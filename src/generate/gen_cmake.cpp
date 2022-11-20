//////////////////////////////////////////////////////////////////////////
// Purpose:   Auto-generate a .cmake file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <fstream>

#include <ttcwd_wx.h>       // cwd -- Class for storing and optionally restoring the current directory
#include <tttextfile_wx.h>  // textfile -- Classes for reading and writing line-oriented files

#include "gen_base.h"       // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "node.h"           // Node class
#include "project_class.h"  // Project class

int WriteCMakeFile(Node* parent_node, std::vector<ttlib::cstr>& results)
{
    auto project = GetProject();

    if (!project->prop_as_bool(prop_generate_cmake) ||
        (parent_node->isGen(gen_Project) && !project->HasValue(prop_cmake_file)))
    {
        return result::exists;
    }
    if (parent_node->isGen(gen_folder) && !parent_node->HasValue(prop_folder_cmake_file))
    {
        return result::exists;
    }

    ttSaveCwd cwd;

    // The generated files make be in a different directory then the project file, and if so, we
    // need to tread that directory as the root of the file.

    ttlib::cstr cmake_file = project->as_string(prop_cmake_file);
    if (parent_node->isGen(gen_folder) && parent_node->HasValue(prop_folder_cmake_file))
    {
        cmake_file = parent_node->as_string(prop_folder_cmake_file);
    }
    if (cmake_file.starts_with(".."))
    {
        ttlib::cstr new_dir(cmake_file);
        new_dir.remove_filename();
        ttlib::ChangeDir(new_dir);
    }
    else
    {
        ttlib::ChangeDir(GetProject()->getProjectPath());
    }

    ttlib::cwd cur_dir;
    cur_dir.make_absolute();

    cmake_file.make_relative(cur_dir.utf8_string());

    ttlib::viewfile current;

    // The return value is ignored because if the file doesn't exist then it will be created,
    // returning result::fail if it cannot be written.
    current.ReadFile(cmake_file);

    ttlib::textfile out;
    out.emplace_back("# Generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/");
    out.emplace_back("#");
    out.emplace_back("# DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!");
    out.emplace_back();

    out.emplace_back();
    out.at(out.size() - 1) << "set (" << project->prop_as_string(prop_cmake_varname);
    out.emplace_back();

    std::set<ttlib::cstr> base_files;
    std::vector<Node*> forms;
    project->CollectForms(forms, parent_node);

    for (const auto& iter: forms)
    {
        if (!iter->HasValue(prop_base_file))
            continue;

        if (parent_node == project)
        {
            if (auto* node_folder = project->get_folder(); node_folder && node_folder->HasValue(prop_folder_cmake_file))
            {
                // This file already got added to a different .cmake file
                continue;
            }
        }

        base_files.emplace(iter->prop_as_string(prop_base_file));
    }

    for (auto base_file: base_files)
    {
        base_file.make_relative(cur_dir.utf8_string());
        base_file.backslashestoforward();
        base_file.remove_extension();

        ttlib::cstr source_ext(".cpp");
        if (auto& extProp = project->prop_as_string(prop_source_ext); extProp.size())
        {
            source_ext = extProp;
        }
        base_file.replace_extension(source_ext);

        out.emplace_back();
        out.at(out.size() - 1) << "    ${CMAKE_CURRENT_LIST_DIR}/" << base_file;
    }

    out.emplace_back();
    out.emplace_back(")");

    if (out.is_sameas(current))
    {
        return result::exists;
    }

    if (!out.WriteFile(cmake_file))
    {
        results.emplace_back() << "Cannot create or write to the file " << cmake_file << '\n';
        return result::fail;
    }
    return result::created;
}
