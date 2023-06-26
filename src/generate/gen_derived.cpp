/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate the derived class source and header file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

/*

    There are several situations we need to deal with here:

    This could be a non-derived class (prop_use_derived_class is false) in which case the header file is empty, and we don't
   use the derived class name or derived filename even if specified.

    This could be a derived class, but either the class name or the filename is empty. In that case, we can't write to disk,
   but we can mockup a temporary class name if needed as well as a temporary filename.

    If we are trying to write to disk, we have to return result::exists if a non-derived class, result::ignored if filename
   or classname is empty.

*/

#include <thread>

#include "gen_base.h"

#include "../customprops/eventhandler_dlg.h"  // EventHandlerDlg static functions
#include "node.h"                             // Node class
#include "node_creator.h"                     // NodeCreator class
#include "project_handler.h"                  // ProjectHandler class

#include "write_code.h"  // Write code to Scintilla or file

// clang-format off

inline constexpr const auto txt_DerivedCmtBlock =
R"===(////////////////////////////////////////////////////////////////////////////
// Original Code generated by wxUiEditor
//
// The code is generated only once. You can now modify the code as needed.
////////////////////////////////////////////////////////////////////////////

)===";

static constexpr const char* lst_close_type_button[] = {

    // Buttons that would normally be used to close the dialog need to call event.Skip() to get validator data and to close
    // the dialog.
    "OKButtonClicked",
    "YesButtonClicked",
    "SaveButtonClicked",

};

// clang-format on

int BaseCodeGenerator::GenerateDerivedClass(Node* project, Node* form, PANEL_PAGE panel_type)
{
    m_form_node = form;
    m_is_derived_class = m_form_node->prop_as_bool(prop_use_derived_class);

    tt_string source_ext(".cpp");
    tt_string header_ext(".h");

    if (auto& extProp = project->prop_as_string(prop_source_ext); extProp.size())
    {
        source_ext = extProp;
    }

    if (auto& extProp = project->prop_as_string(prop_header_ext); extProp.size())
    {
        header_ext = extProp;
    }

    tt_string derived_file;
    if (m_is_derived_class && m_form_node->HasValue(prop_derived_file))
    {
        derived_file = m_form_node->prop_as_string(prop_derived_file);
        derived_file.backslashestoforward();
        if (auto* node_folder = form->get_folder(); node_folder && node_folder->HasValue(prop_folder_derived_directory))
        {
            derived_file = node_folder->as_string(prop_folder_derived_directory);
            derived_file.append_filename(m_form_node->prop_as_string(prop_derived_file).filename());
        }
        else if (Project.HasValue(prop_derived_directory) && !derived_file.contains("/"))
        {
            derived_file = Project.as_string(prop_derived_directory);
            derived_file.append_filename(m_form_node->prop_as_string(prop_derived_file));
        }
        derived_file.make_absolute();
        derived_file.backslashestoforward();
    }
    else
    {
        // If we're writing to disk, return as if the file already exists
        if (panel_type == NOT_PANEL)
            return result::exists;
    }

    if (m_is_derived_class && panel_type == NOT_PANEL)
    {
        if (derived_file.empty())
            return result::exists;

        derived_file.replace_extension(source_ext);

        if (derived_file.file_exists())
            return result::exists;  // We never allow writing over an existing derived class file

        derived_file.remove_extension();
    }

    // Caution! Don't return until thrd_get_events.join(); is called.

    EventVector events;
    std::thread thrd_get_events(&BaseCodeGenerator::CollectEventHandlers, this, m_form_node, std::ref(events));

    tt_string baseFile;
    if (auto& file = m_form_node->prop_as_string(prop_base_file); file.size())
    {
        baseFile = file;
        baseFile.backslashestoforward();
        if (auto* node_folder = form->get_folder(); node_folder && node_folder->HasValue(prop_folder_base_directory))
        {
            baseFile = node_folder->value(prop_folder_base_directory);
            baseFile.append_filename(file.filename());
        }
        else if (Project.HasValue(prop_base_directory) && !baseFile.contains("/"))
        {
            baseFile = Project.BaseDirectory();
            baseFile.append_filename(file);
        }

        baseFile.replace_extension(header_ext);
        tt_string root(derived_file);
        root.remove_filename();
        if (root.size())
            baseFile.make_relative(root);
        baseFile.backslashestoforward();
        baseFile.remove_extension();
    }

    tt_string namespace_using_name;

    // Make a copy of the string so that we can tweak it
    tt_string namespace_prop = Project.value(prop_name_space);
    if (auto* node_namespace = form->get_folder(); node_namespace && node_namespace->HasValue(prop_folder_namespace))
    {
        namespace_prop = node_namespace->as_string(prop_folder_namespace);
    }
    if (namespace_prop.size())
    {
        // BUGBUG: [KeyWorks - 01-25-2021] Need to look for base_class_name property of all children, and add each name
        // as a forwarded class.

        // tt_string_vector works with a single char, not a string.
        namespace_prop.Replace("::", ":");
        // we also accept using semi-colons to separate the namespaces
        namespace_prop.Replace(";", ":");

        tt_string_vector names(namespace_prop, ':');
        for (auto& iter: names)
        {
            if (namespace_using_name.size())
            {
                namespace_using_name += "::";
            }
            namespace_using_name += iter;
        }
    }

    tt_string derived_name = m_form_node->prop_as_string(prop_derived_class_name);
    if (!m_is_derived_class)
    {
        // If this is not a derived class, then use the base class name
        derived_name = m_form_node->prop_as_string(prop_class_name);
    }
    else if (derived_name.empty())
    {
        tt_string base_name(m_form_node->prop_as_string(prop_class_name));
        base_name.Replace("My", "");
        base_name.Replace("Base", "");
        derived_name << "MyDerived" << base_name;
    }

    m_header->Clear();
    m_source->Clear();

    if (m_is_derived_class)
        m_source->writeLine(txt_DerivedCmtBlock);

    if (panel_type != CPP_PANEL)
    {
        if (!m_is_derived_class)
        {
            m_header->writeLine(
                "\n// No header needed when not creating a derived class\n// (use_derived_class property is unchecked)");
            thrd_get_events.join();
            return result::created;
        }
        m_header->writeLine(txt_DerivedCmtBlock);

        m_header->writeLine("\n#pragma once");
        m_header->writeLine();

        if (baseFile.empty())
        {
            m_header->writeLine("// Specify the filename to use in the base_file property");
            m_header->writeLine("#include \"Your filename here\"");
        }
        else
        {
            baseFile.replace_extension(header_ext);
            m_header->writeLine(tt_string().Format("#include %ks", baseFile.c_str()));
            baseFile.remove_extension();
        }
        m_header->writeLine();

        tt_string line;
        line << "class " << derived_name << " : public ";
        if (namespace_using_name.size())
        {
            line << namespace_using_name << "::";
        }

        line << m_form_node->get_node_name();

        m_header->writeLine(line);
        m_header->writeLine("{");

        m_header->writeLine("public:");
        m_header->Indent();

        m_header->writeLine(tt_string() << derived_name
                                        << "();  // If you use this constructor, you must call Create(parent)");
        m_header->writeLine(tt_string() << derived_name << "(wxWindow* parent);");

        m_header->Unindent();
    }

    if (panel_type != HDR_PANEL)
    {
        if (auto prop = project->prop_as_string(prop_local_pch_file); prop.size())
        {
            tt_string pch("#include ");
            pch << "\"" << prop << "\"";

            m_source->writeLine();
            m_source->writeLine(pch);
            m_source->writeLine();
        }

        if (project->HasValue(prop_src_preamble))
        {
            tt_string convert(project->prop_as_string(prop_src_preamble));
            convert.Replace("@@", "\n", tt::REPLACE::all);
            tt_string_vector lines(convert, '\n');
            bool initial_bracket = false;
            for (auto& code: lines)
            {
                if (code.contains("}"))
                {
                    m_source->Unindent();
                }
                else if (!initial_bracket && code.contains("["))
                {
                    initial_bracket = true;
                    m_source->Indent();
                }

                m_source->writeLine(code, indent::auto_no_whitespace);

                if (code.contains("{"))
                {
                    m_source->Indent();
                }
            }
            m_source->Unindent();
            m_source->writeLine();
        }

        if (m_is_derived_class)
        {
            if (derived_file.empty())
            {
                m_source->writeLine();
                m_source->writeLine("// Specify the filename to use in the derived_file property");
                m_source->writeLine("#include \"Your filename here\"");
            }
            else
            {
                tt_string inc;

                // Add a comment to the header that specifies the generated header and source filenames
                baseFile.replace_extension(header_ext);
                derived_file.replace_extension(header_ext);
                inc.Format("#include %ks", std::string(derived_file.filename()).c_str());

                tt_string comment(tt_string(header_ext) << "\"  // auto-generated: ");
                comment << baseFile << " and ";
                baseFile.replace_extension(source_ext);
                comment << baseFile;
                inc.Replace(tt_string(header_ext) << '"', comment);

                if (header_ext != ".h")
                    inc.Replace(".h", header_ext);
                m_source->writeLine();
                m_source->writeLine(inc);
            }

            m_source->writeLine();
        }
        else
        {
            if (baseFile.empty())
            {
                m_source->writeLine();
                m_source->writeLine("// Specify the filename to use in the base_file property");
                m_source->writeLine("#include \"Your filename here\"");
            }
            else
            {
                baseFile.replace_extension(header_ext);
                tt_string inc;
                inc.Format("#include %ks", baseFile.c_str());
                m_source->writeLine("// Non-generated additions to base class (virtual events is unchecked)");
                m_source->writeLine("// Copy and paste into your own code as needed.");
                m_source->writeLine();
                m_source->writeLine(inc);
                m_source->writeLine();
            }
        }

        if (namespace_using_name.size())
        {
            m_source->writeLine(tt_string() << "using namespace " << namespace_using_name << ';');
            m_source->writeLine();
        }

        if (m_is_derived_class)  // non-derived class doesn't have a constructor
        {
            tt_string code;
            if (m_form_node->isGen(gen_wxDialog))
            {
                code << "// If this constructor is used, the caller must call Create(parent)\n";
                code << derived_name << "::" << derived_name << "() {}\n\n";
                code << derived_name << "::" << derived_name << "(wxWindow* parent) { Create(parent); }";
            }
            else
            {
                code << derived_name << "::" << derived_name << "(wxWindow* parent) : ";
                code << m_form_node->get_node_name() << "(parent) {}";
            }

            m_source->writeLine(code);
        }
    }

    thrd_get_events.join();
    if (events.size() > 0)
    {
        m_header->Unindent();
        m_header->writeLine();
        m_header->writeLine("protected:");
        m_header->Indent();
        m_header->SetLastLineBlank();
        m_header->writeLine(tt_string() << "// Handlers for " << m_form_node->get_node_name() << " events");

        std::set<std::string> generatedHandlers;
        for (auto event: events)
        {
            auto event_code = EventHandlerDlg::GetCppValue(event->get_value());
            // Ignore lambda's and functions in another class
            if (event_code.contains("[") || event_code.contains("::"))
                continue;

            if (generatedHandlers.find(event_code) == generatedHandlers.end())
            {
                bool close_type_button { false };
                for (auto& iter: lst_close_type_button)
                {
                    if (event->GetEventInfo()->get_name().is_sameas(iter))
                    {
                        close_type_button = true;
                        break;
                    }
                }

                tt_string prototype;

                // If this is a button that closes a dialog, and the dialog is marked as persist, then event.Skip() must be
                // called.
                if (event->GetEventInfo()->get_name().is_sameas("wxEVT_INIT_DIALOG") ||
                    (close_type_button && m_form_node->prop_as_bool(prop_persist)))
                {
                    // OnInitDialog needs to call event.Skip() in order to initialize validators and update the UI
                    prototype.Format("%s(%s& event)", event_code.c_str(), event->GetEventInfo()->get_event_class().c_str());
                }
                else
                {
                    prototype.Format("%s(%s& WXUNUSED(event))", event_code.c_str(),
                                     event->GetEventInfo()->get_event_class().c_str());
                }
                m_header->writeLine(tt_string().Format("void %s override;", prototype.c_str()));

                if (panel_type != HDR_PANEL)
                {
                    if (event->GetNode()->IsForm() && event->get_name() == "wxEVT_CONTEXT_MENU")
                    {
                        bool is_handled = false;
                        for (const auto& iter: event->GetNode()->GetChildNodePtrs())
                        {
                            if (iter->isGen(gen_wxContextMenuEvent))
                            {
                                is_handled = true;
                                break;
                            }
                        }

                        // This means the base class handles this event, so don't add it to the derived class
                        if (is_handled)
                            continue;
                    }
                    m_source->writeLine();
                    m_source->writeLine(tt_string() << "void " << derived_name << "::" << prototype);
                    m_source->writeLine("{");
                    m_source->Indent();
                    auto name = event->GetEventInfo()->get_name();
                    if (name == "wxEVT_INIT_DIALOG")
                    {
                        m_source->writeLine("event.Skip();  // transfer all validator data to their windows and update UI");
                    }
                    else if (close_type_button)
                    {
                        m_source->writeLine("if (!Validate() || !TransferDataFromWindow())");
                        m_source->Indent();
                        m_source->writeLine("return;");
                        m_source->Unindent();
                        m_source->writeLine();
                        m_source->writeLine("if (IsModal())");

                        m_source->Indent();
                        m_source->writeLine("EndModal(wxID_OK);");
                        m_source->Unindent();

                        m_source->writeLine("else");
                        m_source->writeLine("{");

                        m_source->Indent();
                        m_source->writeLine("    SetReturnCode(wxID_OK);");
                        m_source->writeLine("    Show(false);");
                        m_source->Unindent();

                        m_source->writeLine("}");

                        if (m_form_node->prop_as_bool(prop_persist))
                        {
                            m_source->writeLine();
                            m_source->writeLine("event.Skip();  // This must be called for wxPersistenceManager to work");
                        }
                    }
                    else
                    {
                        m_source->writeLine(tt_string().Format("    // TODO: Implement %s", event_code.c_str()),
                                            indent::auto_no_whitespace);
                    }
                    m_source->Unindent();

                    m_source->writeLine("}");
                }

                generatedHandlers.insert(event_code);
            }
        }
    }

    m_header->Unindent();
    m_header->writeLine("};");

    return result::created;
}
