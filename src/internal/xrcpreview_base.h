////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/srchctrl.h>
#include <wx/stattext.h>
#include <wx/stc/stc.h>

class XrcPreviewBase : public wxDialog
{
public:
    XrcPreviewBase() {}
    XrcPreviewBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Test XRC",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Test XRC",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr);

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnCreate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExport(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnPreview(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSearch(wxCommandEvent& event) { event.Skip(); }
    virtual void OnXrcCopy(wxCommandEvent& event) { event.Skip(); }

    // Class member variables

    wxButton* m_btn;
    wxButton* m_btn_2;
    wxButton* m_btn_3;
    wxButton* m_btn_4;
    wxSearchCtrl* m_searchCtrl;
    wxStaticText* m_staticText;
    wxStyledTextCtrl* m_scintilla;
};
