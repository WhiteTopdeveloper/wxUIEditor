////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include "dbg_winres_dlg_base.h"

bool DbgWinResBase::Create(wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint&pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto box_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer_3 = new wxBoxSizer(wxVERTICAL);
    box_sizer->Add(box_sizer_3, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    auto staticText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("&Folders:"));
    box_sizer_3->Add(staticText, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    auto box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    m_list_folders = new wxListBox(this, wxID_ANY);
    m_list_folders->SetMinSize(wxSize(200, 150));
    m_list_folders->SetToolTip(wxString::FromUTF8("This list will be retained between sessions."));
    box_sizer_2->Add(m_list_folders, wxSizerFlags().Border(wxALL));

    auto btn = new wxButton(this, wxID_ANY, wxString::FromUTF8("Folder..."));
    btn->SetToolTip(wxString::FromUTF8("Add a folder to the Folders list."));
    box_sizer_2->Add(btn, wxSizerFlags().Border(wxALL));

    auto box_sizer_4 = new wxBoxSizer(wxVERTICAL);
    box_sizer->Add(box_sizer_4, wxSizerFlags().Expand().Border(wxALL));

    auto staticText_2 = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("&Resource Files:"));
    box_sizer_4->Add(staticText_2, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_list_files = new wxListBox(this, wxID_ANY);
    m_list_files->SetMinSize(wxSize(-1, 100));
    m_list_files->SetToolTip(wxString::FromUTF8("All the resource files located in all folders underneath the above selected folder."));
    box_sizer_4->Add(m_list_files, wxSizerFlags().Expand().Border(wxALL));

    m_res_file = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    m_res_file->SetToolTip(wxString::FromUTF8("Use this if you need to copy the filename to an editor for previewing."));
    box_sizer_4->Add(m_res_file, wxSizerFlags().Expand().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    box_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(box_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &DbgWinResBase::OnInit, this);
    m_list_folders->Bind(wxEVT_LISTBOX, &DbgWinResBase::OnSelectFolder, this);
    btn->Bind(wxEVT_BUTTON, &DbgWinResBase::OnFolderBtn, this);
    m_list_files->Bind(wxEVT_LISTBOX,
        [this](wxCommandEvent&) { m_res_file->SetValue(m_list_files->GetString(m_list_files->GetSelection())); }
        );
    Bind(wxEVT_BUTTON, &DbgWinResBase::OnAffirmative, this, wxID_OK);

    return true;
}
