///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/valgen.h>

#include "generate_dlg.h"

bool GenerateDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(this, wxID_ANY, "Choose the code you want to generate:");
    dlg_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* checkBox = new wxCheckBox(this, wxID_ANY, "C++ &Base");
    checkBox->SetValidator(wxGenericValidator(&m_gen_base_code));
    box_sizer->Add(checkBox, wxSizerFlags().Border(wxALL));

    checkBox_6 = new wxCheckBox(this, wxID_ANY, "C++ &Inherited");
    checkBox_6->SetValidator(wxGenericValidator(&m_gen_inherited_code));
    box_sizer->Add(checkBox_6, wxSizerFlags().Border(wxALL));

    auto* checkBox_5 = new wxCheckBox(this, wxID_ANY, "&Python");
    checkBox_5->SetValidator(wxGenericValidator(&m_gen_python_code));
    box_sizer->Add(checkBox_5, wxSizerFlags().Border(wxALL));

    auto* checkBox_2 = new wxCheckBox(this, wxID_ANY, "&XRC");
    checkBox_2->SetValidator(wxGenericValidator(&m_gen_xrc_code));
    box_sizer->Add(checkBox_2, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &GenerateDlg::OnInit, this);

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

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   Dialog for choosing and generating specific language file(s)
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "gen_results.h"      // Code generation file writing functions
#include "image_handler.h"    // ImageHandler class
#include "mainframe.h"        // MainFrame -- Main application window
#include "project_handler.h"  // ProjectHandler class

#include "../wxui/dlg_gen_results.h"

enum
{
    GEN_BASE_CODE = 1 << 0,
    GEN_INHERITED_CODE = 1 << 1,
    GEN_PYTHON_CODE = 1 << 2,
    GEN_XRC_CODE = 1 << 3
};

// This generates the base class files. For the derived class files, see OnGenInhertedClass()
// in generate/gen_codefiles.cpp
void MainFrame::OnGenerateCode(wxCommandEvent&)
{
    ProjectImages.UpdateEmbedNodes();
    ProjectImages.UpdateEmbedNodes();

    GenerateDlg dlg(this);
    if (dlg.ShowModal() == wxID_OK)
    {
        GenResults results;

        if (dlg.is_gen_base())
        {
            GenerateCodeFiles(results);
        }
        if (dlg.is_gen_inherited())
        {
            GenInhertedClass(results);
        }
        if (dlg.is_gen_python())
        {
            GeneratePythonFiles(results);
        }
        if (dlg.is_gen_xrc())
        {
            GenerateXrcFiles(results);
        }

        if ((results.updated_files.size() || results.msgs.size()))
        {
            GeneratedResultsDlg results_dlg;
            results_dlg.Create(this);
            for (auto& iter: results.updated_files)
            {
                iter.make_relative(Project.ProjectPath().utf8_string());
                results_dlg.m_lb_files->Append(iter);
            }

            if (results.updated_files.size() == 1)
                results.msgs.emplace_back("1 file was updated");
            else
                results.msgs.emplace_back() << results.updated_files.size() << " files were updated";

            for (auto& iter: results.msgs)
            {
                results_dlg.m_lb_info->Append(iter);
            }

            results_dlg.ShowModal();
        }
        else if (results.file_count)
        {
            ttlib::cstr msg;
            msg << '\n' << "All " << results.file_count << " generated files are current";
            wxMessageBox(msg, "Code Generation", wxOK, this);
        }

        UpdateWakaTime();
    }
}

void GenerateDlg::OnInit(wxInitDialogEvent& event)
{
    if (Project.value(prop_code_preference) == "C++")
    {
        m_gen_python_code = false;
        m_gen_base_code = true;
        m_gen_xrc_code = false;
    }
    else if (Project.value(prop_code_preference) == "Python")
    {
        m_gen_python_code = true;
        m_gen_base_code = false;
        m_gen_xrc_code = false;
    }
    else if (Project.value(prop_code_preference) == "XRC")
    {
        m_gen_python_code = false;
        m_gen_base_code = false;
        m_gen_xrc_code = true;
    }
    else
    {
        m_gen_python_code = false;
        m_gen_base_code = true;
        m_gen_xrc_code = false;
    }
    event.Skip();
}
