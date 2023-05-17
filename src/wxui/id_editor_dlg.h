///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

class Node;

class IDEditorDlg : public wxDialog
{
public:
    IDEditorDlg() {}
    IDEditorDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "ID Editor", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "ID Editor", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    wxString GetResults() { return m_result; }

    void SetNode(Node* node) { m_node = node; }

    bool SelectPrefixSuffix(Node* node);

protected:

    // Event handlers

    void OnAffirmative(wxUpdateUIEvent& event);
    void OnComboSelect(wxCommandEvent& event);
    void OnCustomID(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnStandardID(wxCommandEvent& event);
    void OnStdChange(wxCommandEvent& event);

private:

    // Class member variables

    wxCheckBox* m_checkAddPrefix;
    wxCheckBox* m_checkAddSuffix;
    wxChoice* m_standard_ids;
    wxComboBox* m_comboPrefixes;
    wxComboBox* m_comboSuffix;
    wxFlexGridSizer* m_flex_grid_sizer;
    wxRadioButton* m_radioBtn_Custom;
    wxStaticBoxSizer* m_cstm_id_box;
    wxRadioButton* m_radioBtn_Standard;
    wxStaticBoxSizer* m_std_id_box;
    wxStaticText* m_final_id;
    wxStaticText* m_help_text;
    wxStaticText* m_stock_label;
    wxTextCtrl* m_textID;
    wxTextCtrl* m_textValue;

    Node* m_node;

    wxString m_result;

    bool m_prefix_selected { false };

    bool m_suffix_selected { false };

};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
