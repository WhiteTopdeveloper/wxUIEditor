///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/valgen.h>

#include "optionsdlg.h"

bool OptionsDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* checkBox_borders = new wxCheckBox(this, wxID_ANY, "New sizers have &borders on all sides");
    checkBox_borders->SetValue(true);
    checkBox_borders->SetValidator(wxGenericValidator(&m_sizers_all_borders));
    checkBox_borders->SetToolTip("If checked, all new sizers will be created with wxALL for the border.");
    box_sizer->Add(checkBox_borders, wxSizerFlags().Border(wxALL));

    auto* checkBox_expand = new wxCheckBox(this, wxID_ANY, "New sizers have wx&EXPAND set");
    checkBox_expand->SetValue(true);
    checkBox_expand->SetValidator(wxGenericValidator(&m_sizers_always_expand));
    checkBox_expand->SetToolTip("If checked, new sizers will be created with the wxEXPAND flag.");
    box_sizer->Add(checkBox_expand, wxSizerFlags().Border(wxALL));

    box_sizer->AddSpacer(16);

    auto* checkBox_var_prefix = new wxCheckBox(this, wxID_ANY, "Add \"m_\" prefix to class members");
    checkBox_var_prefix->SetValue(true);
    checkBox_var_prefix->SetValidator(wxGenericValidator(&m_var_prefix));
    checkBox_var_prefix->SetToolTip("If checked, new sizers will be created with the wxEXPAND flag.");
    box_sizer->Add(checkBox_var_prefix, wxSizerFlags().Border(wxALL));

    box_sizer->AddSpacer(16);

    auto* checkBox_wakatime = new wxCheckBox(this, wxID_ANY, "Enable WakaTime");
    checkBox_wakatime->SetValue(true);
    checkBox_wakatime->SetValidator(wxGenericValidator(&m_isWakaTimeEnabled));
    checkBox_wakatime->SetToolTip(
    "If you have WakaTime installed, checking this will record time spent in the editor as \"designing\". (See https://wakatime.com/about)");
    box_sizer->Add(checkBox_wakatime, wxSizerFlags().Border(wxALL));

    parent_sizer->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_BUTTON, &OptionsDlg::OnAffirmative, this, wxID_OK);
    Bind(wxEVT_INIT_DIALOG, &OptionsDlg::OnInit, this);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"    // MainFrame -- Main window frame
#include "preferences.h"  // Preferences -- Stores user preferences

void MainFrame::OnOptionsDlg(wxCommandEvent& WXUNUSED(event))
{
    OptionsDlg dlg(this);
    dlg.ShowModal();
}

void OptionsDlg::OnInit(wxInitDialogEvent& event)
{
    m_sizers_all_borders = Preferences().is_SizersAllBorders();
    m_sizers_always_expand = Preferences().is_SizersExpand();
    m_isWakaTimeEnabled = Preferences().is_WakaTimeEnabled();
    m_var_prefix = Preferences().is_VarPrefix();

    event.Skip();  // transfer all validator data to their windows and update UI
}

void OptionsDlg::OnAffirmative(wxCommandEvent& WXUNUSED(event))
{
    TransferDataFromWindow();

    bool option_changed = false;

    auto lambda = [&](bool new_value, bool& old_value)
    {
        if (new_value != old_value)
        {
            old_value = new_value;
            option_changed = true;
        }
    };

    lambda(m_var_prefix, Preferences().RefVarPrefix());
    lambda(m_sizers_all_borders, Preferences().RefSizersAllBorders());
    lambda(m_sizers_always_expand, Preferences().RefSizersExpand());
    lambda(m_isWakaTimeEnabled, Preferences().RefWakaTimeEnabled());

    if (option_changed)
    {
        Preferences().WriteConfig();
    }

    EndModal(wxID_OK);
}
