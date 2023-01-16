///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/persist.h>
#include <wx/persist/toplevel.h>

#include "eventhandlerdlg_base.h"

bool EventHandlerDlgBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_static_bind_text = new wxStaticText(this, wxID_ANY, "...");
    m_static_bind_text->Wrap(400);
    box_sizer->Add(m_static_bind_text, wxSizerFlags().Border(wxALL));

    box_sizer->AddSpacer(10 + wxSizerFlags::GetDefaultBorder());

    m_radio_use_function = new wxRadioButton(this, wxID_ANY, "Use function");
    m_function_box = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, m_radio_use_function), wxVERTICAL);

    m_text_function = new wxTextCtrl(m_function_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_function_box->Add(m_text_function, wxSizerFlags().Expand().Border(wxALL));

    box_sizer->Add(m_function_box, wxSizerFlags().Expand().Border(wxALL));

    box_sizer->AddSpacer(10 + wxSizerFlags::GetDefaultBorder());

    m_radio_use_lambda = new wxRadioButton(this, wxID_ANY, "Use C++ lambda");
    m_lambda_box = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, m_radio_use_lambda), wxVERTICAL);

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);

    m_check_capture_this = new wxCheckBox(m_lambda_box->GetStaticBox(), wxID_ANY, "&Capture this");
    box_sizer_2->Add(m_check_capture_this, wxSizerFlags().Border(wxALL));

    m_check_include_event = new wxCheckBox(m_lambda_box->GetStaticBox(), wxID_ANY, "&Include event parameter");
    box_sizer_2->Add(m_check_include_event, wxSizerFlags().Border(wxALL));

    m_lambda_box->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    auto* staticText = new wxStaticText(m_lambda_box->GetStaticBox(), wxID_ANY, "Lambda body:");
    m_lambda_box->Add(staticText, wxSizerFlags().Border(wxALL));

    m_stc = new wxStyledTextCtrl(m_lambda_box->GetStaticBox());
    {
        m_stc->SetLexer(wxSTC_LEX_CPP);
        m_stc->SetEOLMode(wxSTC_EOL_LF);
        m_stc->SetWrapMode(wxSTC_WRAP_WORD);
        m_stc->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);
        m_stc->SetWrapIndentMode(wxSTC_WRAPINDENT_INDENT);
        m_stc->SetMultipleSelection(wxSTC_MULTIPASTE_EACH);
        m_stc->SetMultiPaste(wxSTC_MULTIPASTE_EACH);
        m_stc->SetAdditionalSelectionTyping(true);
        m_stc->SetAdditionalCaretsBlink(true);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_stc->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_stc->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_stc->SetMarginWidth(1, 0); // Remove default margin
        m_stc->SetMarginWidth(0, 16);
        m_stc->SetMarginType(0, wxSTC_MARGIN_SYMBOL);
        m_stc->SetMarginMask(0, ~wxSTC_MASK_FOLDERS);
        m_stc->SetMarginSensitive(0, false);
        m_stc->SetIndentationGuides(wxSTC_IV_LOOKFORWARD);
        m_stc->SetUseTabs(false);
        m_stc->SetTabWidth(4);
        m_stc->SetBackSpaceUnIndents(true);
    }
    m_lambda_box->Add(m_stc, wxSizerFlags(1).Expand().DoubleBorder(wxALL));

    box_sizer->Add(m_lambda_box, wxSizerFlags(1).Expand().Border(wxALL));

    parent_sizer->Add(box_sizer, wxSizerFlags(1).Expand().Border(wxALL));

    parent_sizer->AddSpacer(10 + wxSizerFlags::GetDefaultBorder());

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    wxPersistentRegisterAndRestore(this, "EventHandlerDlgBase");

    // Event handlers
    Bind(wxEVT_BUTTON, &EventHandlerDlgBase::OnOK, this, wxID_OK);
    m_check_capture_this->Bind(wxEVT_CHECKBOX, &EventHandlerDlgBase::OnCapture, this);
    m_check_include_event->Bind(wxEVT_CHECKBOX, &EventHandlerDlgBase::OnIncludeEvent, this);
    Bind(wxEVT_INIT_DIALOG, &EventHandlerDlgBase::OnInit, this);
    m_radio_use_function->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUseFunction, this);
    m_radio_use_lambda->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUseLambda, this);
    m_stc->Bind(wxEVT_STC_CHANGE, &EventHandlerDlgBase::OnChange, this);
    m_text_function->Bind(wxEVT_TEXT, &EventHandlerDlgBase::OnFunctionText, this);

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
