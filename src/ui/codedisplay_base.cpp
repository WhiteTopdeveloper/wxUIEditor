////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/sizer.h>

#include "codedisplay_base.h"

CodeDisplayBase::CodeDisplayBase(wxWindow* parent, wxWindowID id) : wxPanel()
{
    Create(parent, id);

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_scintilla = new wxStyledTextCtrl(this, wxID_ANY);
    {
        m_scintilla->SetLexer(wxSTC_LEX_CPP);
        m_scintilla->SetReadOnly(true);
        m_scintilla->SetEOLMode(wxSTC_EOL_LF);
        m_scintilla->SetWrapMode(wxSTC_WRAP_WHITESPACE);
        m_scintilla->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);
        m_scintilla->SetWrapVisualFlagsLocation(wxSTC_WRAPVISUALFLAGLOC_END_BY_TEXT);
        m_scintilla->SetWrapIndentMode(wxSTC_WRAPINDENT_INDENT);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_scintilla->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginWidth(1, 0);  // Remove default margin
        m_scintilla->SetMarginWidth(0, 16);
        m_scintilla->SetMarginType(0, wxSTC_MARGIN_SYMBOL);
        m_scintilla->SetMarginMask(0, ~wxSTC_MASK_FOLDERS);
        m_scintilla->SetMarginSensitive(0, false);
        m_scintilla->SetIndentationGuides(wxSTC_IV_REAL);
        m_scintilla->SetUseTabs(false);
        m_scintilla->SetTabWidth(4);
        m_scintilla->SetBackSpaceUnIndents(true);
    }
    parent_sizer->Add(m_scintilla, wxSizerFlags(1).Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
}
