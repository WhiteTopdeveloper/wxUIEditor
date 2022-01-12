////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/listctrl.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>

class ArtPropertyDlgBase : public wxDialog
{
public:
    ArtPropertyDlgBase() {}
    ArtPropertyDlgBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Art Provider Image",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Art Provider Image",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnChooseClient(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSelectItem(wxListEvent& event) { event.Skip(); }

    // Class member variables

    wxChoice* m_choice_client;
    wxListView* m_list;
    wxStaticBitmap* m_canvas;
    wxStaticText* m_text;
};
