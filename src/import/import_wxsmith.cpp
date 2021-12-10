/////////////////////////////////////////////////////////////////////////////
// Purpose:   Import a wxSmith or XRC file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "import_wxsmith.h"

#include "base_generator.h"  // BaseGenerator -- Base Generator class
#include "mainapp.h"         // App -- Main application class
#include "node.h"            // Node class
#include "node_creator.h"    // NodeCreator class
#include "pjtsettings.h"     // ProjectSettings -- Hold data for currently loaded project
#include "utils.h"           // Utility functions that work with properties

WxSmith::WxSmith() {}

bool WxSmith::Import(const ttString& filename, bool write_doc)
{
    auto result = LoadDocFile(filename);
    if (!result)
    {
        return false;
    }
    auto root = result.value().first_child();

    if (!ttlib::is_sameas(root.name(), "wxsmith", tt::CASE::either) &&
        !ttlib::is_sameas(root.name(), "resource", tt::CASE::either))
    {
        wxMessageBox(wxString() << filename << " is not a wxSmith or XRC file", "Import");
        return false;
    }

    // Using a try block means that if at any point it becomes obvious the project file is invalid and we cannot recover,
    // then we can throw an error and give a standard response about an invalid file.

    try
    {
        m_project = g_NodeCreator.CreateNode(gen_Project, nullptr);
        for (auto& iter: root.children())
        {
            CreateXrcNode(iter, m_project.get());
        }

        if (!m_project->GetChildCount())
        {
            wxMessageBox(wxString() << filename << " does not contain any top level forms.", "Import");
            return false;
        }

        if (write_doc)
            m_project->CreateDoc(m_docOut);
    }

    catch (const std::exception& DBG_PARAM(e))
    {
        MSG_ERROR(e.what());
        wxMessageBox(wxString("This project file is invalid and cannot be loaded: ") << filename, "Import Project");
        return false;
    }

    if (m_errors.size())
    {
        ttlib::cstr errMsg("Not everything in the wxSmith project could be converted:\n\n");
        MSG_ERROR(ttlib::cstr() << "------  " << m_importProjectFile.filename().wx_str() << "------");
        for (auto& iter: m_errors)
        {
            MSG_ERROR(iter);
            errMsg << iter << '\n';
        }

        wxMessageBox(errMsg, "Import wxSmith project");
    }

    return true;
}

NodeSharedPtr WxSmith::CreateXrcNode(pugi::xml_node& xml_obj, Node* parent, Node* sizeritem)
{
    auto object_name = xml_obj.attribute("class").as_cstr();
    if (object_name.empty())
        return NodeSharedPtr();

    bool isBitmapButton = (object_name == "wxBitmapButton");
    auto gen_name = ConvertToGenName(object_name, parent);
    if (gen_name == gen_unknown)
    {
        MSG_INFO(ttlib::cstr() << "Unrecognized object: " << object_name);
        return NodeSharedPtr();
    }

    if (gen_name == gen_wxCheckBox)
    {
        for (auto& iter: xml_obj.children())
        {
            if (iter.cname().is_sameas("style"))
            {
                if (iter.text().as_cview().contains("wxCHK_3STATE"))
                    gen_name = gen_Check3State;
                break;
            }
        }
    }

    auto new_node = g_NodeCreator.CreateNode(gen_name, parent);
    while (!new_node)
    {
        if (sizeritem && sizeritem->isGen(gen_oldbookpage))
        {
            if (auto page = g_NodeCreator.CreateNode(gen_PageCtrl, parent); page)
            {
                if (sizeritem->HasValue(prop_label))
                {
                    page->prop_set_value(prop_label, sizeritem->prop_as_string(prop_label));
                }
                parent->Adopt(page);
                return CreateXrcNode(xml_obj, page.get(), sizeritem);
            }
        }
        else if (parent && parent->isGen(gen_wxPanel))
        {
            auto sizer = g_NodeCreator.CreateNode(gen_VerticalBoxSizer, parent);
            if (sizer)
            {
                new_node = g_NodeCreator.CreateNode(gen_name, sizer.get());
                if (new_node)
                {
                    parent->Adopt(sizer);
                    parent = sizer.get();
                    continue;
                }
            }
        }

        ttlib::cstr msg("Unable to create ");
        msg << object_name;
        if (parent)
        {
            // We can't use the class name because that won't necessarily be the wxWidgets class name. E.g., PanelForm might
            // be the class name, but what we want to display to the user is wxPanel. GetHelpText() will give us something
            // that makes sense to the user.

            auto name = parent->GetGenerator()->GetHelpText(parent);
            if (name.size() && name != "wxWidgets")
            {
#if defined(_DEBUG)
                // Currently, Debug builds also include the filename that gets passed to the browser if Help is requested.
                // That's not useful in a message box, so we remove it.

                name.erase_from('(');
#endif  // _DEBUG
                msg << " as a child of " << name;
            }
        }
        m_errors.emplace(msg);
        return {};
    }

    if (isBitmapButton)
    {
        new_node->prop_set_value(prop_label, "");
        isBitmapButton = false;
    }

    if (parent)
    {
        if (auto prop = new_node->get_prop_ptr(prop_var_name); prop)
        {
            auto original = prop->as_string();
            auto new_name = parent->GetUniqueName(prop->as_string());
            if (new_name.size() && new_name != prop->as_string())
                prop->set_value(new_name);
        }
    }

    if (new_node->isGen(gen_wxStdDialogButtonSizer))
    {
        if (parent)
        {
            parent->Adopt(new_node);
        }
        ProcessAttributes(xml_obj, new_node.get());
        ProcessProperties(xml_obj, new_node.get());

        for (auto& button: xml_obj.children())
        {
            for (auto& btn_id: button.children())
            {
                auto id = btn_id.attribute("name").as_cview();
                if (id.is_sameas("wxID_OK"))
                    new_node->get_prop_ptr(prop_OK)->set_value("1");
                else if (id.is_sameas("wxID_YES"))
                    new_node->get_prop_ptr(prop_Yes)->set_value("1");
                else if (id.is_sameas("wxID_SAVE"))
                    new_node->get_prop_ptr(prop_Save)->set_value("1");
                else if (id.is_sameas("wxID_APPLY"))
                    new_node->get_prop_ptr(prop_Apply)->set_value("1");
                else if (id.is_sameas("wxID_NO"))
                    new_node->get_prop_ptr(prop_No)->set_value("1");
                else if (id.is_sameas("wxID_CANCEL"))
                    new_node->get_prop_ptr(prop_Cancel)->set_value("1");
                else if (id.is_sameas("wxID_CLOSE"))
                    new_node->get_prop_ptr(prop_Close)->set_value("1");
                else if (id.is_sameas("wxID_HELP"))
                    new_node->get_prop_ptr(prop_Help)->set_value("1");
                else if (id.is_sameas("wxID_CONTEXT_HELP"))
                    new_node->get_prop_ptr(prop_ContextHelp)->set_value("1");
            }
        }

        new_node->get_prop_ptr(prop_alignment)->set_value("wxALIGN_RIGHT");
        return new_node;
    }

    auto child = xml_obj.child("object");
    if (g_NodeCreator.IsOldHostType(new_node->DeclName()))
    {
        ProcessAttributes(xml_obj, new_node.get());
        ProcessProperties(xml_obj, new_node.get(), parent);
        new_node = CreateXrcNode(child, parent, new_node.get());
        // ASSERT(new_node);
        if (!new_node)
            return NodeSharedPtr();
        if (new_node->isGen(gen_wxStdDialogButtonSizer))
            new_node->get_prop_ptr(prop_static_line)->set_value(false);
        child = child.next_sibling("object");
    }
    else if (sizeritem)
    {
        for (auto& iter: sizeritem->get_props_vector())
        {
            auto prop = new_node->AddNodeProperty(iter.GetPropDeclaration());
            prop->set_value(iter.as_string());
        }
        if (parent)
        {
            parent->Adopt(new_node);
        }
        ProcessAttributes(xml_obj, new_node.get());
        ProcessProperties(xml_obj, new_node.get());
    }
    else if (parent)
    {
        parent->Adopt(new_node);

        ProcessAttributes(xml_obj, new_node.get());
        ProcessProperties(xml_obj, new_node.get());
    }

    // At this point, all properties have been processed.

    if (new_node->isGen(gen_wxGridSizer) || new_node->isGen(gen_wxFlexGridSizer))
    {
        if (new_node->prop_as_int(prop_rows) > 0 && new_node->prop_as_int(prop_cols) > 0)
            new_node->prop_set_value(prop_rows, 0);
    }

    // Various designers allow the users to create settings that will generate an assert if compiled on a debug version of
    // wxWidgets. We fix some of the more common invalid settings here.

    if (new_node->HasValue(prop_flags) && new_node->prop_as_string(prop_flags).contains("wxEXPAND"))
    {
        if (new_node->HasValue(prop_alignment))
        {
            // wxWidgets will ignore all alignment flags if wxEXPAND is set.
            new_node->prop_set_value(prop_alignment, "");
        }
    }

    if (parent && parent->IsSizer())
    {
        if (parent->prop_as_string(prop_orientation).contains("wxHORIZONTAL"))
        {
            auto currentValue = new_node->prop_as_string(prop_alignment);
            if (currentValue.size() && (currentValue.contains("wxALIGN_LEFT") || currentValue.contains("wxALIGN_RIGHT") ||
                                        currentValue.contains("wxALIGN_CENTER_HORIZONTAL")))
            {
                auto fixed = ClearMultiplePropFlags("wxALIGN_LEFT|wxALIGN_RIGHT|wxALIGN_CENTER_HORIZONTAL", currentValue);
                new_node->prop_set_value(prop_alignment, fixed);
            }
        }
        else if (parent->prop_as_string(prop_orientation).contains("wxVERTICAL"))
        {
            auto currentValue = new_node->prop_as_string(prop_alignment);
            if (currentValue.size() && (currentValue.contains("wxALIGN_TOP") || currentValue.contains("wxALIGN_BOTTOM") ||
                                        currentValue.contains("wxALIGN_CENTER_VERTICAL")))
            {
                auto fixed = ClearMultiplePropFlags("wxALIGN_TOP|wxALIGN_BOTTOM|wxALIGN_CENTER_VERTICAL", currentValue);
                new_node->prop_set_value(prop_alignment, fixed);
            }
        }
    }

    while (child)
    {
        CreateXrcNode(child, new_node.get());
        child = child.next_sibling("object");
    }

    return new_node;
}
