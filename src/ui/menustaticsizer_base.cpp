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

#include "menustaticsizer_base.h"

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
    extern const unsigned char wxStaticBoxSizer_png[215];
    extern const unsigned char wxStaticCheckBoxSizer_png[357];
    extern const unsigned char wxStaticRadioBtnSizer_png[383];
}

MenuStaticSizer::MenuStaticSizer() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxStaticBoxSizer, wxString::FromUTF8("Insert wxStaticBoxSizer"));
    menu_item->SetBitmap(GetImageFromArray(wxue_img::wxStaticBoxSizer_png, sizeof(wxue_img::wxStaticBoxSizer_png)));

    auto menu_item_2 = Append(gen_StaticCheckboxBoxSizer, wxString::FromUTF8("Insert CheckBox wxStaticBoxSizer"));
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::wxStaticCheckBoxSizer_png, sizeof(wxue_img::wxStaticCheckBoxSizer_png)));

    auto menu_item_3 = Append(gen_StaticRadioBtnBoxSizer, wxString::FromUTF8("Insert RadioButton wxStaticBoxSizer"));
    menu_item_3->SetBitmap(GetImageFromArray(wxue_img::wxStaticRadioBtnSizer_png, sizeof(wxue_img::wxStaticRadioBtnSizer_png)));
}

namespace wxue_img
{

    const unsigned char wxStaticBoxSizer_png[215] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,121,73,68,65,84,56,203,237,84,209,14,128,32,8,60,157,31,126,127,78,
    111,141,46,165,172,108,181,121,155,3,133,29,114,56,129,151,96,110,193,89,200,153,73,236,52,121,173,88,148,179,67,2,0,146,107,34,73,144,
    132,223,123,91,203,81,144,76,80,226,70,251,145,175,164,6,0,185,213,69,135,95,69,17,225,236,206,228,147,43,88,162,96,231,196,55,151,202,
    163,222,237,48,226,114,212,210,99,196,83,227,169,241,223,53,190,170,111,72,44,127,242,119,177,0,167,194,50,161,147,242,244,148,0,0,0,
    0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxStaticCheckBoxSizer_png[357] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,1,7,73,68,65,84,56,203,237,148,61,106,133,64,20,133,191,121,40,8,22,
    209,34,144,50,38,157,146,128,59,112,9,238,192,13,36,15,45,173,156,5,184,2,27,183,226,42,82,72,32,27,16,180,179,188,169,18,94,212,68,
    95,126,200,35,228,131,129,225,114,231,156,203,225,50,138,9,121,158,75,215,117,188,199,237,77,192,253,62,85,172,96,76,11,227,56,226,251,
    62,113,28,191,169,15,195,192,48,12,92,156,159,177,133,221,82,209,113,28,60,207,83,47,199,113,28,178,44,163,105,26,44,203,218,36,108,
    0,104,173,229,112,50,128,40,138,36,73,18,60,207,35,12,67,68,132,162,40,152,246,47,161,181,86,179,198,52,77,165,174,107,209,90,139,105,
    154,98,219,182,68,81,36,125,223,11,192,211,227,195,154,168,44,102,124,232,90,85,149,180,109,75,89,150,202,117,93,142,97,38,124,125,117,
    9,64,93,215,2,16,4,193,235,253,75,194,119,251,116,245,145,192,204,72,129,250,80,120,169,233,51,70,59,126,8,99,235,4,223,34,124,210,81,
    252,103,252,151,162,56,54,134,223,219,138,181,207,251,100,120,6,125,77,97,75,88,209,132,146,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxStaticRadioBtnSizer_png[383] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,1,33,73,68,65,84,56,203,237,148,49,75,196,64,16,133,191,61,114,218,40,
    254,5,69,45,108,4,21,4,93,174,144,128,149,117,192,226,10,33,248,31,210,45,114,36,127,34,165,32,44,216,89,9,233,69,80,193,86,193,206,
    224,17,177,19,245,192,177,56,44,238,220,152,8,138,135,248,202,183,179,111,103,222,60,86,81,130,236,248,72,174,174,111,56,187,184,4,96,
    101,105,145,249,185,25,252,205,45,69,13,168,50,209,253,131,67,180,214,248,190,223,231,178,12,197,43,254,70,139,233,217,133,74,113,207,
    69,158,156,158,163,181,38,12,67,149,36,137,0,68,81,164,138,110,46,212,132,7,96,140,25,184,112,155,223,177,174,91,88,107,37,8,2,0,172,
    181,210,108,142,225,170,31,134,49,70,57,11,59,157,61,73,211,84,0,226,56,150,56,142,5,160,232,230,82,213,245,187,150,211,138,181,213,
    101,138,251,7,138,110,46,19,147,83,0,236,134,59,242,252,244,72,175,247,82,203,138,134,139,252,108,243,117,22,231,236,88,160,63,234,118,
    123,128,31,31,62,255,24,47,85,153,10,85,18,195,50,184,30,107,240,67,240,234,118,240,45,194,35,109,197,191,199,127,201,138,175,218,240,
    123,169,168,250,188,71,6,111,141,113,108,231,56,214,204,252,0,0,0,0,73,69,78,68,174,66,96,130
    };

}
