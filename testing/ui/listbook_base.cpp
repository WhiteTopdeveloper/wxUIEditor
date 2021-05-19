////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>

#include "listbook_base.h"

#include "../art/english.xpm"
#include "../art/french.xpm"
#include "../art/japanese.xpm"

ListbookBase::ListbookBase(wxWindow* parent, wxWindowID id, const wxString& title,
		const wxPoint& pos, const wxSize& size, long style) :
	wxDialog(parent, id, title, pos, size, style)
{
    auto box_sizer = new wxBoxSizer(wxVERTICAL);

    m_listbook = new wxListbook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_LEFT);
    {
        auto img_list = new wxImageList(16, 16);
        auto img_0 = wxImage(english_xpm);
        img_list->Add(img_0.Scale(16, 16));
        auto img_1 = wxImage(french_xpm);
        img_list->Add(img_1.Scale(16, 16));
        auto img_2 = wxImage(japanese_xpm);
        img_list->Add(img_2.Scale(16, 16));
        m_listbook->AssignImageList(img_list);
    }
    m_listbook->SetMinSize(wxSize(400, 400));
    box_sizer->Add(m_listbook, wxSizerFlags().Border(wxALL));

    auto page = new wxPanel(m_listbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_listbook->AddPage(page, wxString::FromUTF8("English"), false, 0);
    page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page, wxID_ANY, wxString::FromUTF8("This is a sentence in English."));
    parent_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    page->SetSizerAndFit(parent_sizer);

    auto page_2 = new wxPanel(m_listbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_listbook->AddPage(page_2, wxString::FromUTF8("Français"), false, 1);
    page_2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto parent_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_2, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer_2->Add(m_staticText, wxSizerFlags().Border(wxALL));

    page_2->SetSizerAndFit(parent_sizer_2);

    auto page_3 = new wxPanel(m_listbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_listbook->AddPage(page_3, wxString::FromUTF8("日本語"), false, 2);
    page_3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto parent_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_3, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_3->Add(m_staticText, wxSizerFlags().Border(wxALL));

    page_3->SetSizerAndFit(parent_sizer_3);

    auto stdBtn = CreateStdDialogButtonSizer(wxCLOSE|wxNO_DEFAULT);
    stdBtn->GetCancelButton()->SetDefault();
    box_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(box_sizer);

    Centre(wxBOTH);
}
