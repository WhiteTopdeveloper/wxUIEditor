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

#include "menudatactrl_base.h"

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
    extern const unsigned char dataview_ctrl_png[231];
    extern const unsigned char dataviewlist_ctrl_png[685];
    extern const unsigned char dataviewtree_ctrl_png[238];
}

MenuDataCtrl::MenuDataCtrl() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxDataViewCtrl, "Insert wxDataViewCtrl");
    menu_item->SetBitmap(GetImageFromArray(wxue_img::dataview_ctrl_png, sizeof(wxue_img::dataview_ctrl_png)));

    auto menu_item_2 = Append(gen_wxDataViewTreeCtrl, "Insert wxDataViewTreeCtrl");
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::dataviewtree_ctrl_png, sizeof(wxue_img::dataviewtree_ctrl_png)));

    auto menu_item_3 = Append(gen_wxDataViewListCtrl, "Insert wxDataViewListCtrl");
    menu_item_3->SetBitmap(GetImageFromArray(wxue_img::dataviewlist_ctrl_png, sizeof(wxue_img::dataviewlist_ctrl_png)));
}
