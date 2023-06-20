///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/sizer.h>

#include <wx/filedlg.h>
#include <wx/tokenzr.h>

#include "include_files_dlg.h"

#include "node.h"
#include "node_prop.h"
#include "project_handler.h"

bool IncludeFilesDialog::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(this, wxID_ANY,
        "These header files will be added as #includes to the the generated header file.");
    m_staticText->Wrap(350);
    dlg_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    m_listbox = new wxListBox(this, wxID_ANY);
    m_listbox->SetFocus();
    m_listbox->SetMinSize(ConvertDialogToPixels(wxSize(100, 80)));
    box_sizer->Add(m_listbox, wxSizerFlags().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    auto* btn_add = new wxButton(this, wxID_ANY, "&Add...");
        btn_add->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_FILE_OPEN, wxART_BUTTON));
    box_sizer_2->Add(btn_add, wxSizerFlags().Expand().Border(wxALL));

    m_btn_remove = new wxButton(this, wxID_ANY, "&Remove");
        m_btn_remove->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_DELETE, wxART_BUTTON));
    box_sizer_2->Add(m_btn_remove, wxSizerFlags().Expand().Border(wxALL));

    m_btn_move_up = new wxButton(this, wxID_ANY, "Move &Up");
        m_btn_move_up->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_GO_UP, wxART_BUTTON));
    box_sizer_2->Add(m_btn_move_up, wxSizerFlags().Expand().Border(wxALL));

    m_btn_move_down = new wxButton(this, wxID_ANY, "Move &Down");
        m_btn_move_down->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_GO_DOWN, wxART_BUTTON));
    box_sizer_2->Add(m_btn_move_down, wxSizerFlags().Expand().Border(wxALL));

    m_btn_sort = new wxButton(this, wxID_ANY, "&Sort All");
        m_btn_sort->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_LIST_VIEW, wxART_BUTTON));
    box_sizer_2->Add(m_btn_sort, wxSizerFlags().Expand().Border(wxALL));

    box_sizer->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_BUTTON, &IncludeFilesDialog::OnOK, this, wxID_OK);
    btn_add->Bind(wxEVT_BUTTON, &IncludeFilesDialog::OnAdd, this);
    m_btn_remove->Bind(wxEVT_BUTTON, &IncludeFilesDialog::OnRemove, this);
    m_btn_move_up->Bind(wxEVT_BUTTON, &IncludeFilesDialog::OnMoveUp, this);
    m_btn_move_down->Bind(wxEVT_BUTTON, &IncludeFilesDialog::OnMoveDown, this);
    m_btn_sort->Bind(wxEVT_BUTTON, &IncludeFilesDialog::OnSort, this);
    Bind(wxEVT_INIT_DIALOG, &IncludeFilesDialog::OnInit, this);
    m_listbox->Bind(wxEVT_LISTBOX, &IncludeFilesDialog::OnItemSelected, this);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////////////////////////////////////////////////////////////////
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

void IncludeFilesDialog::Initialize(NodeProperty* prop)
{
    m_prop = prop;
}

void IncludeFilesDialog::SetButtonsEnableState()
{
    int sel = m_listbox->GetSelection();
    m_btn_remove->Enable(sel != wxNOT_FOUND);
    m_btn_move_up->Enable(sel > 0);
    m_btn_move_down->Enable(sel != wxNOT_FOUND && static_cast<unsigned int>(sel) < m_listbox->GetCount() - 1);
    m_btn_sort->Enable(m_listbox->GetCount() > 1);
    FindWindow(GetAffirmativeId())->Enable(m_listbox->GetCount() > 0);
}

void IncludeFilesDialog::OnInit(wxInitDialogEvent& WXUNUSED(event))
{
    ASSERT_MSG(m_prop, "m_prop is nullptr -- call Initialize()!");
    if (m_prop->get_name() == prop_system_hdr_includes || m_prop->get_name() == prop_system_src_includes)
    {
        SetTitle("System Header Files");
    }

    if (m_prop->HasValue())
    {
        tt_view_vector list;
        list.SetString(m_prop->value());
        for (auto& iter: list)
        {
            m_listbox->Append(iter.make_wxString());
        }
        if (m_listbox->GetCount())
        {
            m_listbox->SetSelection(0);
        }
    }

    SetButtonsEnableState();
}

void IncludeFilesDialog::OnAdd(wxCommandEvent& WXUNUSED(event))
{
    tt_wxString path;
    if (m_prop->get_name() == prop_local_hdr_includes || m_prop->get_name() == prop_local_src_includes)
    {
        auto* form = m_prop->GetNode();
        auto* parent_node = form->GetParent();
        if (parent_node->isGen(gen_folder) && parent_node->HasValue(prop_folder_base_directory))
        {
            path = parent_node->value(prop_folder_base_directory);
        }
        else if (Project.HasValue(prop_base_directory))
        {
            path = Project.value(prop_base_directory);
        }

        if (path.size())
        {
            path.append_filename(form->value(prop_base_file).filename());
        }
        else
        {
            path = form->value(prop_base_file);
        }

        if (path.size())
        {
            path.make_absolute();
            path.remove_filename();
        }

        if (path.empty())
        {
            path = Project.ProjectPath();
        }
    }
    else  // if (m_prop->get_name() == prop_system_hdr_includes)
    {
        // Get the path to the WXWIN (wxWidgets) include directory
        if (!wxGetEnv("WXWIN", &path))
        {
            // Get the INCLUDE environment variable, and parse out the first path that has wxWidgets in it.
            wxString include_paths;
            if (wxGetEnv("INCLUDE", &include_paths))
            {
                wxStringTokenizer tokenizer(include_paths, ";");
                while (tokenizer.HasMoreTokens())
                {
                    wxString include_path = tokenizer.GetNextToken();
                    if (include_path.Contains("wxWidgets"))
                    {
                        path = include_path;
                        break;
                    }
                }
            }
        }
        else
        {
            if (!path.Contains("include"))
            {
                path += "/include";
            }
        }
    }

    wxFileDialog dialog(this, "Include Header File", path, wxEmptyString, "Header Files|*.;*.h;*.hh;*.hpp;*.hxx",
                        wxFD_OPEN);
    if (dialog.ShowModal() == wxID_OK)
    {
        tt_wxString filename = dialog.GetPath();
        filename.make_relative_wx(path);
        filename.backslashestoforward();
        m_listbox->Append(filename);
        SetButtonsEnableState();
    }
}

void IncludeFilesDialog::OnItemSelected(wxCommandEvent& WXUNUSED(event))
{
    SetButtonsEnableState();
}

void IncludeFilesDialog::OnMoveUp(wxCommandEvent& WXUNUSED(event))
{
    // Move the currently selected item up one position in the listbox
    int sel = m_listbox->GetSelection();
    if (sel == wxNOT_FOUND || sel == 0)
        return;
    const wxString stringTmp = m_listbox->GetString(sel - 1);
    m_listbox->SetString(sel - 1, m_listbox->GetString(sel));
    m_listbox->SetString(sel, stringTmp);
    m_listbox->SetSelection(sel - 1);
    SetButtonsEnableState();
}

void IncludeFilesDialog::OnMoveDown(wxCommandEvent& WXUNUSED(event))
{
    // Move the currently selected item down one position in the listbox
    int sel = m_listbox->GetSelection();
    if (sel == wxNOT_FOUND || static_cast<unsigned int>(sel) == m_listbox->GetCount() - 1)
        return;
    const wxString stringTmp = m_listbox->GetString(sel + 1);
    m_listbox->SetString(sel + 1, m_listbox->GetString(sel));
    m_listbox->SetString(sel, stringTmp);
    m_listbox->SetSelection(sel + 1);
    SetButtonsEnableState();
}

void IncludeFilesDialog::OnRemove(wxCommandEvent& WXUNUSED(event))
{
    if (int sel = m_listbox->GetSelection(); sel != wxNOT_FOUND)
    {
        m_listbox->Delete(sel);
        if (static_cast<unsigned int>(sel) < m_listbox->GetCount())
        {
            m_listbox->SetSelection(sel);
        }
        SetButtonsEnableState();
    }
}

void IncludeFilesDialog::OnSort(wxCommandEvent& WXUNUSED(event))
{
    if (m_listbox->GetCount() < 2)
        return;

    std::vector<tt_wxString> items;
    for (unsigned int i = 0; i < m_listbox->GetCount(); i++)
    {
        items.push_back(m_listbox->GetString(i));
    }
    std::sort(items.begin(), items.end(),
              [](const tt_wxString& first, const tt_wxString& second)
              {
                  return first.CmpNoCase(second) < 0;
              });
    m_listbox->Clear();
    for (auto& item: items)
    {
        m_listbox->Append(item);
    }
    m_listbox->SetSelection(0);
    SetButtonsEnableState();
}

void IncludeFilesDialog::OnOK(wxCommandEvent& event)
{
    if (m_listbox->GetCount() > 0)
    {
        m_value.clear();
        for (unsigned int i = 0; i < m_listbox->GetCount(); i++)
        {
            if (m_value.size())
                m_value += ";";
            m_value += m_listbox->GetString(i);
        }
    }

    event.Skip();
}
