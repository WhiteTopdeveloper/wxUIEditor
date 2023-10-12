///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

class EditStringDialogBase : public wxDialog
{
public:
    EditStringDialogBase() {}
    EditStringDialogBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr);

    const wxString& GetResults() const { return m_value; }

protected:

    // Validator variables

    wxString m_value;

    // Class member variables

    wxStaticText* m_static_hdr_text;
    wxTextCtrl* m_textCtrl;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
