////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "ribbon_ids.h"
#include "gen_enums.h"     // Enumerations for generators

using namespace GenEnum;

#include "menuspin_base.h"

#include <wx/mstream.h>  // Memory stream classes

// Convert a data array into a wxImage
inline wxImage GetImageFromArray(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

namespace wxue_img
{
    extern const unsigned char spin_ctrl_double_png[219];
    extern const unsigned char spin_ctrl_png[300];
    extern const unsigned char spinbtn_png[192];
}

MenuSpin::MenuSpin() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxSpinCtrl, "Insert wxSpinCtrl");
    menu_item->SetBitmap(GetImageFromArray(wxue_img::spin_ctrl_png, sizeof(wxue_img::spin_ctrl_png)));

    auto menu_item_2 = Append(gen_wxSpinCtrlDouble, "Insert wxSpinCtrlDouble");
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::spin_ctrl_double_png, sizeof(wxue_img::spin_ctrl_double_png)));

    auto menu_item_3 = Append(gen_wxSpinButton, "Insert wxSpinButton");
    menu_item_3->SetBitmap(GetImageFromArray(wxue_img::spinbtn_png, sizeof(wxue_img::spinbtn_png)));
}
