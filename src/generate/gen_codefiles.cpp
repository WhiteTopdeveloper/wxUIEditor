/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate C++ Base code files
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "ttcwd_wx.h"  // cwd -- Class for storing and optionally restoring the current directory

#include "mainframe.h"

#include "gen_base.h"       // BaseCodeGenerator -- Generate Base class
#include "node.h"           // Node class
#include "project_class.h"  // Project class
#include "write_code.h"     // Write code to Scintilla or file

#include "../wxui/dlg_gen_results.h"

bool GenerateCodeFiles(wxWindow* parent, std::vector<ttlib::cstr>* pClassList)
{
    auto project = GetProject();
    if (project->GetChildCount() == 0)
    {
        wxMessageBox("You cannot generate any code until you have added a top level form.", "Code Generation");
        return false;
    }
    ttSaveCwd cwd;
    GetProject()->GetProjectPath().ChangeDir();

    size_t currentFiles = 0;
    std::vector<ttlib::cstr> results;

    if (project->prop_as_bool(prop_generate_cmake) && !pClassList)
    {
        for (auto& iter: project->GetChildNodePtrs())
        {
            if (iter->isGen(gen_folder) && iter->HasValue(prop_folder_cmake_file))
            {
                if (WriteCMakeFile(iter.get(), results) == result::created)
                {
                    ++currentFiles;
                }
            }
        }
        if (project->HasValue(prop_cmake_file))
        {
            if (WriteCMakeFile(project, results) == result::created)
            {
                ++currentFiles;
            }
        }
    }

    ttlib::cstr path;

    ttlib::cstr source_ext(".cpp");
    ttlib::cstr header_ext(".h");

    if (auto& extProp = project->prop_as_string(prop_source_ext); extProp.size())
    {
        source_ext = extProp;
    }

    if (auto& extProp = project->prop_as_string(prop_header_ext); extProp.size())
    {
        header_ext = extProp;
    }

    bool generate_result = true;
    std::vector<Node*> forms;
    project->CollectForms(forms);
    std::vector<ttlib::cstr> updated_files;
    for (const auto& form: forms)
    {
        if (auto& base_file = form->prop_as_string(prop_base_file); base_file.size())
        {
            path = base_file;
            // "filename_base" is the default filename given to all form files. Unless it's changed, no code will be
            // generated.
            if (path == "filename_base")
                continue;
            path.backslashestoforward();
            if (auto* node_folder = form->get_folder(); node_folder && node_folder->HasValue(prop_folder_base_directory))
            {
                path = node_folder->as_string(prop_folder_base_directory);
                path.append_filename(base_file.filename());
            }
            else if (GetProject()->HasValue(prop_base_directory) && !path.contains("/"))
            {
                path = GetProject()->GetBaseDirectory().utf8_string();
                path.append_filename(base_file);
            }
            path.make_absolute();
            path.backslashestoforward();
        }
        else
        {
            results.emplace_back() << "No filename specified for " << form->prop_as_string(prop_class_name) << '\n';
            continue;
        }

        try
        {
            BaseCodeGenerator codegen(GEN_LANG_CPLUSPLUS);

            path.replace_extension(header_ext);
            auto h_cw = std::make_unique<FileCodeWriter>(path.wx_str());
            codegen.SetHdrWriteCode(h_cw.get());

            path.replace_extension(source_ext);
            auto cpp_cw = std::make_unique<FileCodeWriter>(path.wx_str());
            codegen.SetSrcWriteCode(cpp_cw.get());

            codegen.GenerateBaseClass(form);

            path.replace_extension(header_ext);
            auto retval = h_cw->WriteFile();

            if (retval > 0)
            {
                if (!pClassList)
                {
                    updated_files.emplace_back(path);
                }
                else
                {
                    if (form->isGen(gen_Images))
                    {
                        // While technically this is a "form" it doesn't have the usual properties set

                        pClassList->emplace_back(GenEnum::map_GenNames[gen_Images]);
                    }
                    else
                    {
                        pClassList->emplace_back(form->prop_as_string(prop_class_name));
                    }
                    continue;
                }
            }
            else if (retval < 0)
            {
                results.emplace_back() << "Cannot create or write to the file " << path << '\n';
                generate_result = false;
            }
            else  // retval == result::exists)
            {
                ++currentFiles;
            }

            path.replace_extension(source_ext);
            retval = cpp_cw->WriteFile();

            if (retval > 0)
            {
                if (!pClassList)
                {
                    updated_files.emplace_back(path);
                }
                else
                {
                    pClassList->emplace_back(form->prop_as_string(prop_class_name));
                    continue;
                }
            }

            else if (retval < 0)
            {
                results.emplace_back() << "Cannot create or write to the file " << path << '\n';
            }
            else  // retval == result::exists
            {
                ++currentFiles;
            }
        }
        catch (const std::exception& TESTING_PARAM(e))
        {
            MSG_ERROR(e.what());
            wxMessageBox(ttlib::cstr("An internal error occurred generating code files for ")
                             << form->prop_as_string(prop_base_file),
                         "Code generation");
            continue;
        }
    }

    if (updated_files.size() || results.size())
    {
        GeneratedResultsDlg dlg;
        dlg.Create(wxGetFrame().GetWindow());
        for (auto& iter: updated_files)
        {
            iter.make_relative(GetProject()->getProjectPath());
            dlg.m_lb_files->Append(iter);
        }

        if (updated_files.size() == 1)
            results.emplace_back("1 file was updated");
        else
            results.emplace_back() << updated_files.size() << " files were updated";

        for (auto& iter: results)
        {
            dlg.m_lb_info->Append(iter);
        }

        dlg.ShowModal();
    }
    else if (currentFiles && parent)
    {
        ttlib::cstr msg;
        msg << '\n' << "All " << currentFiles << " generated files are current";
        wxMessageBox(msg, "Code Generation", wxOK, parent);
    }
    return generate_result;
}

void MainFrame::GenInhertedClass()
{
    auto project = GetProject();
    ttlib::cwd cwd;
    ttlib::ChangeDir(GetProject()->getProjectPath());
    ttlib::cstr path;
    std::vector<ttlib::cstr> results;

    ttlib::cstr source_ext(".cpp");
    ttlib::cstr header_ext(".h");

    if (auto& extProp = project->prop_as_string(prop_source_ext); extProp.size())
    {
        source_ext = extProp;
    }

    if (auto extProp = project->prop_as_string(prop_header_ext); extProp.size())
    {
        header_ext = extProp;
    }

    size_t currentFiles = 0;
    std::vector<Node*> forms;
    project->CollectForms(forms);

    for (const auto& form: forms)
    {
        if (auto& file = form->prop_as_string(prop_derived_file); file.size())
        {
            path = file;
            if (path.empty())
                continue;
            path.backslashestoforward();
            if (GetProject()->HasValue(prop_derived_directory) && !path.contains("/"))
            {
                path = GetProject()->as_string(prop_derived_directory);
                path.append_filename(file);
            }
            path.make_absolute();
            path.backslashestoforward();
            path.replace_extension(source_ext);
            if (path.file_exists())
            {
                // Count both source and header file
                path.replace_extension(header_ext);
                if (path.file_exists())
                {
                    currentFiles += 2;
                    continue;
                }
                else
                {
                    ++currentFiles;
                }
            }
            path.remove_extension();
        }
        else
        {
            continue;
        }

        BaseCodeGenerator codegen(GEN_LANG_CPLUSPLUS);

        path.replace_extension(header_ext);
        auto h_cw = std::make_unique<FileCodeWriter>(path.wx_str());
        codegen.SetHdrWriteCode(h_cw.get());

        path.replace_extension(source_ext);
        auto cpp_cw = std::make_unique<FileCodeWriter>(path.wx_str());
        codegen.SetSrcWriteCode(cpp_cw.get());

        auto retval = codegen.GenerateDerivedClass(project, form);
        if (retval == result::fail)
        {
            results.emplace_back() << "Cannot create or write to the file " << path << '\n';
            continue;
        }
        else if (retval == result::exists)
        {
            path.replace_extension(header_ext);
            if (path.file_exists())
            {
                ++currentFiles;
                continue;
            }

            // If we get here, the source file exists, but the header file does not.
            retval = h_cw->WriteFile();
            if (retval == result::fail)
            {
                results.emplace_back() << "Cannot create or write to the file " << path << '\n';
            }
            else if (retval == result::exists)
            {
                ++currentFiles;
            }
            else
            {
                results.emplace_back() << path.filename() << " saved" << '\n';
            }
            continue;
        }
        else if (retval == result::ignored)
        {
            // Completely ignore this file
            continue;
        }

        path.replace_extension(header_ext);
        if (path.file_exists())
            retval = result::exists;
        else
            retval = h_cw->WriteFile();

        if (retval == result::fail)
        {
            results.emplace_back() << "Cannot create or write to the file " << path << '\n';
        }
        else if (retval == result::exists)
        {
            ++currentFiles;
        }
        else
        {
            results.emplace_back() << path.filename() << " saved" << '\n';
        }

        path.replace_extension(source_ext);
        retval = cpp_cw->WriteFile();
        if (retval == result::fail)
        {
            results.emplace_back() << "Cannot create or write to the file " << path << '\n';
        }
        else if (retval == result::exists)
        {
            ++currentFiles;
        }
        else
        {
            results.emplace_back() << path.filename() << " saved" << '\n';
        }
    }

    if (results.size())
    {
        ttlib::cstr msg;
        for (auto& iter: results)
        {
            msg += iter;
        }

        if (currentFiles)
        {
            msg << '\n' << "The other " << currentFiles << " derived files have already been created";
        }

        wxMessageBox(msg.wx_str(), "Code Generation", wxOK);
    }
    else if (currentFiles)
    {
        ttlib::cstr msg;
        msg << '\n' << "All " << currentFiles << " derived files have already been created";
        wxMessageBox(msg, "Code Generation", wxOK);
    }
    else
    {
        wxMessageBox("There were no derived filenames specified -- nothing to generate.\n\nAdd a filename to the "
                     "derived_filename property to generate a derived file.",
                     "Code Generation", wxOK);
    }
}

#if defined(INTERNAL_TESTING)

    #include "pugixml.hpp"

void GenerateTmpFiles(const std::vector<ttlib::cstr>& ClassList, pugi::xml_node root)
{
    auto project = GetProject();

    ttSaveCwd cwd;
    ttlib::ChangeDir(GetProject()->getProjectPath());
    ttlib::cstr path;
    std::vector<ttlib::cstr> results;

    ttlib::cstr source_ext(".cpp");
    ttlib::cstr header_ext(".h");

    if (auto& extProp = project->prop_as_string(prop_source_ext); extProp.size())
    {
        source_ext = extProp;
    }

    if (auto& extProp = project->prop_as_string(prop_header_ext); extProp.size())
    {
        header_ext = extProp;
    }

    std::vector<Node*> forms;
    project->CollectForms(forms);

    for (auto& iter_class: ClassList)
    {
        for (const auto& form: forms)
        {
            // The Images class doesn't have a prop_class_name, so use "Images". Note that this will fail if there is a real
            // form where the user set the class name to "Images". If this wasn't an Internal function, then we would need to
            // store nodes rather than class names.

            ttlib::cstr class_name(form->prop_as_string(prop_class_name));
            if (form->isGen(gen_Images))
                class_name = "Images";

            if (class_name.is_sameas(iter_class))
            {
                BaseCodeGenerator codegen(GEN_LANG_CPLUSPLUS);

                // At this point we know which form has changes, but we don't know if it's the src file, the header file, or
                // both, so we need to check again.
                ttlib::cstr base_file(form->prop_as_string(prop_base_file));
                base_file.replace_extension(header_ext);
                base_file.make_absolute();

                base_file.replace_extension(header_ext);
                auto h_cw = std::make_unique<FileCodeWriter>(base_file.wx_str());
                codegen.SetHdrWriteCode(h_cw.get());

                base_file.replace_extension(source_ext);
                auto cpp_cw = std::make_unique<FileCodeWriter>(base_file.wx_str());
                codegen.SetSrcWriteCode(cpp_cw.get());

                codegen.GenerateBaseClass(form);

                base_file.replace_extension(header_ext);
                bool new_hdr = (h_cw->WriteFile(true) > 0);

                base_file.replace_extension(source_ext);
                bool new_src = (cpp_cw->WriteFile(true) > 0);

                if (new_hdr)
                {
                    path = base_file;
                    if (auto pos_file = path.find_filename(); ttlib::is_found(pos_file))
                    {
                        path.insert(pos_file, "~wxue_");
                    }

                    path.replace_extension(header_ext);
                    h_cw = std::make_unique<FileCodeWriter>(path.wx_str());
                    codegen.SetHdrWriteCode(h_cw.get());

                    path.replace_extension(source_ext);
                    cpp_cw = std::make_unique<FileCodeWriter>(path.wx_str());
                    codegen.SetSrcWriteCode(cpp_cw.get());

                    codegen.GenerateBaseClass(form);

                    path.replace_extension(header_ext);
                    h_cw->WriteFile();

                    auto paths = root.append_child("paths");
                    base_file.replace_extension(header_ext);
                    paths.append_child("left").text().set(base_file.c_str());
                    paths.append_child("left-readonly").text().set("0");

                    paths.append_child("right").text().set(path.c_str());
                    paths.append_child("right-readonly").text().set("1");
                }

                if (new_src)
                {
                    path = base_file;
                    if (auto pos_file = path.find_filename(); ttlib::is_found(pos_file))
                    {
                        path.insert(pos_file, "~wxue_");
                    }

                    path.replace_extension(header_ext);
                    h_cw = std::make_unique<FileCodeWriter>(path.wx_str());
                    codegen.SetHdrWriteCode(h_cw.get());

                    path.replace_extension(source_ext);
                    cpp_cw = std::make_unique<FileCodeWriter>(path.wx_str());
                    codegen.SetSrcWriteCode(cpp_cw.get());

                    codegen.GenerateBaseClass(form);

                    path.replace_extension(source_ext);
                    cpp_cw->WriteFile();

                    auto paths = root.append_child("paths");
                    base_file.replace_extension(source_ext);
                    paths.append_child("left").text().set(base_file.c_str());
                    paths.append_child("left-readonly").text().set("0");
                    paths.append_child("right").text().set(path.c_str());
                    paths.append_child("right-readonly").text().set("1");
                }
            }
        }
    }
}

#endif  // defined(INTERNAL_TESTING)
