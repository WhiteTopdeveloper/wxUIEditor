////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>

#include "optionsdlg_base.h"

OptionsDlgBase::OptionsDlgBase(wxWindow* parent) : wxDialog()
{
    Create(parent, wxID_ANY, wxString::FromUTF8("Options"));

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto checkBox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("New sizers have &borders on all sides"));
    checkBox->SetValidator(wxGenericValidator(&m_sizers_all_borders));
    box_sizer->Add(checkBox, wxSizerFlags().Border(wxALL));

    auto checkBox2 = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("New sizers have wx&EXPAND set"));
    checkBox2->SetValidator(wxGenericValidator(&m_sizers_always_expand));
    box_sizer->Add(checkBox2, wxSizerFlags().Border(wxALL));

    auto checkBox3 = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("New widgets always have a class &member"));
    checkBox3->SetValidator(wxGenericValidator(&m_class_access));
    box_sizer->Add(checkBox3, wxSizerFlags().Border(wxALL));

    auto flex_grid_sizer = new wxFlexGridSizer(2, 0, 0);
    box_sizer->Add(flex_grid_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto staticTextSrcExt = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("&Source code extension:"));
    flex_grid_sizer->Add(staticTextSrcExt, wxSizerFlags().Left().Border(wxALL));

    auto choiceSrc = new wxChoice(this, wxID_ANY);
    choiceSrc->Append(wxString::FromUTF8(".cpp"));
    choiceSrc->Append(wxString::FromUTF8(".cxx"));
    choiceSrc->Append(wxString::FromUTF8(".cc"));
    choiceSrc->SetValidator(wxGenericValidator(&m_src_extension));
    flex_grid_sizer->Add(choiceSrc, wxSizerFlags().Border(wxALL));

    auto staticTextHrdExt = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("&Header file extension:"));
    flex_grid_sizer->Add(staticTextHrdExt, wxSizerFlags().Left().Border(wxALL));

    auto choiceHdr = new wxChoice(this, wxID_ANY);
    choiceHdr->Append(wxString::FromUTF8(".h"));
    choiceHdr->Append(wxString::FromUTF8(".hpp"));
    choiceHdr->Append(wxString::FromUTF8(".hxx"));
    choiceHdr->Append(wxString::FromUTF8(".hh"));
    choiceHdr->SetValidator(wxGenericValidator(&m_hdr_extension));
    flex_grid_sizer->Add(choiceHdr, wxSizerFlags().Border(wxALL));

    auto staticText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("&Class member prefix"));
    flex_grid_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    auto textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    textCtrl->SetValidator(wxGenericValidator(&m_member_prefix));
    flex_grid_sizer->Add(textCtrl, wxSizerFlags().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &OptionsDlgBase::OnInit, this);
    Bind(wxEVT_BUTTON, &OptionsDlgBase::OnAffirmative, this, wxID_OK);
}
