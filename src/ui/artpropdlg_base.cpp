////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/sizer.h>

#include "artpropdlg_base.h"

bool ArtPropertyDlgBase::Create(wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint&pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto box_sizer4 = new wxBoxSizer(wxVERTICAL);
    box_sizer->Add(box_sizer4, wxSizerFlags().Border(wxALL));

    m_list = new wxListView(this, wxID_ANY, wxDefaultPosition, wxSize(250, 400), wxLC_REPORT|wxLC_NO_HEADER|wxLC_SINGLE_SEL|wxBORDER_SUNKEN|wxLC_REPORT);
    box_sizer4->Add(m_list, wxSizerFlags().Border(wxRIGHT, 10));

    auto box_sizer3 = new wxBoxSizer(wxVERTICAL);
    box_sizer->Add(box_sizer3, wxSizerFlags(1).Border(wxALL));

    m_text = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("Size: 333x333"));
    box_sizer3->Add(m_text, wxSizerFlags().Border(wxALL));

    m_canvas = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    box_sizer3->Add(m_canvas, wxSizerFlags().Border(wxALL));

    auto box_sizer2 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer2, wxSizerFlags().Border(wxALL));

    auto staticText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("Client:"));
    box_sizer2->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_choice_client = new wxChoice(this, wxID_ANY);
    box_sizer2->Add(m_choice_client, wxSizerFlags(1).Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    m_list->Bind(wxEVT_LIST_ITEM_SELECTED, &ArtPropertyDlgBase::OnSelectItem, this);
    m_choice_client->Bind(wxEVT_CHOICE, &ArtPropertyDlgBase::OnChooseClient, this);

    return true;
}
