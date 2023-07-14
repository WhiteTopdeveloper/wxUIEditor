/////////////////////////////////////////////////////////////////////////////
// Purpose:   ProjectHandler class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <filesystem>
#include <fstream>
#include <thread>

#include <wx/animate.h>   // wxAnimation and wxAnimationCtrl
#include <wx/artprov.h>   // wxArtProvider class
#include <wx/filename.h>  // wxFileName - encapsulates a file path
#include <wx/filesys.h>   // class for opening files - virtual file system
#include <wx/mstream.h>   // Memory stream classes
#include <wx/wfstream.h>  // File stream classes

#include "project_handler.h"

#include "bitmaps.h"        // Map of bitmaps accessed by name
#include "image_handler.h"  // ProjectImage class
#include "mainapp.h"        // App -- App class
#include "mainframe.h"      // MainFrame -- Main window frame
#include "node.h"           // Node class
#include "utils.h"          // Utility functions that work with properties

ProjectHandler& Project = ProjectHandler::getInstance();

void ProjectHandler::Initialize(NodeSharedPtr project, bool allow_ui)
{
    m_project_node = project;
    m_allow_ui = allow_ui;

    // Note that the ProjectImage class keeps a shared pointer to the project node, so the
    // reference count won't go to zero until we call this function.

    ProjectImages.Initialize(m_project_node, allow_ui);
}

void ProjectHandler::SetProjectFile(const tt_string& file)
{
    m_projectFile = file;
    m_projectPath = m_projectFile;
    m_projectPath.make_absolute();
    m_projectPath.remove_filename();
}

void ProjectHandler::set_ProjectFile(const tt_string& file)
{
    m_projectFile = file.make_wxString();
    m_projectPath = m_projectFile;
    m_projectPath.make_absolute();
    m_projectPath.remove_filename();
}

void ProjectHandler::CollectForms(std::vector<Node*>& forms, Node* node_start)
{
    if (!node_start)
    {
        node_start = m_project_node.get();
    }

    for (const auto& child: node_start->GetChildNodePtrs())
    {
        if (child->IsForm())
        {
            forms.push_back(child.get());
        }
        else
        {
            if (child->isGen(gen_folder) || child->isGen(gen_sub_folder))
            {
                CollectForms(forms, child.get());
            }
        }
    }
}

void ProjectHandler::FixupDuplicatedNode(Node* new_node)
{
    std::set<std::string_view> base_classnames;
    std::set<std::string_view> derived_classnames;
    std::set<std::string_view> base_filenames;
    std::set<std::string_view> derived_filenames;
    std::set<std::string_view> xrc_filenames;
    std::set<std::string_view> python_filenames;
    std::set<std::string_view> ruby_filenames;

    // Collect all of the class and filenames in use by each form so we can make sure the new
    // form doesn't use any of them.
    std::vector<Node*> forms;
    CollectForms(forms);
    for (auto& iter: forms)
    {
        if (iter->HasValue(prop_class_name))
            base_classnames.insert(iter->value(prop_class_name));
        if (iter->HasValue(prop_derived_class_name))
            derived_classnames.insert(iter->value(prop_derived_class_name));
        if (iter->HasValue(prop_base_file))
            base_filenames.insert(iter->value(prop_base_file));
        if (iter->HasValue(prop_derived_file))
            derived_filenames.insert(iter->value(prop_derived_file));
        if (iter->HasValue(prop_xrc_file))
            xrc_filenames.insert(iter->value(prop_xrc_file));
        if (iter->HasValue(prop_python_file))
            python_filenames.insert(iter->value(prop_python_file));
        if (iter->HasValue(prop_ruby_file))
            ruby_filenames.insert(iter->value(prop_ruby_file));
    }

    auto lambda = [&](std::set<std::string_view>& set_names, PropName prop)
    {
        if (new_node->HasValue(prop))
        {
            if (set_names.contains(new_node->value(prop)))
            {
                tt_string new_name = new_node->value(prop);
                if (!new_name.contains("_copy"))
                    new_name += "_copy";
                if (set_names.contains(new_name))
                {
                    tt_string copy_name = new_name;
                    while (tt::is_digit(copy_name.back()))
                    {
                        // remove any trailing digits
                        copy_name.erase(copy_name.size() - 1, 1);
                    }
                    if (copy_name.back() == '_')
                    {
                        copy_name.erase(copy_name.size() - 1, 1);
                    }

                    for (int i = 2;; ++i)
                    {
                        new_name.clear();
                        new_name << copy_name << '_' << i;
                        if (!set_names.contains(new_name))
                            break;
                    }
                }
                new_node->set_value(prop, new_name);
            }
        }
    };

    lambda(base_classnames, prop_class_name);
    lambda(derived_classnames, prop_derived_class_name);
    lambda(base_filenames, prop_base_file);
    lambda(derived_filenames, prop_derived_file);
    lambda(xrc_filenames, prop_xrc_file);
    lambda(python_filenames, prop_python_file);
    lambda(ruby_filenames, prop_ruby_file);
}

tt_string ProjectHandler::ArtDirectory() const
{
    tt_string result;

    if (m_project_node->HasValue(prop_art_directory))
        result = m_project_node->as_string(prop_art_directory);
    if (result.empty())
        result = m_projectPath;

    result.make_absolute();

    return result;
}

tt_string ProjectHandler::BaseDirectory(Node* node, int language) const
{
    tt_string result;

    Node* folder = node->get_folder();
    if (folder)
    {
        if (language == GEN_LANG_CPLUSPLUS && folder->HasValue(prop_folder_base_directory))
            result = folder->as_string(prop_folder_base_directory);
        else if (language == GEN_LANG_PYTHON && folder->HasValue(prop_folder_python_output_folder))
            result = folder->as_string(prop_folder_python_output_folder);
        else if (language == GEN_LANG_RUBY && folder->HasValue(prop_folder_ruby_output_folder))
            result = folder->as_string(prop_folder_python_output_folder);
        else if (language == GEN_LANG_XRC && folder->HasValue(prop_folder_xrc_directory))
            result = folder->as_string(prop_folder_xrc_directory);
    }

    // Even if the node has a folder parent, there may not be a directory set for it, so check
    // result and if it's empty use the project directory properties.
    if (result.empty() || !folder)
    {
        if (language == GEN_LANG_CPLUSPLUS && m_project_node->HasValue(prop_base_directory))
            result = m_project_node->as_string(prop_base_directory);
        else if (language == GEN_LANG_PYTHON && m_project_node->HasValue(prop_python_output_folder))
            result = m_project_node->as_string(prop_python_output_folder);
        else if (language == GEN_LANG_RUBY && m_project_node->HasValue(prop_ruby_output_folder))
            result = m_project_node->as_string(prop_ruby_output_folder);
        else if (language == GEN_LANG_XRC && m_project_node->HasValue(prop_xrc_directory))
            result = m_project_node->as_string(prop_xrc_directory);
    }

    if (result.empty())
        result = m_projectPath;

    result.make_absolute();

    return result;
}

// Note that this will return a directory for GEN_LANG_PYTHON and GEN_LANG_XRC even though we currently
// don't generate derived files for those languages.
tt_string ProjectHandler::DerivedDirectory(Node* node, int language) const
{
    tt_string result;

    Node* folder = node->get_folder();
    if (folder)
    {
        if (language == GEN_LANG_CPLUSPLUS && folder->HasValue(prop_folder_derived_directory))
            result = folder->as_string(prop_folder_base_directory);
        else if (language == GEN_LANG_PYTHON && folder->HasValue(prop_folder_python_output_folder))
            result = folder->as_string(prop_folder_python_output_folder);
        else if (language == GEN_LANG_RUBY && folder->HasValue(prop_folder_ruby_output_folder))
            result = folder->as_string(prop_folder_python_output_folder);
        else if (language == GEN_LANG_XRC && folder->HasValue(prop_folder_xrc_directory))
            result = folder->as_string(prop_folder_xrc_directory);
    }

    // Even if the node has a folder parent, there may not be a directory set for it, so check
    // result and if it's empty use the project directory properties.
    if (result.empty() || !folder)
    {
        if (language == GEN_LANG_CPLUSPLUS && m_project_node->HasValue(prop_derived_directory))
            result = m_project_node->as_string(prop_base_directory);
        else if (language == GEN_LANG_PYTHON && m_project_node->HasValue(prop_python_output_folder))
            result = m_project_node->as_string(prop_python_output_folder);
        else if (language == GEN_LANG_RUBY && m_project_node->HasValue(prop_ruby_output_folder))
            result = m_project_node->as_string(prop_ruby_output_folder);
        else if (language == GEN_LANG_XRC && m_project_node->HasValue(prop_xrc_directory))
            result = m_project_node->as_string(prop_xrc_directory);
    }

    if (result.empty())
        result = m_projectPath;

    result.make_absolute();

    return result;
}

Node* ProjectHandler::GetFirstFormChild(Node* node) const
{
    if (!node)
        node = m_project_node.get();
    for (const auto& child: node->GetChildNodePtrs())
    {
        if (child->IsForm())
        {
            return child.get();
        }
        else if (child->isGen(gen_folder) || child->isGen(gen_sub_folder))
        {
            return GetFirstFormChild(child.get());
        }
    }

    return nullptr;
}

int ProjectHandler::get_PreferredLanguage()
{
    auto& value = Project.value(prop_code_preference);
    if (value == "C++")
        return GEN_LANG_CPLUSPLUS;
    else if (value == "Python")
        return GEN_LANG_PYTHON;
    else if (value == "Ruby")
        return GEN_LANG_RUBY;
    else if (value == "XRC")
        return GEN_LANG_XRC;
    else
        return GEN_LANG_CPLUSPLUS;
}
