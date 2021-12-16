////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/clrpicker.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>

namespace wxue_ctrl
{
class ColourRectCtrl;
}

class ColourPropBase : public wxDialog
{
public:
    ColourPropBase() {}
    ColourPropBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Colour Property",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Colour Property",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Class member variables

    wxColourPickerCtrl* m_colourPicker;
    wxComboBox* m_combo_system;
    wxRadioButton* m_radio_custom;
    wxStaticBoxSizer* m_staticbox_custom;
    wxRadioButton* m_radio_default;
    wxRadioButton* m_radio_system;
    wxStaticBoxSizer* m_staticbox_system;
    wxStaticText* m_static_sample_text;
    wxue_ctrl::ColourRectCtrl* m_colour_rect;

    // Virtual event handlers -- override them in your derived class

    virtual void OnColourChanged(wxColourPickerEvent& event) { event.Skip(); }
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRadioCustomColour(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRadioSystemColour(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSetDefault(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSystemColourChange(wxCommandEvent& event) { event.Skip(); }
};
