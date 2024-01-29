/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate Python code files
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022-2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <set>
#include <thread>
#include <unordered_set>

#include "mainframe.h"

#include "base_generator.h"   // BaseGenerator -- Base widget generator class
#include "code.h"             // Code -- Helper class for generating code
#include "dlg_msgs.h"         // wxMessageDialog dialogs
#include "file_codewriter.h"  // FileCodeWriter -- Classs to write code to disk
#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "gen_common.h"       // Common component functions
#include "gen_results.h"      // Code generation file writing functions
#include "gen_timer.h"        // TimerGenerator class
#include "image_gen.h"        // Functions for generating embedded images
#include "image_handler.h"    // ImageHandler class
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class
#include "utils.h"            // Miscellaneous utilities
#include "write_code.h"       // Write code to Scintilla or file

#include "pugixml.hpp"

using namespace code;
using namespace GenEnum;

// clang-format off

inline constexpr const auto txt_PyPerlRubyCmtBlock =
R"===(###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

)===";

// clang-format on

const char* python_triple_quote = "\"\"\"";

extern const char* python_perl_ruby_end_cmt_line;  // "# ************* End of generated code"

// defined in gen_xrc.cpp
int GenXrcObject(Node* node, pugi::xml_node& object, size_t xrc_flags);

#if defined(_DEBUG) || defined(INTERNAL_TESTING)

void MainFrame::OnGeneratePython(wxCommandEvent& WXUNUSED(event))
{
    GenResults results;
    GeneratePythonFiles(results);

    tt_string msg;
    if (results.updated_files.size())
    {
        if (results.updated_files.size() == 1)
            msg << "1 file was updated";
        else
            msg << " files were updated";
        msg << '\n';
    }
    else
    {
        msg << "All " << results.file_count << " generated files are current";
    }

    if (results.msgs.size())
    {
        for (auto& iter: results.msgs)
        {
            msg << '\n';
            msg << iter;
        }
    }

    wxMessageBox(msg, "Python Code Generation", wxOK | wxICON_INFORMATION);
}

#endif

static void GatherImportModules(std::set<std::string>& imports, Node* node)
{
    if (auto* gen = node->getGenerator(); gen)
    {
        gen->GetPythonImports(node, imports);
    }
    for (auto& child: node->getChildNodePtrs())
    {
        GatherImportModules(imports, child.get());
    }
}

bool GeneratePythonFiles(GenResults& results, std::vector<tt_string>* pClassList)
{
    if (Project.getChildCount() == 0)
    {
        results.msgs.emplace_back("You cannot generate any code until you have added a top level form.") << '\n';
        wxMessageBox("You cannot generate any code until you have added a top level form.", "Code Generation");
        return false;
    }
    tt_cwd cwd(true);
    Project.ChangeDir();

    bool generate_result = true;
    std::vector<Node*> forms;
    Project.CollectForms(forms);

#if defined(_DEBUG) || defined(INTERNAL_TESTING)
    results.StartClock();
#endif

    for (const auto& form: forms)
    {
        auto [path, has_base_file] = Project.GetOutputPath(form, GEN_LANG_PYTHON);
        if (!has_base_file)
        {
#if !defined(_DEBUG)
            // For a lot of wxPython testing of projects with multiple dialogs, there may
            // only be a few forms where wxPython generation is being tested, so don't nag in
            // Debug builds. :-)
            results.msgs.emplace_back() << "No Python filename specified for " << form->as_string(prop_class_name) << '\n';
#endif  // _DEBUG
            continue;
        }

        try
        {
            BaseCodeGenerator codegen(GEN_LANG_PYTHON, form);

            auto h_cw = std::make_unique<FileCodeWriter>(path);
            codegen.SetHdrWriteCode(h_cw.get());

            path.replace_extension(".py");
            auto cpp_cw = std::make_unique<FileCodeWriter>(path);
            codegen.SetSrcWriteCode(cpp_cw.get());

            codegen.GeneratePythonClass();
            int flags = flag_no_ui;
            if (pClassList)
                flags |= flag_test_only;
            auto retval = cpp_cw->WriteFile(GEN_LANG_PYTHON, flags);

            if (auto warning_msgs = codegen.getWarnings(); warning_msgs.size())
            {
                for (auto& iter: warning_msgs)
                {
                    results.msgs.emplace_back() << iter << '\n';
                }
            }

            if (retval > 0)
            {
                if (!pClassList)
                {
                    results.updated_files.emplace_back(path);
                }
                else
                {
                    if (form->isGen(gen_Images))
                        pClassList->emplace_back(GenEnum::map_GenNames[gen_Images]);
                    if (form->isGen(gen_Data))
                        pClassList->emplace_back(GenEnum::map_GenNames[gen_Data]);
                    else
                        pClassList->emplace_back(form->as_string(prop_class_name));
                    continue;
                }
            }

            else if (retval < 0)
            {
                results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
            }
            else  // retval == result::exists
            {
                ++results.file_count;
            }
        }
        catch (const std::exception& err)
        {
            MSG_ERROR(err.what());
            dlgGenInternalError(err, path, form->as_std(prop_class_name));
            continue;
        }
    }

    if (results.msgs.size())
    {
        results.msgs.emplace_back() << '\n';
    }

#if defined(_DEBUG) || defined(INTERNAL_TESTING)
    results.EndClock();
#endif

    return generate_result;
}

// Equivalent to GenerateBaseClass in gen_base.cpp

void BaseCodeGenerator::GeneratePythonClass(PANEL_PAGE panel_type)
{
    Code code(m_form_node, GEN_LANG_PYTHON);

    m_embedded_images.clear();
    SetImagesForm();
    std::set<std::string> img_include_set;
    m_baseFullPath = MakePythonPath(m_form_node);

    std::thread thrd_get_events(&BaseCodeGenerator::CollectEventHandlers, this, m_form_node, std::ref(m_events));
    std::thread thrd_collect_img_headers(&BaseCodeGenerator::CollectImageHeaders, this, m_form_node,
                                         std::ref(img_include_set));

    // If the code files are being written to disk, then UpdateEmbedNodes() has already been called.
    if (panel_type != NOT_PANEL)
    {
        ProjectImages.UpdateEmbedNodes();
    }

    std::vector<Node*> forms;
    Project.CollectForms(forms);

    m_panel_type = panel_type;

    m_header->Clear();
    m_source->Clear();
    m_source->SetLastLineBlank();

    if (m_panel_type == NOT_PANEL)
    {
        m_source->writeLine(txt_PyPerlRubyCmtBlock);
        // Python style guidelines want a module document string
        m_source->writeLine("\"\"\"" + m_form_node->as_string(prop_class_name) + " class generated by wxUiEditor.\"\"\"");
        m_source->writeLine();
    }

    if (Project.hasValue(prop_python_project_preamble))
    {
        WritePropSourceCode(Project.getProjectNode(), prop_python_project_preamble);
    }

    if (!m_form_node->isGen(gen_Images))
        m_source->writeLine("import wx\n");

    if (m_form_node->isGen(gen_Images))
    {
        thrd_get_events.join();
        thrd_collect_img_headers.join();
        GeneratePythonImagesForm();
        return;
    }

    m_header->writeLine(tt_string("# Sample inherited class from ") << m_form_node->as_string(prop_class_name));
    m_header->writeLine();
    m_header->writeLine("import wx");

    std::set<std::string> imports;
    GatherImportModules(imports, m_form_node);

    for (const auto& import: imports)
    {
        m_source->writeLine(import);
        m_header->writeLine(import);
    }

    if (m_form_node->hasValue(prop_python_import_list))
    {
        tt_string_vector list;
        list.SetString(m_form_node->as_string(prop_python_import_list));
        for (auto& iter: list)
        {
            if (!iter.starts_with("import "))
            {
                iter.remove_extension();
                m_source->writeLine(tt_string("import ") << iter);
            }
            else
            {
                m_source->writeLine(iter);
            }
        }
        if (list.size())
        {
            m_source->writeLine();
        }
    }

    m_set_enum_ids.clear();
    m_set_const_ids.clear();
    BaseCodeGenerator::CollectIDs(m_form_node, m_set_enum_ids, m_set_const_ids);
    // set to highest wx
    auto id_value = 1;
    for (auto& iter: m_set_enum_ids)
    {
        if (!iter.starts_with("self."))
        {
            m_source->writeLine(tt_string() << iter << " = wx.ID_HIGHEST + " << id_value++);
        }
    }
    for (auto& iter: m_set_const_ids)
    {
        if (!iter.starts_with("self."))
        {
            if (tt::contains(iter, " wx"))
            {
                tt_string id = iter;
                id.Replace(" wx", " wx.", true, tt::CASE::exact);
                m_source->writeLine(id);
            }
            else
            {
                m_source->writeLine(iter);
            }
        }
    }

    thrd_collect_img_headers.join();
    if (m_embedded_images.size())
    {
        m_source->writeLine();

        // First see if we need to import the gen_Images List
        bool images_file_imported = false;
        bool svg_import_libs = false;
        for (auto& iter: m_embedded_images)
        {
            if (iter->form == m_ImagesForm)
            {
                if (!images_file_imported)
                {
                    tt_string import_name = iter->form->as_string(prop_python_file).filename();
                    import_name.remove_extension();
                    code.Str("import ").Str(import_name);
                    m_source->writeLine(code);
                    code.clear();
                    images_file_imported = true;
                }
                if (iter->type == wxBITMAP_TYPE_SVG)
                {
                    m_source->writeLine("import zlib");
                    m_source->writeLine("import base64");
                    svg_import_libs = true;
                }
            }
            else if (!svg_import_libs)
            {
                if (iter->type == wxBITMAP_TYPE_SVG)
                {
                    m_source->writeLine("import zlib");
                    m_source->writeLine("import base64");
                    svg_import_libs = true;
                }
            }
        }

        // Now write any embedded images that aren't declared in the gen_Images List
        for (auto& iter: m_embedded_images)
        {
            // Only write the images that aren't declared in any gen_Images List. Note that
            // this *WILL* result in duplicate images being written to different forms.
            if (iter->form != m_ImagesForm)
            {
                m_source->writeLine("from wx.lib.embeddedimage import PyEmbeddedImage");
                WriteImageConstruction(code);
                break;
            }
        }
    }

    m_source->writeLine();
    m_header->writeLine();
    m_header->writeLine(tt_string("import ") << m_form_node->as_string(prop_python_file) << "\n");
    m_header->writeLine();

    if (m_form_node->hasValue(prop_python_insert))
    {
        tt_string convert(m_form_node->as_string(prop_python_insert));
        convert.Replace("@@", "\n", tt::REPLACE::all);
        tt_string_vector lines(convert, '\n', tt::TRIM::right);
        for (auto& line: lines)
        {
            m_source->doWrite(line);
            m_source->doWrite("\n");
        }
        m_source->doWrite("\n");
    }

    tt_string inherit_name = m_form_node->as_string(prop_python_inherit_name);
    if (inherit_name.empty())
    {
        inherit_name += "inherit_" + m_form_node->as_string(prop_class_name);
    }
    if (inherit_name.size())
    {
        tt_string inherit("class ");
        inherit << inherit_name << "(";
        inherit << m_form_node->as_string(prop_python_file) << "." << m_form_node->as_string(prop_class_name) << "):";

        m_header->writeLine(inherit);
        m_header->Indent();
        m_header->writeLine("def __init__(self, parent):");
        m_header->writeLine("super().__init__(parent)");
        m_header->Unindent();
        m_header->writeLine();
    }

    auto generator = m_form_node->getNodeDeclaration()->getGenerator();
    code.clear();
    if (generator->ConstructionCode(code))
    {
        m_source->writeLine(code);
        m_source->writeLine();
        m_source->Indent();
        m_source->Indent();

        id_value = 1;
        for (auto& iter: m_set_enum_ids)
        {
            if (iter.starts_with("self."))
            {
                m_source->writeLine(tt_string() << iter << " = wx.ID_HIGHEST + " << id_value++);
            }
        }
        if (id_value > 1)
        {
            // If at least one id was set, add a blank line
            m_source->writeLine();
        }
    }

    code.clear();
    if (generator->SettingsCode(code))
    {
        if (code.size())
        {
            m_source->writeLine(code);
            m_source->writeLine();
        }
    }

    if (m_form_node->getPropPtr(prop_window_extra_style))
    {
        code.clear();
        code.GenWindowSettings();
        if (code.size())
        {
            m_source->writeLine(code);
        }
    }

    m_source->SetLastLineBlank();
    for (const auto& child: m_form_node->getChildNodePtrs())
    {
        if (child->isGen(gen_wxContextMenuEvent))
            continue;
        GenConstruction(child.get());
    }

    code.clear();
    if (generator->AfterChildrenCode(code))
    {
        if (code.size())
        {
            m_source->writeLine();
            m_source->writeLine(code);
        }
    }

    // TODO: [Randalphwa - 12-04-2022] Python supports persistence, though it's not as easy as it is in C++.
    // See https://docs.wxpython.org/wx.lib.agw.persist.html?highlight=persist#module-wx.lib.agw.persist

    // Timer code must be created before the events, otherwise the timer variable won't exist
    // when the event is created.

    code.clear();
    if (TimerGenerator::StartIfChildTimer(m_form_node, code))
    {
        m_source->writeLine(code);
        m_source->writeLine();
    }

    // Delay calling join() for as long as possible to increase the chance that the thread will
    // have already completed.
    thrd_get_events.join();
    if (m_events.size())
    {
        m_source->writeLine();
        m_source->writeLine("# Bind Event handlers");
        GenSrcEventBinding(m_form_node, m_events);
        m_source->ResetIndent();
        m_source->writeLine();
        m_source->Indent();
        GenPythonEventHandlers(m_events);
    }

    if (m_form_node->isGen(gen_wxWizard))
    {
        code.clear();
        code.Eol().Str("# Add the following below the comment block to add a simple");
        code.Eol().Str("# Run() function to launch the wizard").Eol().Str(python_triple_quote);
        code.Eol().Str("def Run(self):");
        code.Tab().Str("return self.RunWizard(self.GetPageAreaSizer().GetItem(0).GetWindow())");
        code.Eol().Str(python_triple_quote).Eol().Eol();
        m_source->writeLine(code);
    }

    // Make certain indentation is reset after all construction code is written
    m_source->ResetIndent();
    m_header->ResetIndent();

    std::sort(m_embedded_images.begin(), m_embedded_images.end(),
              [](const EmbeddedImage* a, const EmbeddedImage* b)
              {
                  return (a->array_name.compare(b->array_name) < 0);
              });
}

bool PythonBitmapList(Code& code, GenEnum::PropName prop)
{
    auto& description = code.node()->as_string(prop);
    ASSERT_MSG(description.size(), "PythonBitmapList called with empty description");
    tt_view_vector parts(description, BMP_PROP_SEPARATOR, tt::TRIM::both);

    if (parts[IndexImage].empty() || parts[IndexType].contains("Art") || parts[IndexType].contains("SVG"))
    {
        return false;
    }

    auto bundle = ProjectImages.GetPropertyImageBundle(description);

    if (!bundle || bundle->lst_filenames.size() < 3)
    {
        return false;
    }

    bool is_xpm = (parts[IndexType].is_sameas("XPM"));
    auto path = MakePythonPath(code.node());

    code += "bitmaps = [ ";
    bool needs_comma = false;
    for (auto& iter: bundle->lst_filenames)
    {
        if (needs_comma)
        {
            code.UpdateBreakAt();
            code.Comma(false).Eol().Tab(3);
        }

        bool is_embed_success = false;
        if (parts[IndexType].starts_with("Embed"))
        {
            if (auto embed = ProjectImages.GetEmbeddedImage(iter); embed)
            {
                AddPythonImageName(code, embed);
                code += ".Bitmap";
                needs_comma = true;
                is_embed_success = true;
            }
        }

        if (!is_embed_success)
        {
            tt_string name(iter);
            name.make_absolute();
            name.make_relative(path);
            name.backslashestoforward();

            code.Str("wx.Bitmap(").QuotedString(name);
            if (is_xpm)
                code.Comma().Str("wx.BITMAP_TYPE_XPM");
            code += ")";
            needs_comma = true;
        }
    }
    code += " ]\n";
    code.UpdateBreakAt();

    return true;
}

bool PythonBundleCode(Code& code, GenEnum::PropName prop)
{
    auto& description = code.node()->as_string(prop);
    if (description.empty())
    {
        code.Add("wxNullBitmap");
        return false;
    }

    tt_view_vector parts(description, BMP_PROP_SEPARATOR, tt::TRIM::both);

    if (parts.size() <= 1 || parts[IndexImage].empty())
    {
        code.Add("wxNullBitmap");
        return false;
    }

    if (parts[IndexType].contains("Art"))
    {
        tt_string art_id(parts[IndexArtID]);
        tt_string art_client;
        if (auto pos = art_id.find('|'); tt::is_found(pos))
        {
            art_client = art_id.subview(pos + 1);
            art_id.erase(pos);
        }

        code.Add("wxArtProvider.GetBitmapBundle(").Add(art_id);

        // Note that current documentation states that the client is required, but the header file says otherwise
        if (art_client.size())
            code.Comma().Add(art_client);
        code << ')';
        return true;
    }

    auto path = MakePythonPath(code.node());

    if (auto bundle = ProjectImages.GetPropertyImageBundle(description); bundle && bundle->lst_filenames.size())
    {
        tt_string name(bundle->lst_filenames[0]);
        name.make_absolute();
        if (!name.file_exists())
        {
            name = Project.ArtDirectory();
            name.append_filename(bundle->lst_filenames[0]);
        }
        name.make_relative(path);
        name.backslashestoforward();

        if (description.starts_with("SVG"))
        {
            auto embed = ProjectImages.GetEmbeddedImage(parts[IndexImage]);
            ASSERT(embed);
            tt_string svg_name;
            if (embed->form != code.node()->getForm())
            {
                svg_name = embed->form->as_string(prop_python_file).filename();
                svg_name.remove_extension();
                svg_name << '.' << embed->array_name;
            }
            else
            {
                svg_name = embed->array_name;
            }
            code.insert(0, tt_string("_svg_string_ = zlib.decompress(base64.b64decode(") << svg_name << "))\n");
            code += "wx.BitmapBundle.FromSVG(_svg_string_";
            wxSize svg_size { -1, -1 };
            if (parts[IndexSize].size())
            {
                svg_size = GetSizeInfo(parts[IndexSize]);
            }
            code.Comma().Add("wxSize(").itoa(svg_size.x).Comma().itoa(svg_size.y) += "))";
        }

        else if (description.starts_with("XPM"))
        {
            code.CheckLineLength(name.size() + sizeof("wx.Bitmap()") + sizeof("wx.BITMAP_TYPE_XPM)"));
            code.Str("wx.Bitmap(").QuotedString(name).Comma().Str("wx.BITMAP_TYPE_XPM)");
        }

        else if (bundle->lst_filenames.size() == 1)
        {
            code += "wx.BitmapBundle.FromBitmap(";
            bool is_embed_success = false;

            if (parts[IndexType].starts_with("Embed"))
            {
                if (auto embed = ProjectImages.GetEmbeddedImage(bundle->lst_filenames[0]); embed)
                {
                    code.CheckLineLength(embed->array_name.size() + sizeof(".Bitmap)"));
                    AddPythonImageName(code, embed);
                    code += ".Bitmap)";
                    is_embed_success = true;
                }
            }

            if (!is_embed_success)
            {
                code.CheckLineLength(name.size() + sizeof("wx.Bitmap()"));
                code.Str("wx.Bitmap(").QuotedString(name) += "))";
            }
        }
        else if (bundle->lst_filenames.size() == 2)
        {
            code += "wx.BitmapBundle.FromBitmaps(";
            bool is_embed_success = false;

            if (parts[IndexType].starts_with("Embed"))
            {
                if (auto embed = ProjectImages.GetEmbeddedImage(bundle->lst_filenames[0]); embed)
                {
                    code.CheckLineLength(embed->array_name.size() + sizeof(".Bitmap"));
                    AddPythonImageName(code, embed);

                    code += ".Bitmap";

                    if (auto embed2 = ProjectImages.GetEmbeddedImage(bundle->lst_filenames[1]); embed2)
                    {
                        code.Comma().CheckLineLength(embed2->array_name.size() + sizeof(".Bitmap)"));
                        AddPythonImageName(code, embed2);
                        code += ".Bitmap)";
                    }
                    else
                    {
                        code.Comma().Str("wx.NullBitmap)");
                    }
                    is_embed_success = true;
                }
            }
            if (!is_embed_success)
            {
                tt_string name2(bundle->lst_filenames[1]);
                name2.make_absolute();
                name2.make_relative(path);
                name2.backslashestoforward();

                code.CheckLineLength(name.size() + name2.size() + 27);
                code.Str("wx.Bitmap(").QuotedString(name).Str(", wx.Bitmap(").QuotedString(name2).Str("))");
            }
        }
        else
        {
            code += "wx.BitmapBundle.FromBitmaps([";
            for (size_t idx = 0; idx < bundle->lst_filenames.size(); ++idx)
            {
                if (parts[IndexType].starts_with("Embed"))
                {
                    if (auto embed = ProjectImages.GetEmbeddedImage(bundle->lst_filenames[idx]); embed)
                    {
                        code.CheckLineLength(embed->array_name.size() + sizeof(".Bitmap"));
                        AddPythonImageName(code, embed);

                        code += ".Bitmap";
                        if (idx < bundle->lst_filenames.size() - 1)
                        {
                            code.Comma();
                        }
                    }
                }
            }
            code += "])";
        }
    }
    else
    {
        FAIL_MSG("Missing bundle description");
        code.Add("wxNullBitmap");
        return false;
    }

    return true;
}

struct BTN_BMP_TYPES
{
    GenEnum::PropName prop_name;
    const char* function_name;
};

inline const BTN_BMP_TYPES btn_bmp_types[] = {
    { prop_bitmap, "SetBitmap" },
    { prop_disabled_bmp, "SetBitmapDisabled" },
    { prop_pressed_bmp, "SetBitmapPressed" },
    { prop_focus_bmp, "SetBitmapFocus" },
    { prop_current, "SetBitmapCurrent" },
};

void PythonBtnBimapCode(Code& code, bool is_single)
{
    for (auto& iter: btn_bmp_types)
    {
        code.Eol(eol_if_needed);
        if (code.hasValue(iter.prop_name))
        {
            code.Eol(eol_if_needed);
            if (PythonBitmapList(code, iter.prop_name))
            {
                code.Eol(eol_if_needed).NodeName().Function(iter.function_name) << '(';
                code += "wx.BitmapBundle.FromBitmaps(bitmaps)";
            }
            else
            {
                code.Eol(eol_if_needed).NodeName().Function(iter.function_name) << '(';
                code.Bundle(iter.prop_name);
            }
            code.EndFunction();
        }
        if (is_single)
        {
            // Means the caller only wants prop_bitmap
            break;
        }
    }
}

tt_string MakePythonPath(Node* node)
{
    auto [path, has_base_file] = Project.GetOutputPath(node->getForm(), GEN_LANG_PYTHON);

    if (path.empty())
        path = "./";
    else if (has_base_file)
        path.remove_filename();
    return path;
}
