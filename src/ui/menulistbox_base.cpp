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

#include "menulistbox_base.h"

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
    extern const unsigned char wxCheckListBox_png[514];
    extern const unsigned char wxListBox_png[326];
    extern const unsigned char wxListView_png[372];
    extern const unsigned char wxRearrangeCtrl_png[348];
    extern const unsigned char wxSimpleHtmlListBox_png[692];
}

MenuListbox::MenuListbox() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxListBox, wxString::FromUTF8("Insert wxListBox"));
    menu_item->SetBitmap(GetImageFromArray(wxue_img::wxListBox_png, sizeof(wxue_img::wxListBox_png)));

    auto menu_item_2 = Append(gen_wxCheckListBox, wxString::FromUTF8("Insert wxCheckListBox"));
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::wxCheckListBox_png, sizeof(wxue_img::wxCheckListBox_png)));

    auto menu_item_3 = Append(gen_wxListView, wxString::FromUTF8("Insert wxListView"));
    menu_item_3->SetBitmap(GetImageFromArray(wxue_img::wxListView_png, sizeof(wxue_img::wxListView_png)));

    auto menu_item_4 = Append(gen_wxRearrangeCtrl, wxString::FromUTF8("Insert wxRearrangeCtrl"));
    menu_item_4->SetBitmap(GetImageFromArray(wxue_img::wxRearrangeCtrl_png, sizeof(wxue_img::wxRearrangeCtrl_png)));

    auto menu_item_5 = Append(gen_wxSimpleHtmlListBox, wxString::FromUTF8("Insert wxSimpleHtmlListBox"));
    menu_item_5->SetBitmap(GetImageFromArray(wxue_img::wxSimpleHtmlListBox_png, sizeof(wxue_img::wxSimpleHtmlListBox_png)));
}

namespace wxue_img
{

    const unsigned char wxCheckListBox_png[514] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,1,164,73,68,65,84,56,203,237,148,61,107,20,81,20,134,159,129,253,74,
    101,225,15,72,145,159,48,107,99,97,163,132,4,59,83,216,216,136,48,219,36,98,138,8,75,154,64,132,16,109,82,8,201,4,68,123,33,189,1,27,
    145,52,238,252,25,179,153,251,49,115,207,77,177,51,187,179,155,101,214,8,233,242,54,247,114,57,231,121,207,61,115,238,192,189,10,5,97,
    24,249,187,0,55,0,6,131,248,214,137,221,110,143,239,131,152,212,56,196,7,24,43,252,85,142,212,56,246,94,108,143,192,101,96,169,127,53,
    202,156,71,124,192,217,225,62,0,143,222,188,71,89,153,84,92,5,150,6,85,163,89,149,198,89,46,156,29,126,24,159,255,249,242,145,149,151,
    219,55,193,183,173,218,228,158,167,155,125,148,21,134,218,113,101,28,67,61,83,241,255,244,217,102,130,205,61,38,19,148,21,148,17,82,
    237,38,224,160,151,16,38,167,227,132,36,140,22,66,67,96,243,217,86,253,84,148,90,58,56,69,245,35,124,28,214,207,104,47,1,32,62,137,104,
    52,27,180,219,45,154,205,54,237,78,139,78,171,195,218,250,238,52,88,245,163,169,196,197,242,245,15,228,162,166,191,45,192,206,57,127,
    92,51,53,227,86,228,192,147,74,224,175,138,81,94,147,252,237,247,49,218,10,58,19,174,140,35,53,163,245,232,213,206,8,172,139,192,243,
    65,204,106,183,135,6,86,107,42,58,47,140,77,62,130,42,43,40,235,139,177,155,243,64,74,152,7,126,204,180,39,152,211,217,44,23,126,126,
    62,152,138,123,176,182,53,1,151,32,5,44,149,31,114,206,190,186,2,164,86,8,95,239,144,124,253,4,192,195,231,111,185,172,206,177,170,78,
    198,130,125,245,76,23,215,95,222,120,199,80,11,151,218,49,84,114,183,191,205,123,141,117,13,191,203,211,22,66,100,78,29,0,0,0,0,73,69,
    78,68,174,66,96,130
    };

    const unsigned char wxListBox_png[326] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,232,73,68,65,84,56,203,197,149,61,14,194,32,24,64,31,198,197,209,193,
    75,8,135,232,33,196,123,244,4,180,155,91,29,60,69,241,14,237,234,104,82,206,131,131,54,70,43,77,177,173,146,16,242,241,243,62,126,94,
    2,204,84,4,64,150,101,126,74,168,49,134,101,27,212,117,61,9,244,116,60,0,60,193,0,85,85,245,46,138,73,190,140,221,81,146,36,131,18,47,
    198,28,59,77,211,224,216,64,176,101,47,212,71,104,8,190,24,179,211,162,40,130,240,175,175,162,133,182,237,0,176,35,87,2,33,238,117,111,
    195,208,80,252,193,10,71,174,20,86,55,248,70,118,18,198,40,247,10,118,103,172,211,152,14,20,64,70,93,213,143,60,150,59,180,180,228,185,
    139,242,119,128,21,18,211,148,108,51,213,251,120,95,122,172,41,189,199,63,106,169,219,190,166,99,193,187,207,255,242,56,30,62,137,21,
    209,30,159,142,7,220,245,210,59,121,179,94,197,125,77,222,251,73,191,166,89,203,13,219,0,96,188,55,130,91,120,0,0,0,0,73,69,78,68,174,
    66,96,130
    };

    const unsigned char wxListView_png[372] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,1,22,73,68,65,84,56,203,213,148,189,138,194,64,20,133,191,145,128,104,
    173,111,96,39,86,73,97,99,179,213,90,250,18,250,4,62,197,62,65,250,237,183,212,74,144,109,182,200,54,194,150,130,175,160,96,68,156,117,
    44,204,224,36,153,24,227,31,120,155,64,206,185,231,94,206,156,25,120,181,18,174,219,87,143,16,118,0,198,163,225,93,69,223,187,31,148,
    138,52,44,230,115,106,245,198,229,27,111,194,16,20,32,12,68,27,36,64,41,5,226,4,110,214,225,137,155,52,82,24,194,171,213,50,123,180,
    209,88,169,86,249,155,125,91,133,172,27,55,91,157,171,253,148,209,119,11,252,3,59,0,62,143,194,183,8,154,162,169,141,1,60,111,144,41,
    18,4,126,234,95,219,224,79,35,124,7,236,147,194,182,230,115,245,19,241,183,25,120,233,86,95,49,188,221,27,152,3,32,6,191,119,189,32,
    174,105,133,242,221,120,138,114,134,229,241,157,75,133,82,143,76,14,223,177,77,207,171,181,197,91,237,189,4,122,30,197,114,44,19,7,150,
    196,100,145,28,235,24,234,166,114,36,254,102,225,127,5,126,60,21,69,114,172,111,217,36,240,99,17,147,207,122,232,95,175,14,242,170,97,
    56,100,196,221,110,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxRearrangeCtrl_png[348] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,254,73,68,65,84,56,203,237,85,49,14,130,48,20,125,53,93,228,58,237,
    228,224,72,24,25,56,3,61,3,91,55,207,80,206,224,224,104,28,221,76,232,224,224,89,136,137,73,93,0,91,44,182,162,35,47,33,41,205,255,143,
    223,255,223,43,192,130,14,132,177,210,124,147,160,117,77,250,181,49,198,155,75,8,33,20,0,154,70,69,145,114,46,96,147,222,174,23,111,
    156,148,210,80,95,82,236,135,122,236,15,71,0,64,145,103,195,222,202,14,176,9,57,23,206,19,34,29,175,233,212,81,99,171,182,171,180,65,
    231,30,63,4,10,0,68,104,48,93,191,38,207,74,111,48,27,77,94,74,105,38,134,71,156,86,172,119,53,218,170,132,81,236,93,66,66,123,9,62,
    86,220,163,173,202,73,146,89,173,184,43,6,32,220,227,13,119,223,131,6,121,0,216,90,138,56,71,12,50,202,32,73,183,113,106,20,82,46,144,
    140,164,55,71,53,78,143,211,25,58,182,77,97,235,250,103,29,23,121,230,181,52,253,135,25,124,238,163,240,244,51,234,190,13,24,100,249,
    35,13,120,2,55,75,104,132,222,85,16,207,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxSimpleHtmlListBox_png[692] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,2,86,73,68,65,84,56,203,213,149,75,72,84,81,24,199,127,247,49,183,73,
    45,77,113,28,29,31,99,19,45,74,178,232,73,6,13,244,4,161,54,13,133,32,4,45,2,119,5,173,92,204,93,245,160,133,45,12,106,83,161,148,13,
    182,105,33,149,36,106,101,105,46,122,208,68,6,62,211,201,41,132,148,212,59,143,58,45,38,71,135,155,147,208,184,232,91,125,247,59,223,
    249,241,63,223,57,252,47,44,83,72,0,186,174,139,84,66,189,94,47,234,220,71,71,71,71,74,160,245,87,46,2,204,131,1,218,219,219,255,25,
    236,127,211,99,6,3,180,180,52,81,89,89,129,17,28,228,217,8,236,223,94,26,95,251,25,142,32,107,174,216,9,171,14,99,81,148,132,189,21,
    141,45,241,92,54,129,27,154,232,155,136,210,214,246,128,222,222,129,69,149,89,53,149,145,233,25,12,4,131,223,167,177,104,137,26,77,138,
    11,215,57,233,127,235,231,155,164,242,161,199,207,249,80,16,35,48,202,104,96,156,218,250,75,184,180,249,222,71,253,99,204,68,163,76,
    26,97,106,247,148,39,112,76,138,179,242,29,4,252,47,73,203,46,192,158,157,142,69,85,40,220,125,4,207,193,45,38,213,59,28,185,60,25,30,
    167,56,51,131,213,43,180,228,96,228,52,108,26,172,223,86,70,24,8,142,125,198,255,216,71,115,235,43,83,235,199,137,73,206,238,42,67,8,
    193,84,40,156,124,20,53,53,71,227,121,93,221,169,120,126,237,194,85,178,210,19,123,15,185,28,216,210,87,178,57,47,27,171,170,254,69,
    241,31,226,238,245,27,228,108,173,96,205,130,154,17,142,146,169,168,132,140,8,25,178,66,52,28,77,174,24,138,77,149,19,167,117,83,205,
    125,231,97,82,49,242,114,121,133,73,177,199,227,137,231,213,85,199,112,173,117,154,54,5,191,124,165,225,118,51,231,206,212,176,177,124,
    231,210,192,39,171,143,227,187,119,159,3,251,246,226,127,223,199,211,174,158,132,245,130,124,59,229,155,54,96,24,6,183,26,125,92,94,
    4,108,26,133,179,164,8,89,150,113,228,219,153,156,154,98,104,248,19,22,107,6,154,117,21,179,179,6,121,121,185,72,146,132,44,43,56,75,
    138,150,62,138,152,151,74,191,13,53,22,57,57,54,36,9,126,68,102,176,219,114,17,66,160,40,50,165,73,192,139,95,158,136,219,53,221,207,
    59,121,209,213,73,255,192,16,173,109,157,177,231,102,132,184,217,232,75,126,131,186,174,11,183,219,45,82,17,239,94,119,11,33,132,80,
    23,26,244,156,151,166,236,215,36,132,16,252,47,241,11,2,228,2,236,233,5,147,117,0,0,0,0,73,69,78,68,174,66,96,130
    };

}
