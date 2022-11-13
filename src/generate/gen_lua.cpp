/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate Lua code files
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "ttcwd_wx.h"  // cwd -- Class for storing and optionally restoring the current directory

#include "mainframe.h"

#include "gen_base.h"       // BaseCodeGenerator -- Generate Base class
#include "node.h"           // Node class
#include "project_class.h"  // Project class
#include "write_code.h"     // Write code to Scintilla or file

bool GenerateLuaFiles(wxWindow* parent, bool NeedsGenerateCheck, std::vector<ttlib::cstr>* pClassList)
{
    auto project = GetProject();
    if (project->GetChildCount() == 0)
    {
        if (NeedsGenerateCheck)
            return false;

        wxMessageBox("You cannot generate any code until you have added a top level form.", "Code Generation");
        return false;
    }
    ttSaveCwd cwd;
    GetProject()->GetProjectPath().ChangeDir();
    ttlib::cstr path;
    std::vector<ttlib::cstr> results;

    size_t currentFiles = 0;

    bool generate_result = true;
    for (const auto& form: project->GetChildNodePtrs())
    {
        if (auto& base_file = form->prop_as_string(prop_lua_file); base_file.size())
        {
            path = base_file;
            path.backslashestoforward();
            if (GetProject()->HasValue(prop_lua_directory) && !path.contains("/"))
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
            BaseCodeGenerator codegen(GEN_LANG_LUA);

            auto h_cw = std::make_unique<FileCodeWriter>(path.wx_str());
            codegen.SetHdrWriteCode(h_cw.get());

            path.replace_extension(".lua");
            auto cpp_cw = std::make_unique<FileCodeWriter>(path.wx_str());
            codegen.SetSrcWriteCode(cpp_cw.get());

            codegen.GenerateLuaClass(form.get());

            auto retval = cpp_cw->WriteFile(NeedsGenerateCheck);

            if (retval > 0)
            {
                if (!NeedsGenerateCheck)
                {
                    results.emplace_back() << path.filename() << " saved" << '\n';
                }
                else
                {
                    if (pClassList)
                    {
                        pClassList->emplace_back(form->prop_as_string(prop_class_name));
                        continue;
                    }
                    else
                    {
                        return generate_result;
                    }
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
                             << form->prop_as_string(prop_lua_file),
                         "Code generation");
            continue;
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
            msg << '\n' << "The other " << currentFiles << " generated files are current";
        }

        wxMessageBox(msg.wx_str(), "Code Generation", wxOK, parent);
    }
    else if (currentFiles && parent)
    {
        ttlib::cstr msg;
        msg << '\n' << "All " << currentFiles << " generated files are current";
        wxMessageBox(msg, "Code Generation", wxOK, parent);
    }
    return generate_result;
}

using namespace GenEnum;

// clang-format off

inline constexpr const auto txt_LuaCmtBlock =
R"===(---------------------------------------------------------------------------------
-- Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
--
-- DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
---------------------------------------------------------------------------------

package.cpath = package.cpath..";./?.dll;./?.so;../lib/?.so;../lib/vc_dll/?.dll;../lib/bcc_dll/?.dll;../lib/mingw_dll/?.dll;"
require("wx")

UI = {}

)===";

// clang-format on

void BaseCodeGenerator::GenerateLuaClass(Node* form_node, PANEL_PAGE panel_type)
{
    m_project = GetProject();
    m_form_node = form_node;

    m_panel_type = panel_type;

    m_header->Clear();
    m_source->Clear();

    m_source->writeLine(txt_LuaCmtBlock);
    m_header->writeLine("-- wxLua is available at https://github.com/pkulchenko/wxlua");
    m_header->writeLine("-- Lua information is available at https://www.lua.org/home.html");
    m_header->writeLine("-- LuaJIT information is available at https://luajit.org/");
}
