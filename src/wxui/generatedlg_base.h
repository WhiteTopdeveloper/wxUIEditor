////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>

class GenerateDlgBase : public wxDialog
{
public:
    GenerateDlgBase() {}
    GenerateDlgBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Generate Code",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Generate Code",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    bool is_gen_base() const { return m_gen_base_code; }
    bool is_gen_inherited() const { return m_gen_inherited_code; }
    bool is_gen_python() const { return m_gen_python_code; }
    bool is_gen_xrc() const { return m_gen_xrc_code; }

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }

    // Validator variables

    bool m_gen_base_code { false };
    bool m_gen_inherited_code { false };
    bool m_gen_python_code { false };
    bool m_gen_xrc_code { false };

    // Class member variables

    wxCheckBox* checkBox_6;
    wxStaticText* m_staticText;
};
