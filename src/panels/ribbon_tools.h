/////////////////////////////////////////////////////////////////////////////
// Purpose:   Displays node creation tools in a wxRibbonBar
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>      // Top-level component of the ribbon-bar-style interface
#include <wx/ribbon/toolbar.h>  // Ribbon-style tool bar

#include "../ui/ribbonpanel_base.h"

#include <wx/aui/auibar.h>
#include <wx/aui/auibook.h>
#include <wx/spinbutt.h>

class RibbonPanel : public RibbonPanelBase
{
public:
    RibbonPanel(wxWindow* parent);

protected:
    void OnToolClick(wxRibbonToolBarEvent& event) override;
    void OnDropDown(wxRibbonToolBarEvent& event) override;
    void OnMenuEvent(wxCommandEvent& event);
};

void CreateRibbon(wxBoxSizer* parent_sizer, wxWindow* parent);
