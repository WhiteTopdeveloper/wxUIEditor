////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "commonctrls_base.h"

CommonCtrlsBase::CommonCtrlsBase(wxWindow* parent, wxWindowID id, const wxString& title,
		const wxPoint& pos, const wxSize& size, long style) :
	wxDialog(parent, id, title, pos, size, style)
{
    SetSizeHints(wxDefaultSize);

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer6 = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer6, wxSizerFlags().Expand().Border(wxALL));

    m_infoCtrl = new wxInfoBar(this);
    m_infoCtrl->SetShowHideEffects(wxSHOW_EFFECT_EXPAND, wxSHOW_EFFECT_NONE);
    box_sizer6->Add(m_infoCtrl, wxSizerFlags().Expand().Border(wxALL));

    auto box_sizer = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    m_staticText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("Text:"));
    box_sizer->Add(m_staticText, wxSizerFlags().Center().Border(wxLEFT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_textCtrl = new wxTextCtrl(this, wxID_ANY, wxString::FromUTF8("Text \"ctrl\""), wxDefaultPosition, wxDefaultSize,
    wxTE_PROCESS_ENTER);
    m_textCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &m_textCtrlValidate));
    box_sizer->Add(m_textCtrl, wxSizerFlags().Border(wxALL));

    m_staticText2 = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("More text:"));
    box_sizer->Add(m_staticText2, wxSizerFlags().Center().Border(wxLEFT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_textCtrl2 = new wxTextCtrl(this, wxID_ANY, wxString::FromUTF8("Another ctrl"));
    box_sizer->Add(m_textCtrl2, wxSizerFlags().Border(wxALL));

    m_checkBox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("2-state Checkbox"));
    box_sizer->Add(m_checkBox, wxSizerFlags().Center().Border(wxALL));

    auto box_sizer2 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer2, wxSizerFlags().Expand().Border(wxALL));

    m_btn = new wxButton(this, wxID_ANY, wxString::FromUTF8("First btn"));
    box_sizer2->Add(m_btn, wxSizerFlags().Border(wxALL));

    auto btn2 = new wxButton(this, wxID_ANY, wxString::FromUTF8("Popup"));
    box_sizer2->Add(btn2, wxSizerFlags().Border(wxALL));

    m_radioBtn = new wxRadioButton(this, wxID_ANY, wxString::FromUTF8("First radio"), wxDefaultPosition, wxDefaultSize,
    wxRB_GROUP);
    box_sizer2->Add(m_radioBtn, wxSizerFlags().Center().Border(wxALL));

    m_radioBtn2 = new wxRadioButton(this, wxID_ANY, wxString::FromUTF8("Second radio"));
    box_sizer2->Add(m_radioBtn2, wxSizerFlags().Center().Border(wxALL));

    m_checkBox2 = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("Checkbox"));
    box_sizer2->Add(m_checkBox2, wxSizerFlags().Center().Border(wxALL));

    auto static_box = new wxStaticBoxSizer(wxVERTICAL, this, wxString::FromUTF8("Combos and Choices"));
    parent_sizer->Add(static_box, wxSizerFlags().Expand().Border(wxALL));

    auto box_sizer3 = new wxBoxSizer(wxHORIZONTAL);
    static_box->Add(box_sizer3, wxSizerFlags().Expand().Border(wxALL));

    auto static_box_sizer2 = new wxStaticBoxSizer(wxVERTICAL, static_box->GetStaticBox(), wxString::FromUTF8("Combo"));
    box_sizer3->Add(static_box_sizer2, wxSizerFlags().Expand().Border(wxALL));

    m_staticText3 = new wxStaticText(static_box_sizer2->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Unsorted"));
    static_box_sizer2->Add(m_staticText3, wxSizerFlags().Border(wxALL));

    m_comboBox = new wxComboBox(static_box_sizer2->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_comboBox->Append(wxString::FromUTF8("item #1"));
    m_comboBox->Append(wxString::FromUTF8("item #2"));
    m_comboBox->Append(wxString::FromUTF8("item #0"));
    m_comboBox->SetStringSelection(wxString::FromUTF8("item #2"));
    m_comboBox->SetToolTip(wxString::FromUTF8("Item #0 should be selected by default"));
    static_box_sizer2->Add(m_comboBox, wxSizerFlags().Expand().Border(wxALL));

    m_staticText4 = new wxStaticText(static_box_sizer2->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Sorted"));
    static_box_sizer2->Add(m_staticText4, wxSizerFlags().Border(wxALL));

    m_comboBox2 = new wxComboBox(static_box_sizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_SORT);
    m_comboBox2->Append(wxString::FromUTF8("item #1"));
    m_comboBox2->Append(wxString::FromUTF8("item #2"));
    m_comboBox2->Append(wxString::FromUTF8("item #0"));
    m_comboBox2->SetStringSelection(wxString::FromUTF8("item #2"));
    m_comboBox2->SetToolTip(wxString::FromUTF8("Item #2 should be selected by default"));
    static_box_sizer2->Add(m_comboBox2, wxSizerFlags().Border(wxALL));

    auto static_box_sizer3 = new wxStaticBoxSizer(wxVERTICAL, static_box->GetStaticBox(), wxString::FromUTF8("Choice"));
    box_sizer3->Add(static_box_sizer3, wxSizerFlags().Expand().Border(wxALL));

    m_staticText5 = new wxStaticText(static_box_sizer3->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Unsorted"));
    static_box_sizer3->Add(m_staticText5, wxSizerFlags().Border(wxALL));

    m_choice = new wxChoice(static_box_sizer3->GetStaticBox(), wxID_ANY);
    m_choice->Append(wxString::FromUTF8("item #1"));
    m_choice->Append(wxString::FromUTF8("item #2"));
    m_choice->Append(wxString::FromUTF8("item #0"));
    m_choice->SetSelection(2);
    m_choice->SetToolTip(wxString::FromUTF8("Item #0 should be selected by default"));
    static_box_sizer3->Add(m_choice, wxSizerFlags().Border(wxALL));

    m_staticText6 = new wxStaticText(static_box_sizer3->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Sorted"));
    static_box_sizer3->Add(m_staticText6, wxSizerFlags().Border(wxALL));

    m_choice2 = new wxChoice(static_box_sizer3->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_SORT);
    m_choice2->Append(wxString::FromUTF8("item #1"));
    m_choice2->Append(wxString::FromUTF8("item #2"));
    m_choice2->Append(wxString::FromUTF8("item #0"));
    m_choice2->SetSelection(2);
    m_choice2->SetToolTip(wxString::FromUTF8("Item #2 should be selected by default"));
    static_box_sizer3->Add(m_choice2, wxSizerFlags().Border(wxALL));

    auto static_box_sizer4 = new wxStaticBoxSizer(wxVERTICAL, static_box->GetStaticBox(), wxString::FromUTF8("List"));
    box_sizer3->Add(static_box_sizer4, wxSizerFlags().Expand().Border(wxALL));

    m_staticText7 = new wxStaticText(static_box_sizer4->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Unsorted"));
    static_box_sizer4->Add(m_staticText7, wxSizerFlags().Border(wxALL));

    m_listBox = new wxListBox(static_box_sizer4->GetStaticBox(), wxID_ANY);
    m_listBox->Append(wxString::FromUTF8("item #1"));
    m_listBox->Append(wxString::FromUTF8("item #2"));
    m_listBox->Append(wxString::FromUTF8("item #0"));
    static_box_sizer4->Add(m_listBox, wxSizerFlags().Border(wxALL));

    m_staticText8 = new wxStaticText(static_box_sizer4->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Sorted"));
    static_box_sizer4->Add(m_staticText8, wxSizerFlags().Border(wxALL));

    m_listBox2 = new wxListBox(static_box_sizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE|wxLB_SORT);
    m_listBox2->Append(wxString::FromUTF8("item #1"));
    m_listBox2->Append(wxString::FromUTF8("item #2"));
    m_listBox2->Append(wxString::FromUTF8("item #0"));
    static_box_sizer4->Add(m_listBox2, wxSizerFlags().Border(wxALL));

    auto static_box_sizer5 = new wxStaticBoxSizer(wxVERTICAL, static_box->GetStaticBox(), wxString::FromUTF8("Checked"));
    box_sizer3->Add(static_box_sizer5, wxSizerFlags().Expand().Border(wxALL));

    m_staticText9 = new wxStaticText(static_box_sizer5->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Unsorted"));
    static_box_sizer5->Add(m_staticText9, wxSizerFlags().Border(wxALL));

    m_checkList = new wxCheckListBox(static_box_sizer5->GetStaticBox(), wxID_ANY);
    m_checkList->Append(wxString::FromUTF8("item #1"));
    m_checkList->Append(wxString::FromUTF8("item #2"));
    m_checkList->Append(wxString::FromUTF8("item #0"));
    static_box_sizer5->Add(m_checkList, wxSizerFlags().Border(wxALL));

    m_staticText10 = new wxStaticText(static_box_sizer5->GetStaticBox(), wxID_ANY, wxString::FromUTF8("Sorted"));
    static_box_sizer5->Add(m_staticText10, wxSizerFlags().Border(wxALL));

    m_checkList2 = new wxCheckListBox(static_box_sizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE|wxLB_SORT);
    m_checkList2->Append(wxString::FromUTF8("item #1"));
    m_checkList2->Append(wxString::FromUTF8("item #2"));
    m_checkList2->Append(wxString::FromUTF8("item #0"));
    static_box_sizer5->Add(m_checkList2, wxSizerFlags().Border(wxALL));

    auto flex_grid_sizer = new wxFlexGridSizer(4, 0, 0);
    parent_sizer->Add(flex_grid_sizer, wxSizerFlags().Expand().Border(wxALL));

    m_staticText11 = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("On Windows 10, the items may be be clipped unless they have a trailing space."));
    m_staticText11->Wrap(200);
    flex_grid_sizer->Add(m_staticText11, wxSizerFlags().Border(wxALL));

	wxString radioBox_choices[] = {
		wxString::FromUTF8("Button zero "),
		wxString::FromUTF8("Button one "),
		wxString::FromUTF8("Button two "),
	};
	m_radioBox = new wxRadioBox(this, wxID_ANY, wxString::FromUTF8("Radio Box"),
		wxDefaultPosition, wxDefaultSize, 3, radioBox_choices, 0, wxRA_SPECIFY_ROWS);
    m_radioBox->SetValidator(wxGenericValidator(&m_valRadio));
    flex_grid_sizer->Add(m_radioBox, wxSizerFlags().Border(wxALL));

    auto bmp = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxArtProvider::GetBitmap(wxART_GO_HOME, wxART_OTHER)));
    flex_grid_sizer->Add(bmp, wxSizerFlags().Border(wxALL));

    m_bmpComboBox = new wxBitmapComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    flex_grid_sizer->Add(m_bmpComboBox, wxSizerFlags().Border(wxALL));

    auto box_sizer5 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer5, wxSizerFlags().Expand().Border(wxALL));

    m_staticText12 = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("Slider:"));
    box_sizer5->Add(m_staticText12, wxSizerFlags().Center().Border(wxLEFT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_slider = new wxSlider(this, wxID_ANY, 50, 0, 100);
    m_slider->SetValue(50);
    box_sizer5->Add(m_slider, wxSizerFlags().Border(wxALL));

    m_staticText13 = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("Guage:"));
    box_sizer5->Add(m_staticText13, wxSizerFlags().Center().Border(wxLEFT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_gauge = new wxGauge(this, wxID_ANY, 100);
    m_gauge->SetValue(0);
    box_sizer5->Add(m_gauge, wxSizerFlags().Center().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL|wxHELP);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);

    Centre(wxBOTH);

    // Event handlers
    m_textCtrl->Bind(wxEVT_TEXT_ENTER, &CommonCtrlsBase::OnProcessEnter, this);
    m_checkBox->Bind(wxEVT_CHECKBOX, &CommonCtrlsBase::OnCheckBox, this);
    m_btn->Bind(wxEVT_BUTTON, &CommonCtrlsBase::OnFirstBtn, this);
    btn2->Bind(wxEVT_BUTTON, &CommonCtrlsBase::OnPopupBtn, this);
    m_radioBtn->Bind(wxEVT_RADIOBUTTON, &CommonCtrlsBase::OnRadio, this);
    m_radioBtn2->Bind(wxEVT_RADIOBUTTON, &CommonCtrlsBase::OnRadio, this);
    m_checkBox2->Bind(wxEVT_CHECKBOX, &CommonCtrlsBase::OnCheckBox, this);
    m_comboBox->Bind(wxEVT_COMBOBOX, &CommonCtrlsBase::OnCombo, this);
    m_comboBox2->Bind(wxEVT_COMBOBOX_CLOSEUP, &CommonCtrlsBase::OnComboClose, this);
    m_choice->Bind(wxEVT_CHOICE, &CommonCtrlsBase::OnChoice, this);
    m_choice2->Bind(wxEVT_CHOICE, &CommonCtrlsBase::OnChoice, this);
    m_listBox->Bind(wxEVT_LISTBOX, &CommonCtrlsBase::OnListBox, this);
    m_listBox2->Bind(wxEVT_LISTBOX, &CommonCtrlsBase::OnListBox, this);
    m_checkList->Bind(wxEVT_CHECKLISTBOX, &CommonCtrlsBase::OnListChecked, this);
    m_radioBox->Bind(wxEVT_RADIOBOX, &CommonCtrlsBase::OnRadioBox, this);
    m_slider->Bind(wxEVT_SLIDER, &CommonCtrlsBase::OnSlider, this);
}
