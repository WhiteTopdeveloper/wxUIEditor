///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/accel.h>
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "images.h"

#include "mainframe.h"

#include <wx/mstream.h>  // memory stream classes

// Convert a data array into a wxImage
inline wxImage wxueImage(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

namespace wxue_img
{
    // Ainsi ça se passe.png
    extern const unsigned char Ainsi_c3_a_se_passe_png[148];
    extern const unsigned char debug_32_png[1701];
    extern const unsigned char english_png[541];
    extern const unsigned char wxNotebook_png[177];
    extern const unsigned char wxPython_1_5x_png[765];
    extern const unsigned char wxPython_2x_png[251];
    extern const unsigned char wxPython_png[399];
}

bool MainFrame::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{

    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    if (!wxFrame::Create(parent, id, title, pos, size, style, name))
        return false;

    splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
    splitter->SetSashGravity(0.0);
    splitter->SetMinimumPaneSize(150);
    splitter->SetMinSize(ConvertDialogToPixels(wxSize(200, 200)));

    propertyGridManager = new wxPropertyGridManager(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxPG_AUTO_SORT|wxPG_BOLD_MODIFIED|wxPG_SPLITTER_AUTO_CENTER|wxPG_DESCRIPTION|wxPG_TOOLBAR|wxPG_NO_INTERNAL_BORDER);
    propertyGridManager->SetExtraStyle(wxPG_EX_MODE_BUTTONS);

    propertyGridPage = propertyGridManager->AddPage("Animal Page", wxue_img::bundle_wxPython_1_5x_png());

    propertyGridItem_7 = propertyGridPage->Append(new wxPropertyCategory("Pets", "Pets"));

    propertyGridItem_2 = propertyGridPage->Append(new wxStringProperty("dog", "Woof!"));

    propertyGridItem = propertyGridPage->Append(new wxStringProperty("cat", "Meow!"));

    propertyGridItem_5 = propertyGridPage->Append(new wxPropertyCategory("Big Animals", "Big Animals"));

    propertyGridItem_8 = propertyGridPage->Append(new wxStringProperty("horses", wxEmptyString));

    propertyGridPage_2 = propertyGridManager->AddPage("Number Page", wxue_img::bundle_english_png());

    propertyGridItem_6 = propertyGridPage_2->Append(new wxPropertyCategory("Numbers", "Numbers"));

    propertyGridItem_3 = propertyGridPage_2->Append(new wxIntProperty("1", wxEmptyString));

    propertyGridItem_4 = propertyGridPage_2->Append(new wxIntProperty("2", wxEmptyString));

    grid = new wxGrid(splitter, wxID_ANY);
    {
        grid->CreateGrid(5, 5);
        grid->EnableDragGridSize(false);
        grid->SetMargins(0, 0);
        grid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
        grid->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        grid->SetColLabelSize(wxGRID_AUTOSIZE);
        grid->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        grid->SetRowLabelSize(wxGRID_AUTOSIZE);
    }
    splitter->SplitHorizontally(propertyGridManager, grid);

    auto* menubar = new wxMenuBar();

    menu = new wxMenu();
    auto* menuQuit = new wxMenuItem(menu, wxID_EXIT);
    {
        wxAcceleratorEntry entry;
        if (entry.FromString("ALT+X"))
            menuQuit->AddExtraAccel(entry);
    }

    menuQuit->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_QUIT, wxART_MENU));

    menu->Append(menuQuit);
    menubar->Append(menu, wxGetStockLabel(wxID_FILE));

    auto* menuDialogs = new wxMenu();
    auto* menu_item_3 = new wxMenuItem(menuDialogs, wxID_ANY, "MainTestDlg");
    menu_item_3->SetBitmap(wxue_img::bundle_debug_32_png());

    menuDialogs->Append(menu_item_3);
    auto* menu_item_4 = new wxMenuItem(menuDialogs, wxID_ANY, "BookTestDlg");
    menu_item_4->SetBitmap(wxue_img::bundle_wxNotebook_png());

    menuDialogs->Append(menu_item_4);
    auto* menu_item_2 = new wxMenuItem(menuDialogs, wxID_ANY, "PythonDlg");
    {
        wxVector<wxBitmap> bitmaps;
        bitmaps.push_back(wxueImage(wxue_img::wxPython_png, sizeof(wxue_img::wxPython_png)));
        bitmaps.push_back(wxueImage(wxue_img::wxPython_1_5x_png, sizeof(wxue_img::wxPython_1_5x_png)));
        bitmaps.push_back(wxueImage(wxue_img::wxPython_2x_png, sizeof(wxue_img::wxPython_2x_png)));
        menu_item_2->SetBitmap(wxBitmapBundle::FromBitmaps(bitmaps));
    }

    menuDialogs->Append(menu_item_2);
    auto* menu_tools_dlg2 = new wxMenuItem(menuDialogs, wxID_ANY, "Tools Dialog",
        "Dialog for testing different types of toolbars", wxITEM_NORMAL);
    menu_tools_dlg2->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::wxToolBar_png, sizeof(wxue_img::wxToolBar_png))));

    menuDialogs->Append(menu_tools_dlg2);
    auto* menuItem3 = new wxMenuItem(menuDialogs, wxID_ANY, "Wizard");
    menuItem3->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::wxWizard_png, sizeof(wxue_img::wxWizard_png))));

    menuDialogs->Append(menuItem3);
    menuDialogs->AppendSeparator();
    auto* menuItem_2 = new wxMenuItem(menuDialogs, wxID_ANY, "Common Controls...", "Common controls", wxITEM_NORMAL);
    menuItem_2->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_TIP, wxART_MENU));

    menuDialogs->Append(menuItem_2);
    menuDialogs->AppendSeparator();

    auto* submenu = new wxMenu();
    auto* menu_item_5 = new wxMenuItem(submenu, wxID_ANY, "DlgIssue_956");
    menu_item_5->SetBitmap(wxue_img::bundle_debug_32_png());

    submenu->Append(menu_item_5);
    auto* menu_item_6 = new wxMenuItem(submenu, wxID_ANY, "DlgIssue_960");
    menu_item_6->SetBitmap(wxue_img::bundle_Ainsi_c3_a_se_passe_png());

    submenu->Append(menu_item_6);
    auto* submenu_item = menuDialogs->AppendSubMenu(submenu, "Issue Dialogs");
    submenu_item->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::wxDialog_png, sizeof(wxue_img::wxDialog_png))));
    menubar->Append(menuDialogs, "&Dialogs");

    SetMenuBar(menubar);

    m_toolBar = CreateToolBar();

    auto* tool_dropdown = m_toolBar->AddTool(wxID_ANY, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_EXECUTABLE_FILE,
        wxART_MENU), wxEmptyString, wxITEM_DROPDOWN);
    auto* tool_dropdown_menu = new wxMenu;
    auto* menu_item = new wxMenuItem(tool_dropdown_menu, wxID_ANY, "Wizard...");
    menu_item->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_FIND, wxART_MENU));

    tool_dropdown_menu->Append(menu_item);
    auto* menu_tools_dlg = new wxMenuItem(tool_dropdown_menu, wxID_ANY, "Tools Dialog",
        "Dialog for testing different types of toolbars", wxITEM_NORMAL);
    tool_dropdown_menu->Append(menu_tools_dlg);
    tool_dropdown->SetDropdownMenu(tool_dropdown_menu);
    auto* tool_4 = m_toolBar->AddTool(wxID_ANY, "MainTestDlg", wxue_img::bundle_debug_32_png());

    auto* tool_5 = m_toolBar->AddTool(wxID_ANY, "BookTestDlg", wxue_img::bundle_wxNotebook_png());

    m_toolBar->AddSeparator();
    auto* tool_3 = m_toolBar->AddTool(wxID_ANY, "PythonDlg", wxue_img::bundle_wxPython_1_5x_png());

    m_toolBar->AddStretchableSpace();

    auto* tool_2 = m_toolBar->AddTool(wxID_ANY, "Common Controls...", wxArtProvider::GetBitmapBundle(wxART_TIP, wxART_TOOLBAR));

    m_toolBar->Realize();

    m_statusBar = CreateStatusBar(2);
    {
        const int sb_field_widths[2] = {100, -1};
        m_statusBar->SetStatusWidths(2, sb_field_widths);
        const int sb_field_styles[2] = {wxSB_FLAT, wxSB_FLAT};
        m_statusBar->SetStatusStyles(2, sb_field_styles);
    }

    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_MENU, &MainFrame::OnQuit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnMainTestDlg, this, menu_item_3->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnBookTestDlg, this, menu_item_4->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnPythonDlg, this, menu_item_2->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnToolsDlg, this, menu_tools_dlg2->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnWizard, this, menuItem3->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnCommonDialog, this, menuItem_2->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnDlgIssue_956, this, menu_item_5->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnDlgIssue_960, this, menu_item_6->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnWizard, this, menu_item->GetId());
    Bind(wxEVT_MENU, &MainFrame::OnToolsDlg, this, menu_tools_dlg->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnMainTestDlg, this, tool_4->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnBookTestDlg, this, tool_5->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnPythonDlg, this, tool_3->GetId());
    Bind(wxEVT_TOOL, &MainFrame::OnCommonDialog, this, tool_2->GetId());

    return true;
}

namespace wxue_img
{

    const unsigned char wxDialog_png[636] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,
        0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,2,46,73,68,65,84,56,203,181,149,65,107,19,81,16,199,127,187,217,46,137,169,
        105,83,208,131,232,197,107,192,226,169,7,191,128,199,30,122,211,66,17,5,253,6,94,68,68,16,252,0,94,42,42,222,122,
        216,67,234,41,7,233,61,34,74,48,17,4,111,193,92,114,73,147,26,105,179,111,198,195,190,221,108,146,110,155,82,58,
        176,204,123,59,239,205,155,249,207,127,222,131,11,18,39,30,188,218,237,168,0,168,130,2,42,168,234,196,7,160,98,
        255,99,215,136,34,170,44,184,138,43,35,158,111,222,114,0,92,128,23,59,191,180,176,0,225,247,109,138,190,67,216,
        120,75,49,159,195,252,120,143,52,63,112,185,232,195,207,143,148,22,125,150,74,121,150,75,5,202,165,2,229,165,34,
        43,229,69,252,205,199,56,247,158,80,44,149,120,250,238,155,2,120,0,234,122,236,127,217,6,136,116,101,43,153,83,
        217,162,111,199,253,191,163,140,124,35,233,255,51,140,140,51,54,61,219,249,173,215,87,252,76,176,156,105,15,199,
        138,114,116,20,210,238,236,243,250,209,109,199,3,200,231,224,206,213,206,185,11,214,117,111,114,56,56,32,129,34,
        142,39,168,214,216,88,191,155,232,88,42,171,107,167,58,109,53,234,92,242,29,188,28,99,199,216,138,167,157,6,213,
        90,242,239,79,103,190,108,68,5,35,66,194,10,75,158,115,75,14,16,35,227,136,213,158,18,71,152,214,0,189,110,123,
        46,199,161,8,146,142,88,84,207,132,103,214,154,208,72,18,164,155,198,56,222,16,235,160,90,75,190,105,167,211,107,
        34,144,73,58,52,130,34,106,102,90,141,58,149,213,53,90,141,250,12,28,233,234,103,173,17,219,238,99,40,82,24,199,
        27,78,163,86,6,47,16,77,21,207,24,51,97,94,190,114,99,102,75,92,192,147,108,32,152,208,164,89,49,75,183,207,141,
        201,123,161,185,23,176,117,127,227,68,155,24,65,109,144,238,52,221,230,145,188,111,47,26,135,164,211,162,204,199,
        29,225,29,183,177,215,109,211,220,11,200,178,125,173,5,89,247,80,34,94,86,84,113,218,103,181,77,56,238,15,134,180,
        135,215,80,149,136,210,26,245,189,147,162,145,216,58,68,201,198,175,140,157,171,146,115,29,134,135,3,122,7,102,
        242,170,126,240,242,147,138,68,79,141,138,32,106,181,49,72,124,160,229,188,138,36,205,16,209,75,163,23,77,148,221,
        55,15,29,46,82,254,3,136,174,81,14,10,69,149,111,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxToolBar_png[554] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,
        0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,1,220,73,68,65,84,56,203,237,148,49,104,19,81,24,199,127,175,105,114,114,
        54,5,131,222,34,233,34,26,132,6,4,135,12,182,16,194,27,196,65,167,182,131,147,14,21,75,160,29,156,157,37,148,116,
        144,14,5,151,10,33,160,139,96,19,44,152,161,231,32,7,182,165,54,233,150,156,58,88,10,210,34,151,114,141,71,121,
        14,105,26,143,107,221,50,20,250,223,222,123,223,251,127,255,255,247,125,239,193,57,142,32,114,185,156,234,9,113,
        181,90,237,9,113,95,175,74,209,15,32,101,138,104,212,96,105,233,3,0,74,41,132,16,0,120,158,231,187,48,50,50,76,
        40,20,33,147,121,16,32,179,44,11,33,4,165,82,137,254,233,233,199,108,111,207,224,56,55,73,167,239,2,135,192,30,
        112,9,219,254,193,250,250,55,154,205,230,241,229,161,33,208,180,139,188,190,243,61,64,124,235,171,198,254,190,211,
        81,220,0,46,16,141,126,98,117,117,6,104,1,117,224,26,227,227,115,167,24,85,132,198,22,56,124,251,196,183,59,56,
        248,11,77,219,107,19,11,113,5,240,128,235,52,26,63,169,84,62,3,183,129,247,216,246,85,138,197,34,186,174,163,148,
        66,74,217,233,57,0,161,177,5,127,190,66,166,91,99,165,90,128,224,224,160,73,62,111,83,171,153,128,9,192,192,0,44,
        47,127,1,96,99,3,164,172,162,20,140,78,153,60,127,89,8,248,24,157,50,249,56,151,236,148,162,5,244,49,59,187,131,
        227,188,33,157,14,26,175,215,33,149,122,218,214,218,22,203,159,196,195,255,79,133,16,151,89,92,244,216,218,42,144,
        72,4,3,118,119,33,28,190,207,228,228,51,92,215,69,29,77,125,254,81,242,56,38,30,143,147,205,102,217,49,238,117,
        137,45,171,129,174,191,34,153,252,125,98,230,205,205,27,204,207,191,192,117,93,159,226,127,97,24,134,143,180,211,
        5,165,105,16,137,156,108,201,52,215,8,135,253,135,19,19,195,212,106,221,117,44,22,67,74,73,165,242,142,149,149,
        181,179,250,164,203,229,242,249,31,127,70,241,23,223,2,154,75,171,133,77,36,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char wxWizard_png[1047] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,
        0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,3,201,73,68,65,84,56,203,213,149,77,104,92,85,20,199,127,239,35,51,239,37,
        169,121,147,168,157,39,86,140,186,153,224,38,1,21,186,12,130,18,45,162,221,212,70,138,8,130,80,139,213,166,136,
        109,55,82,65,4,55,74,7,68,90,63,105,23,162,213,133,212,6,101,236,198,148,22,59,145,104,141,160,109,218,164,164,
        77,173,153,230,99,50,147,153,119,207,113,241,222,76,29,180,117,229,194,11,135,199,123,247,190,223,57,247,156,123,
        254,23,254,111,195,58,241,203,239,122,244,212,21,186,186,3,86,106,138,0,168,130,2,42,168,106,139,1,168,36,223,73,
        214,136,34,170,180,217,138,45,117,30,190,47,196,61,250,195,60,126,167,15,40,126,91,211,31,0,155,178,39,153,26,43,
        114,226,174,173,36,200,107,33,233,63,133,9,82,175,243,249,119,51,184,106,187,148,87,133,114,109,21,43,1,54,70,112,
        112,15,217,129,144,133,242,179,55,216,115,235,171,68,134,186,177,112,141,40,65,187,77,167,231,52,39,183,140,62,
        68,117,96,43,222,122,143,204,197,34,47,100,190,164,196,97,190,185,245,195,127,201,172,82,171,9,51,75,224,122,14,
        12,220,217,193,189,235,124,140,196,211,87,71,251,201,242,26,213,245,125,120,100,224,179,231,201,100,246,177,161,
        191,235,134,88,215,177,88,92,169,243,197,210,50,174,5,180,167,44,122,58,29,230,126,252,138,224,224,30,170,57,168,
        14,246,225,5,111,2,5,200,121,84,167,242,4,175,231,25,239,125,2,175,119,128,142,187,115,45,80,47,237,177,166,167,
        27,210,22,174,3,46,170,136,10,43,149,26,149,201,60,1,16,48,69,149,176,245,199,201,248,153,203,132,84,67,152,45,
        87,254,6,6,168,27,193,136,224,42,74,35,187,157,15,30,100,226,158,243,220,241,201,219,100,57,76,245,145,145,120,
        226,200,69,14,76,6,28,9,250,248,244,241,103,72,3,25,11,210,158,223,2,47,47,45,196,5,52,130,173,34,68,18,39,87,36,
        57,171,7,14,113,188,186,3,175,240,51,99,91,139,28,206,79,146,43,85,233,239,203,177,109,231,78,124,223,39,157,78,
        95,55,215,34,130,45,170,68,73,213,20,139,116,218,163,62,49,205,253,207,189,74,97,95,72,95,239,16,195,244,178,113,
        114,138,227,133,35,244,134,33,35,35,35,68,81,116,93,168,138,96,163,10,18,71,235,182,185,100,179,107,241,125,159,
        114,185,28,175,28,222,200,194,220,56,0,197,98,145,226,88,129,76,38,195,246,23,95,98,97,97,177,197,34,177,154,93,
        105,171,10,34,2,8,41,215,161,221,247,72,181,57,160,17,125,147,227,148,188,28,142,5,23,166,207,1,80,24,139,225,97,
        24,178,123,247,46,92,91,91,204,24,19,131,27,80,219,118,168,172,70,204,254,81,99,230,74,141,11,87,234,148,190,191,
        196,154,174,91,40,93,93,164,30,25,166,206,158,105,194,11,133,2,65,16,240,206,187,251,57,51,23,177,88,181,227,84,
        36,167,204,54,198,64,44,61,76,95,174,113,232,219,18,251,143,206,179,127,116,158,247,191,46,113,250,124,5,85,105,
        230,176,1,47,22,139,113,166,134,135,249,233,228,40,167,207,149,155,221,103,34,131,173,162,72,82,188,180,11,183,
        117,59,172,187,57,182,219,123,108,58,60,11,249,11,24,224,212,196,111,12,14,14,18,134,33,217,108,150,161,161,33,
        46,255,90,72,148,15,212,24,92,21,193,24,165,188,82,161,231,38,155,13,15,116,54,165,203,182,237,70,179,210,230,94,
        211,146,181,1,124,244,193,123,188,252,202,14,242,249,60,0,79,111,121,42,6,39,114,106,55,36,208,177,33,229,66,202,
        85,82,174,69,202,181,112,44,5,49,212,86,43,44,45,151,169,213,163,216,162,216,246,238,125,131,241,241,113,54,111,
        222,68,45,138,48,81,132,149,4,229,46,46,173,112,246,82,26,177,172,164,65,4,213,216,153,168,52,85,81,164,138,72,
        67,149,147,5,10,143,62,185,157,99,197,89,80,197,177,45,86,86,13,87,151,77,124,131,188,245,241,49,218,59,124,196,
        72,114,192,21,21,65,52,121,26,131,52,28,66,236,92,4,36,222,122,92,3,141,47,30,81,118,109,123,236,191,187,243,254,
        4,61,95,30,87,232,10,12,187,0,0,0,0,73,69,78,68,174,66,96,130
    };

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
// Purpose:   Main Window
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true forces the frame to close
    Close(true);
}
