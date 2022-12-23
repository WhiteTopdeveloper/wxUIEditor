///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/checkbox.h>
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/statbox.h>
#include <wx/valgen.h>

#include "debugsettings.h"

bool DebugSettings::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto* static_box = new wxStaticBoxSizer(wxVERTICAL, this, "MSG Window Settings");

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* checkBox = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Display MSG Window");
    checkBox->SetValidator(wxGenericValidator(&m_DisplayMsgWindow));
    checkBox->SetToolTip(
    "If checked, the MSG window will be displayed the first time it receives a non-filtered MSG. If unchecked, the window is never displayed unless you go here and click the Show Now button.");
    box_sizer->Add(checkBox, wxSizerFlags().Center().Border(wxALL));

    box_sizer->AddSpacer(15);

    m_btn = new wxButton(static_box->GetStaticBox(), wxID_ANY, "Show Now");
    box_sizer->Add(m_btn, wxSizerFlags().Border(wxALL));

    static_box->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer2 = new wxBoxSizer(wxVERTICAL);

    auto* checkBox2 = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Display MSG_INFO() messages");
    checkBox2->SetValidator(wxGenericValidator(&m_DisplayMsgInfo));
    box_sizer2->Add(checkBox2, wxSizerFlags().Border(wxALL));

    auto* checkBox3 = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Display MSG_EVENT() messages");
    checkBox3->SetValidator(wxGenericValidator(&m_DisplayMsgEvent));
    box_sizer2->Add(checkBox3, wxSizerFlags().Border(wxALL));

    auto* checkBox4 = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Display MSG_WARNING() messages");
    checkBox4->SetValidator(wxGenericValidator(&m_DisplayMsgWarnng));
    box_sizer2->Add(checkBox4, wxSizerFlags().Border(wxALL));

    static_box->Add(box_sizer2, wxSizerFlags().Expand().Border(wxALL));

    static_box->AddSpacer(10);

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    auto* checkBox_2 = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Display creation info");
    checkBox_2->SetValidator(wxGenericValidator(&m_FireCreationMsgs));
    checkBox_2->SetToolTip("MSG_INFO called when nav, prop, and mockup panels have their contents recreated.");
    box_sizer_2->Add(checkBox_2, wxSizerFlags().Border(wxALL));

    static_box->Add(box_sizer_2, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer->Add(static_box, wxSizerFlags().Expand().Border(wxALL));

    std_button_sizer = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(std_button_sizer, wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    wxPersistentRegisterAndRestore(this, "DebugSettings");

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &DebugSettings::OnInit, this);
    m_btn->Bind(wxEVT_BUTTON, &DebugSettings::OnShowNow, this);
    Bind(wxEVT_BUTTON, &DebugSettings::OnOK, this, wxID_OK);

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
// Purpose:   Settings while running the Debug version of wxUiEditor
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/config.h>  // wxConfig base header

#include "mainapp.h"  // App -- App class

void DebugSettings::OnInit(wxInitDialogEvent& event)
{
    m_orgFlags = wxGetApp().Preferences().GetDebugFlags();
    m_DisplayMsgWindow = (m_orgFlags & PREFS::PREFS_MSG_WINDOW);
    m_DisplayMsgInfo = (m_orgFlags & PREFS::PREFS_MSG_INFO);
    m_DisplayMsgEvent = (m_orgFlags & PREFS::PREFS_MSG_EVENT);
    m_DisplayMsgWarnng = (m_orgFlags & PREFS::PREFS_MSG_WARNING);
    m_FireCreationMsgs = (m_orgFlags & PREFS::PREFS_CREATION_MSG);

    event.Skip();  // transfer all validator data to their windows and update UI
}

void DebugSettings::OnShowNow(wxCommandEvent& WXUNUSED(event))
{
    g_pMsgLogging->ShowLogger();
}

void DebugSettings::OnOK(wxCommandEvent& event)
{
    if (!Validate() || !TransferDataFromWindow())
        return;

    if (m_DisplayMsgWindow)
        m_orgFlags |= PREFS::PREFS_MSG_WINDOW;
    else
        m_orgFlags &= ~PREFS::PREFS_MSG_WINDOW;

    if (m_DisplayMsgInfo)
        m_orgFlags |= PREFS::PREFS_MSG_INFO;
    else
        m_orgFlags &= ~PREFS::PREFS_MSG_INFO;

    if (m_DisplayMsgEvent)
        m_orgFlags |= PREFS::PREFS_MSG_EVENT;
    else
        m_orgFlags &= ~PREFS::PREFS_MSG_EVENT;

    if (m_DisplayMsgWarnng)
        m_orgFlags |= PREFS::PREFS_MSG_WARNING;
    else
        m_orgFlags &= ~PREFS::PREFS_MSG_WARNING;

    if (m_FireCreationMsgs)
        m_orgFlags |= PREFS::PREFS_CREATION_MSG;
    else
        m_orgFlags &= ~PREFS::PREFS_CREATION_MSG;

    if (m_orgFlags != wxGetApp().Preferences().GetDebugFlags())
    {
        wxGetApp().Preferences().SetDebugFlags(m_orgFlags);
        wxGetApp().Preferences().WriteConfig();
    }

    event.Skip();  // Need to call this for Persist to work
}
