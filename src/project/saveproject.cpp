//////////////////////////////////////////////////////////////////////////
// Purpose:   Save a wxUiEditor project file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include "mainapp.h"    // App -- Main application class
#include "node.h"       // Node class
#include "prop_decl.h"  // PropChildDeclaration and PropDeclaration classes

#include "../pugixml/pugixml.hpp"

using namespace GenEnum;

void Node::CreateDoc(pugi::xml_document& doc)
{
    auto root = doc.append_child("wxUiEditorData");
    root.append_attribute("data_version") = (curWxuiMajorVer * 10) + curWxuiMinorVer;

    auto node = root.append_child("node");

    AddNodeToDoc(node);
}

void Node::AddNodeToDoc(pugi::xml_node& node)
{
    node.append_attribute("class") = DeclName().c_str();

    for (auto& iter: m_properties)
    {
        auto& value = iter.as_string();
        if (value.size())
        {
            auto info = iter.GetPropDeclaration();

            // If the value hasn't changed from the default, don't save it
            if (info->GetDefaultValue() == value)
                continue;

            auto attr = node.append_attribute(iter.DeclName());
            if (iter.type() == type_bool)
                attr.set_value(iter.as_bool());
            else
                attr.set_value(value.c_str());
        }
        else
        {
            // Some properties need to be saved with empty values

            if (iter.isProp(prop_label) || iter.isProp(prop_borders))
            {
                node.append_attribute(iter.DeclName());
            }
        }
    }

    for (auto& iter: m_events)
    {
        auto& value = iter.get_value();
        if (value.size())
            node.append_attribute(iter.get_name().c_str()) = value.c_str();
    }

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        auto child = GetChild(i);
        auto child_element = node.append_child("node");
        child->AddNodeToDoc(child_element);
    }
}
