////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "navtoolbar_base.h"

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
    extern const unsigned char nav_coll_expand_png[316];
    extern const unsigned char nav_collapse_png[299];
    extern const unsigned char nav_expand_png[487];
    extern const unsigned char nav_movedown_png[584];
    extern const unsigned char nav_moveleft_png[645];
    extern const unsigned char nav_moveright_png[551];
    extern const unsigned char nav_moveup_png[560];
}

NavToolbar::NavToolbar(wxWindow* parent, wxWindowID id, 
        const wxPoint& pos, const wxSize& size, long style) :
    wxToolBar(parent, id, pos, size, style)
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    AddTool(id_NavCollExpand, wxEmptyString, GetImageFromArray(wxue_img::nav_coll_expand_png, sizeof(wxue_img::nav_coll_expand_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Collapse siblings, expand children", "Expand selected item, collapse all other items at the same level");

    AddTool(id_NavExpand, wxEmptyString, GetImageFromArray(wxue_img::nav_expand_png, sizeof(wxue_img::nav_expand_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Expand all children", "Expand selected item and all of it's sub-items");

    AddTool(id_NavCollapse, wxEmptyString, GetImageFromArray(wxue_img::nav_collapse_png, sizeof(wxue_img::nav_collapse_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Collapse all siblings", "Collapse selected item and all items at the same level");

    AddSeparator();

    AddTool(id_NavMoveLeft, wxEmptyString, GetImageFromArray(wxue_img::nav_moveleft_png, sizeof(wxue_img::nav_moveleft_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Move Left", "Move the selected item left");

    AddTool(id_NavMoveUp, wxEmptyString, GetImageFromArray(wxue_img::nav_moveup_png, sizeof(wxue_img::nav_moveup_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Move Up", "Move the selected item up");

    AddTool(id_NavMoveDown, wxEmptyString, GetImageFromArray(wxue_img::nav_movedown_png, sizeof(wxue_img::nav_movedown_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Move Down", "Move the selected item down");

    AddTool(id_NavMoveRight, wxEmptyString, GetImageFromArray(wxue_img::nav_moveright_png, sizeof(wxue_img::nav_moveright_png)), wxNullBitmap, wxITEM_NORMAL, 
            "Move Right", "Move the selected item right");

}

namespace wxue_img
{

    const unsigned char nav_coll_expand_png[316] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,0,238,73,68,65,84,56,203,213,145,59,74,3,97,20,133,191,255,53,243,59,26,145,116,162,98,149,34,130,43,176,16,27,247,
    144,133,100,1,150,198,13,4,44,172,45,220,70,176,18,11,147,20,58,149,24,240,53,14,132,140,76,204,204,181,176,177,26,209,96,145,175,60,
    247,194,61,247,28,88,120,20,192,193,233,190,212,215,163,47,197,10,214,106,156,49,56,99,176,90,163,52,32,80,148,130,17,79,252,114,207,
    85,124,195,91,59,85,22,224,33,25,145,249,21,0,124,20,178,28,122,162,32,0,28,136,70,149,37,249,108,74,50,73,25,60,199,60,141,199,188,
    231,31,139,16,208,201,229,145,116,175,143,165,106,71,207,123,196,86,13,31,211,87,38,62,248,185,198,239,180,206,91,2,48,43,166,236,110,
    236,16,58,205,109,50,196,6,5,0,221,195,11,85,233,160,55,236,1,176,189,182,133,9,51,196,229,244,71,119,172,214,220,239,255,107,118,54,
    101,239,172,241,247,16,107,86,145,165,75,252,107,11,115,243,9,198,7,71,251,96,211,148,187,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char nav_collapse_png[299] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,0,221,73,68,65,84,56,203,237,210,189,77,195,64,0,64,225,119,63,62,159,108,44,100,138,115,2,200,72,180,20,12,192,20,
    76,65,149,17,216,136,146,5,88,33,66,84,56,13,63,145,176,177,35,140,129,35,200,71,65,193,8,80,228,27,224,85,15,54,254,158,0,152,93,206,
    194,226,249,150,110,104,145,128,18,130,195,201,1,233,174,64,32,24,59,77,221,47,137,227,8,27,27,92,234,40,243,146,179,163,115,161,1,174,
    151,115,118,166,9,211,34,71,107,73,164,20,40,143,95,75,132,4,50,79,150,102,168,96,169,154,59,46,230,87,156,30,159,0,160,1,30,218,71,
    222,236,22,54,137,73,99,75,98,12,16,65,144,136,113,196,127,125,210,14,43,110,234,138,167,190,231,221,175,105,63,154,223,64,117,191,192,
    213,142,64,64,41,137,137,20,69,145,99,202,151,159,88,147,179,26,94,217,211,5,251,219,19,140,83,12,99,183,25,224,223,248,6,159,151,67,
    119,36,204,18,35,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char nav_expand_png[487] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,1,153,73,68,65,84,56,203,181,146,189,110,211,80,24,134,159,115,142,255,176,9,36,12,206,95,21,148,210,1,196,80,33,38,
    212,27,96,69,48,178,51,245,10,16,92,6,87,128,152,88,64,72,8,137,133,133,157,170,234,68,12,8,146,160,38,56,166,137,147,28,59,245,97,96,
    232,18,35,34,196,59,126,63,143,62,189,223,11,255,40,81,214,120,27,189,54,31,146,247,44,139,25,183,219,247,184,217,220,91,59,107,149,
    1,222,124,121,193,141,107,91,128,195,203,79,207,74,47,40,5,124,142,35,58,243,11,0,12,79,6,155,3,180,62,101,178,152,1,2,157,229,165,0,
    185,174,88,125,232,153,60,91,49,213,11,102,122,78,150,229,236,62,105,152,82,19,247,95,237,155,232,199,71,38,105,140,4,148,16,108,55,
    46,19,180,4,2,65,49,177,24,77,135,184,174,141,231,58,132,65,72,167,214,225,193,245,71,194,2,56,28,30,112,169,233,211,172,215,176,44,
    137,173,20,40,141,206,37,66,2,21,77,37,168,160,140,71,111,252,149,231,7,239,184,179,187,119,230,65,63,30,48,247,206,227,249,46,129,235,
    225,59,14,96,131,145,136,162,64,175,50,226,52,225,104,212,227,120,58,101,161,115,226,229,248,12,208,251,22,17,142,66,12,6,165,36,142,
    173,168,215,107,56,157,147,223,176,113,141,36,157,209,182,234,108,93,108,224,132,138,180,152,148,7,73,222,23,166,219,109,177,115,203,
    167,234,159,35,58,92,48,136,143,233,63,254,41,254,234,11,197,83,35,116,158,113,90,20,56,150,162,48,171,181,203,127,204,65,154,47,233,
    39,48,207,114,18,173,55,15,146,20,5,189,239,49,74,10,170,203,234,102,65,2,184,123,181,77,43,11,232,154,29,182,237,43,252,55,253,2,205,
    176,155,109,99,22,185,169,0,0,0,0,73,69,78,68,174,66,96,130
    };

}
