////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/bitmap.h>
#include <wx/colour.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/hyperlink.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

class MsgFrameBase : public wxFrame
{
public:
    MsgFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& title = "wxUiEditor Messages",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);

    enum
    {
        id_event_msgs = wxID_HIGHEST + 1,
        id_hide,
        id_warning_msgs
    };

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnClear(wxCommandEvent& event) { event.Skip(); }
    virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
    virtual void OnEvents(wxCommandEvent& event) { event.Skip(); }
    virtual void OnHide(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInfo(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPageChanged(wxBookCtrlEvent& event) { event.Skip(); }
    virtual void OnParent(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveAs(wxCommandEvent& event) { event.Skip(); }
    virtual void OnWarnings(wxCommandEvent& event) { event.Skip(); }

    // Class member variables

    wxHyperlinkCtrl* m_hyperlink;
    wxMenuItem* m_menu_item_events;
    wxMenuItem* m_menu_item_info;
    wxMenuItem* m_menu_item_warnings;
    wxNotebook* m_notebook;
    wxPanel* m_page_log;
    wxPanel* m_page_node;
    wxStaticText* m_txt_clipboard;
    wxStaticText* m_txt_generator;
    wxStaticText* m_txt_memory;
    wxStaticText* m_txt_project;
    wxStaticText* m_txt_type;
    wxTextCtrl* m_textCtrl;
};

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char hide_png[242];
}
