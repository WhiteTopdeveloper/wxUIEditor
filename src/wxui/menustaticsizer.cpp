///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include "ui_images.h"

#include "ribbon_ids.h"
#include "gen_enums.h"     // Enumerations for generators

using namespace GenEnum;

#include "menustaticsizer.h"

MenuStaticSizer::MenuStaticSizer() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* menu_item = Append(gen_wxStaticBoxSizer, "Insert wxStaticBoxSizer");
    menu_item->SetBitmap(wxue_img::bundle_wxStaticBoxSizer_png());
    auto* menu_item_2 = Append(gen_StaticCheckboxBoxSizer, "Insert CheckBox wxStaticBoxSizer");
    menu_item_2->SetBitmap(wxue_img::bundle_wxStaticCheckBoxSizer_png());
    auto* menu_item_3 = Append(gen_StaticRadioBtnBoxSizer, "Insert RadioButton wxStaticBoxSizer");
    menu_item_3->SetBitmap(wxue_img::bundle_wxStaticRadioBtnSizer_png());
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
