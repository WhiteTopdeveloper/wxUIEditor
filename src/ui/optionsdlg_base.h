////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>

class OptionsDlgBase : public wxDialog
{
public:
    OptionsDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& title = wxString::FromUTF8("Options"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE);

protected:

    // Validator variables

    bool m_class_access { false };
    bool m_sizers_all_borders { false };
    bool m_sizers_always_expand { false };
    wxString m_hdr_extension;
    wxString m_member_prefix;
    wxString m_src_extension;

    // Virtual event handlers -- override them in your derived class

    virtual void OnAffirmative(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
};
