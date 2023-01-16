///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/bmpbndl.h>
#include <wx/collpane.h>
#include <wx/colour.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "convert_img_base.h"

bool ConvertImageBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* collapsiblePane = new wxCollapsiblePane(this, wxID_ANY, "Dialog Description");
    collapsiblePane->Collapse();
    box_sizer->Add(collapsiblePane,
        wxSizerFlags(1).Expand().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    auto* box_sizer2 = new wxBoxSizer(wxHORIZONTAL);

    m_staticDescription = new wxStaticText(collapsiblePane->GetPane(), wxID_ANY,
        "This dialog can be used to convert an image into a file that can be #included into a source file. The original image can be any file format that wxWidgets supports.\n\nThe header output type is an array containing the image data in whatever format you choose. While the disk file size might be larger than an XPM file, the size in your executable will typically be quite a bit smaller.");
    m_staticDescription->Wrap(400);
    box_sizer2->Add(m_staticDescription, wxSizerFlags().Border(wxALL));
    collapsiblePane->GetPane()->SetSizerAndFit(box_sizer2);

    parent_sizer->Add(box_sizer,
    wxSizerFlags().Expand().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    auto* flex_grid_sizer = new wxFlexGridSizer(2, 0, 0);
    {
        flex_grid_sizer->AddGrowableCol(1);
    }

    m_staticOriginal_2 = new wxStaticText(this, wxID_ANY, "&Source:");
    flex_grid_sizer->Add(m_staticOriginal_2, wxSizerFlags().Center().Border(wxALL));

    m_fileOriginal = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, wxFileSelectorPromptStr,
        "Select file(s)\", \"All files|*.*|PNG|*.png|XPM|*.xpm|Tiff|*.tif;*.tiff|Bitmaps|*.bmp|Icon|*.ico||",
        wxDefaultPosition, wxSize(300, -1), wxFLP_USE_TEXTCTRL|wxFLP_OPEN|wxFLP_FILE_MUST_EXIST);
    flex_grid_sizer->Add(m_fileOriginal, wxSizerFlags().Expand().Border(wxALL));

    m_staticHeader = new wxStaticText(this, wxID_ANY, "O&utput:");
    flex_grid_sizer->Add(m_staticHeader, wxSizerFlags().Center().Border(wxALL));

    m_fileOutput = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, wxFileSelectorPromptStr,
        "Header files|*.h_img||", wxDefaultPosition, wxDefaultSize, wxFLP_SAVE|wxFLP_USE_TEXTCTRL);
    flex_grid_sizer->Add(m_fileOutput, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer->Add(flex_grid_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* static_box = new wxStaticBoxSizer(wxVERTICAL, this, "Output Type");

    m_choicebook = new wxChoicebook(static_box->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxCHB_LEFT);
    static_box->Add(m_choicebook, wxSizerFlags().Border(wxALL));

    auto* header_page = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(header_page, "Header");
    header_page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_2 = new wxBoxSizer(wxVERTICAL);

    auto* hdr_static_box = new wxStaticBoxSizer(wxVERTICAL, header_page, "Settings");

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_check_make_png = new wxCheckBox(hdr_static_box->GetStaticBox(), wxID_ANY, "Convert to &PNG");
    m_check_make_png->SetValue(true);
    m_check_make_png->SetToolTip("If checked, image will be converted to PNG before being saved.");
    box_sizer_2->Add(m_check_make_png, wxSizerFlags().Border(wxALL));

    m_ForceHdrMask = new wxCheckBox(hdr_static_box->GetStaticBox(), wxID_ANY, "&Force Mask");
    m_ForceHdrMask->SetToolTip("Check this to override any mask specified in the original image file.");
    box_sizer_2->Add(m_ForceHdrMask, wxSizerFlags().Border(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    box_sizer_3->AddSpacer(10);

    m_comboHdrMask = new wxComboBox(hdr_static_box->GetStaticBox(), wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxSize(150, -1), 0, nullptr, wxCB_READONLY);
    box_sizer_3->Add(m_comboHdrMask,
        wxSizerFlags().Left().Border(wxLEFT|wxRIGHT|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    box_sizer_2->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxHORIZONTAL);

    box_sizer_5->AddSpacer(10);

    m_staticHdrRGB = new wxStaticText(hdr_static_box->GetStaticBox(), wxID_ANY, "0 0 0");
    box_sizer_5->Add(m_staticHdrRGB, wxSizerFlags().Border(wxLEFT|wxRIGHT, wxSizerFlags::GetDefaultBorder()));

    box_sizer_2->Add(box_sizer_5, wxSizerFlags().Border(wxLEFT|wxRIGHT, wxSizerFlags::GetDefaultBorder()));

    hdr_static_box->Add(box_sizer_2, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer_2->Add(hdr_static_box, wxSizerFlags().Border(wxALL));
    header_page->SetSizerAndFit(parent_sizer_2);

    auto* xpm_page = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(xpm_page, "XPM");
    xpm_page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_3 = new wxBoxSizer(wxVERTICAL);

    auto* mask_static_box = new wxStaticBoxSizer(wxVERTICAL, xpm_page, "Settings");

    auto* box_sizer7 = new wxBoxSizer(wxVERTICAL);

    m_ConvertAlphaChannel = new wxCheckBox(mask_static_box->GetStaticBox(), wxID_ANY, "&Alpha Channel to Mask");
    m_ConvertAlphaChannel->SetValue(true);
    m_ConvertAlphaChannel->SetToolTip("Check this to replace any alpha channel with a mask.");
    box_sizer7->Add(m_ConvertAlphaChannel, wxSizerFlags().Expand().Border(wxALL));

    m_ForceXpmMask = new wxCheckBox(mask_static_box->GetStaticBox(), wxID_ANY, "&Force Mask");
    m_ForceXpmMask->SetToolTip("Check this to override any mask specified in the original image file.");
    box_sizer7->Add(m_ForceXpmMask, wxSizerFlags().Border(wxALL));

    auto* box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);

    box_sizer_4->AddSpacer(10);

    m_comboXpmMask = new wxComboBox(mask_static_box->GetStaticBox(), wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxSize(150, -1), 0, nullptr, wxCB_READONLY);
    box_sizer_4->Add(m_comboXpmMask,
        wxSizerFlags().Left().Border(wxLEFT|wxRIGHT|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    box_sizer7->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* box_sizer_6 = new wxBoxSizer(wxHORIZONTAL);

    box_sizer_6->AddSpacer(10);

    m_staticXpmRGB = new wxStaticText(mask_static_box->GetStaticBox(), wxID_ANY, "0 0 0");
    box_sizer_6->Add(m_staticXpmRGB, wxSizerFlags().Border(wxLEFT|wxRIGHT, wxSizerFlags::GetDefaultBorder()));

    box_sizer7->Add(box_sizer_6, wxSizerFlags().Border(wxLEFT|wxRIGHT, wxSizerFlags::GetDefaultBorder()));

    mask_static_box->Add(box_sizer7, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer_3->Add(mask_static_box, wxSizerFlags().Border(wxALL));
    xpm_page->SetSizerAndFit(parent_sizer_3);

    parent_sizer->Add(static_box, wxSizerFlags().Border(wxALL));

    auto* box_sizer6 = new wxBoxSizer(wxHORIZONTAL);

    m_staticDimensions = new wxStaticText(this, wxID_ANY, "16 x 16");
    m_staticDimensions->Hide();
    box_sizer6->Add(m_staticDimensions,
        wxSizerFlags(1).Center().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    parent_sizer->Add(box_sizer6,
    wxSizerFlags().Expand().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    auto* grid_sizer2 = new wxGridSizer(2, 0, 0);

    m_staticOriginal = new wxStaticText(this, wxID_ANY, "Source");
    m_staticOriginal->Hide();
    grid_sizer2->Add(m_staticOriginal,
        wxSizerFlags().Center().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_staticOutput = new wxStaticText(this, wxID_ANY, "Current");
    m_staticOutput->Hide();
    grid_sizer2->Add(m_staticOutput,
        wxSizerFlags().Center().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_bmpOriginal = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    m_bmpOriginal->Hide();
    grid_sizer2->Add(m_bmpOriginal, wxSizerFlags().Center().Border(wxALL));

    m_bmpOutput = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    m_bmpOutput->Hide();
    grid_sizer2->Add(m_bmpOutput, wxSizerFlags().Center().Border(wxALL));

    parent_sizer->Add(grid_sizer2, wxSizerFlags(1).Expand().Border(wxALL));

    auto* flex_grid_sizer2 = new wxFlexGridSizer(2, 1, 0, 0);

    m_staticSave = new wxStaticText(this, wxID_ANY, "save");
    m_staticSave->Hide();
    flex_grid_sizer2->Add(m_staticSave, wxSizerFlags().Expand().Border(wxALL));

    m_staticSize = new wxStaticText(this, wxID_ANY, "size");
    m_staticSize->Hide();
    flex_grid_sizer2->Add(m_staticSize, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer->Add(flex_grid_sizer2, wxSizerFlags().Expand().Border(wxALL));

    auto* grid_sizer = new wxGridSizer(2, 0, 0);

    m_btnConvert = new wxButton(this, wxID_ANY, "Convert");
    grid_sizer->Add(m_btnConvert, wxSizerFlags().Border(wxALL));

    m_btnClose = new wxButton(this, wxID_OK, "Close");
    grid_sizer->Add(m_btnClose, wxSizerFlags().Right().Border(wxALL));

    parent_sizer->Add(grid_sizer, wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    m_btnConvert->Bind(wxEVT_BUTTON, &ConvertImageBase::OnConvert, this);
    m_check_make_png->Bind(wxEVT_CHECKBOX, &ConvertImageBase::OnCheckPngConversion, this);
    m_ForceHdrMask->Bind(wxEVT_CHECKBOX, &ConvertImageBase::OnForceHdrMask, this);
    m_ConvertAlphaChannel->Bind(wxEVT_CHECKBOX, &ConvertImageBase::OnConvertAlpha, this);
    m_ForceXpmMask->Bind(wxEVT_CHECKBOX, &ConvertImageBase::OnForceXpmMask, this);
    m_choicebook->Bind(wxEVT_CHOICEBOOK_PAGE_CHANGED, &ConvertImageBase::OnPageChanged, this);
    m_comboHdrMask->Bind(wxEVT_COMBOBOX, &ConvertImageBase::OnComboHdrMask, this);
    m_comboXpmMask->Bind(wxEVT_COMBOBOX, &ConvertImageBase::OnComboXpmMask, this);
    m_fileOriginal->Bind(wxEVT_FILEPICKER_CHANGED, &ConvertImageBase::OnInputChange, this);
    m_fileOutput->Bind(wxEVT_FILEPICKER_CHANGED, &ConvertImageBase::OnOutputChange, this);

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
