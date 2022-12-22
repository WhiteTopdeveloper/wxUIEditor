//////////////////////////////////////////////////////////////////////////
// Purpose:   wxSimplebook generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/simplebook.h>  // wxBookCtrlBase-derived class without any controller.

#include "gen_book_utils.h"  // Common Book utilities
#include "gen_common.h"      // GeneratorLibrary -- Generator classes
#include "gen_xrc_utils.h"   // Common XRC generating functions
#include "node.h"            // Node class
#include "pugixml.hpp"       // xml read/write/create/process
#include "utils.h"           // Utility functions that work with properties

#include "gen_simplebook.h"

wxObject* SimplebookGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxSimplebook(wxStaticCast(parent, wxWindow), wxID_ANY, DlgPoint(parent, node, prop_pos),
                                   DlgSize(parent, node, prop_size), GetStyleInt(node));

    widget->SetEffects((wxShowEffect) node->prop_as_mockup(prop_show_effect, "info_"),
                       (wxShowEffect) node->prop_as_mockup(prop_hide_effect, "info_"));
    if (node->HasValue(prop_duration))
    {
        widget->SetEffectTimeout(node->prop_as_int(prop_duration));
    }

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);
    widget->Bind(wxEVT_BOOKCTRL_PAGE_CHANGED, &SimplebookGenerator::OnPageChanged, this);

    return widget;
}

void SimplebookGenerator::OnPageChanged(wxBookCtrlEvent& event)
{
    auto book = wxDynamicCast(event.GetEventObject(), wxSimplebook);
    if (book && event.GetSelection() != wxNOT_FOUND)
        GetMockup()->SelectNode(book->GetPage(event.GetSelection()));
    event.Skip();
}

std::optional<ttlib::sview> SimplebookGenerator::CommonConstruction(Code& code)
{
    if (code.is_cpp() && code.is_local_var())
        code << "auto* ";
    code.NodeName().CreateClass();
    code.GetParentName().Comma().as_string(prop_id).PosSizeFlags(false);

    return code.m_code;
}

std::optional<ttlib::sview> SimplebookGenerator::CommonSettings(Code& code)
{
    if (!code.IsEqualTo(prop_show_effect, "no effects") || !code.IsEqualTo(prop_hide_effect, "no effects"))
    {
        Node* node = code.node();
        code.NodeName().Function("SetEffects(").Str(node->as_constant(prop_show_effect, "info_"));
        code.Comma().Str(node->as_constant(prop_hide_effect, "info_")).EndFunction();

        if (code.IntValue(prop_duration) != 0)
        {
            code.NodeName().Function("SetEffectTimeout(").Str(prop_duration).EndFunction();
        }
    }
    return code.m_code;
}

bool SimplebookGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/Simplebk.h>", set_src, set_hdr);

    return true;
}

// ../../wxSnapShot/src/xrc/xh_simplebook.cpp
// ../../../wxWidgets/src/xrc/xh_simplebook.cpp

int SimplebookGenerator::GenXrcObject(Node* node, pugi::xml_node& object, size_t xrc_flags)
{
    auto result = node->GetParent()->IsSizer() ? BaseGenerator::xrc_sizer_item_created : BaseGenerator::xrc_updated;
    auto item = InitializeXrcObject(node, object);

    GenXrcObjectAttributes(node, item, "wxSimplebook");

    GenXrcStylePosSize(node, item);
    GenXrcWindowSettings(node, item);

    if (xrc_flags & xrc::add_comments)
    {
        if (!node->isPropValue(prop_show_effect, "no effects") || !node->isPropValue(prop_show_effect, "no effects"))
            item.append_child(pugi::node_comment).set_value("SetEffects() are not supported in XRC");
        GenXrcComments(node, item);
    }

    return result;
}

void SimplebookGenerator::RequiredHandlers(Node* /* node */, std::set<std::string>& handlers)
{
    handlers.emplace("wxSimplebookXmlHandler");
}
