///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/radiobut.h>

class NodeSearchDlg : public wxDialog
{
public:
    NodeSearchDlg() {}
    NodeSearchDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Node Search",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Node Search",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    bool isSearchGenerators() const { return m_search_generators; }
    const wxString& get_GenName() const { return m_gen_name; }
    bool isSearchVarnames() const { return m_search_varnames; }
    const wxString& get_VarName() const { return m_var_name; }
    bool isSearchLabels() const { return m_search_labels; }
    const wxString& get_Label() const { return m_label_name; }

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);
    void OnRadioSearchGenerators(wxCommandEvent& event);
    void OnRadioSearchLabels(wxCommandEvent& event);
    void OnRadioSearchVarNames(wxCommandEvent& event);

private:

    // Validator variables

    bool m_search_generators { true };
    bool m_search_labels { false };
    bool m_search_varnames { false };
    wxString m_gen_name;
    wxString m_label_name;
    wxString m_var_name;

    // Class member variables

    wxComboBox* m_combo_generators;
    wxComboBox* m_combo_labels;
    wxComboBox* m_combo_variables;
    wxRadioButton* m_radio_generators;
    wxRadioButton* m_radio_labels;
    wxRadioButton* m_radio_var_names;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
