///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/infobar.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>

class NewDialog : public wxDialog
{
public:
    NewDialog() {}
    NewDialog(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Create New Dialog",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Create New Dialog",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    void createNode();
    void VerifyClassName();

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);

private:

    // Validator variables

    bool m_has_std_btns { true };
    bool m_has_tabs { false };
    int m_num_tabs { 3 };
    wxString m_base_class { "MyDialogBase" };
    wxString m_title;

    // Class member variables

    wxCheckBox* m_check_tabs;
    wxInfoBar* m_infoBar;
    wxSpinCtrl* m_spinCtrlTabs;
    wxTextCtrl* m_classname;
    wxTextCtrl* m_textCtrl_title;

    bool m_is_info_shown { false };
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
