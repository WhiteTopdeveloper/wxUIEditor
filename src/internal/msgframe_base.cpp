///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "msgframe_base.h"

#include <wx/mstream.h>  // memory stream classes

// Convert a data array into a wxImage
inline wxImage wxueImage(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

MsgFrameBase::MsgFrameBase(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style) :
    wxFrame(parent, id, title, pos, size, style)
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* menubar = new wxMenuBar();

    auto* menu_file = new wxMenu();
    auto* menu_item_saveas = new wxMenuItem(menu_file, wxID_SAVEAS, wxEmptyString);
    menu_item_saveas->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_FILE_SAVE_AS, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS, wxART_MENU))
#endif
    );
    menu_file->Append(menu_item_saveas);
    menu_file->AppendSeparator();
    auto* menu_item_clear = new wxMenuItem(menu_file, wxID_CLEAR, wxEmptyString);
    menu_item_clear->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_CUT, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_CUT, wxART_MENU))
#endif
    );
    menu_file->Append(menu_item_clear);
    auto* menu_item_hide = new wxMenuItem(menu_file, id_hide, "&Hide");
    menu_item_hide->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxBitmapBundle::FromBitmap(wxueImage(wxue_img::hide_png, sizeof(wxue_img::hide_png)))
#else
        wxBitmap(wxueImage(wxue_img::hide_png, sizeof(wxue_img::hide_png)))
#endif
    );
    menu_file->Append(menu_item_hide);
    menubar->Append(menu_file, "&File");

    auto* menu_view = new wxMenu();
    m_menu_item_warnings = new wxMenuItem(menu_view, id_warning_msgs, "Warnings", wxEmptyString, wxITEM_CHECK);
    m_menu_item_warnings->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_WARNING, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_WARNING, wxART_MENU))
#endif
    );
    menu_view->Append(m_menu_item_warnings);
    m_menu_item_events = new wxMenuItem(menu_view, id_event_msgs, "Events", wxEmptyString, wxITEM_CHECK);
    m_menu_item_events->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_TIP, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_TIP, wxART_MENU))
#endif
    );
    menu_view->Append(m_menu_item_events);
    m_menu_item_info = new wxMenuItem(menu_view, wxID_INFO, wxEmptyString, wxEmptyString, wxITEM_CHECK);
    m_menu_item_info->SetBitmap(
#if wxCHECK_VERSION(3, 1, 6)
        wxArtProvider::GetBitmapBundle(wxART_INFORMATION, wxART_MENU)
#else
        wxBitmap(wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_MENU))
#endif
    );
    menu_view->Append(m_menu_item_info);
    menubar->Append(menu_view, "&View");

    SetMenuBar(menubar);

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_notebook = new wxNotebook(this, wxID_ANY);
    m_notebook->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    parent_sizer->Add(m_notebook, wxSizerFlags(1).Expand().Border(wxALL));

    m_page_log = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_page_log, "Log");
    m_page_log->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* log_sizer = new wxBoxSizer(wxVERTICAL);

    m_textCtrl = new wxTextCtrl(m_page_log, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
        wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxHSCROLL);
    m_textCtrl->SetMinSize(wxSize(350, 300));
    log_sizer->Add(m_textCtrl, wxSizerFlags(1).Expand().Border(wxALL, 0));
    m_page_log->SetSizerAndFit(log_sizer);

    m_page_node = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_page_node, "Node");
    m_page_node->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* node_sizer = new wxBoxSizer(wxVERTICAL);

    auto* static_box_2 = new wxStaticBoxSizer(wxVERTICAL, m_page_node, "Selected Node");

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    m_txt_generator = new wxStaticText(static_box_2->GetStaticBox(), wxID_ANY, "Name:");
    box_sizer->Add(m_txt_generator, wxSizerFlags(1).Expand().Border(wxALL));

    auto* btn = new wxButton(static_box_2->GetStaticBox(), wxID_ANY, "Parent...");
    box_sizer->Add(btn, wxSizerFlags().Center().Border(wxALL));

    static_box_2->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    m_txt_type = new wxStaticText(static_box_2->GetStaticBox(), wxID_ANY, "Type:");
    static_box_2->Add(m_txt_type, wxSizerFlags().Border(wxALL));

    m_txt_memory = new wxStaticText(static_box_2->GetStaticBox(), wxID_ANY, "Memory:");
    static_box_2->Add(m_txt_memory, wxSizerFlags().Border(wxALL));

    m_hyperlink = new wxHyperlinkCtrl(static_box_2->GetStaticBox(), wxID_ANY, "wxWidgets Documentation",
        "https://docs.wxwidgets.org/trunk/");
    static_box_2->Add(m_hyperlink, wxSizerFlags().Expand().Border(wxALL));

    node_sizer->Add(static_box_2, wxSizerFlags().Expand().Border(wxALL));

    auto* static_box = new wxStaticBoxSizer(wxVERTICAL, m_page_node, "Memory Usage");

    m_txt_project = new wxStaticText(static_box->GetStaticBox(), wxID_ANY, "Project:");
    static_box->Add(m_txt_project, wxSizerFlags().Border(wxALL));

    m_txt_clipboard = new wxStaticText(static_box->GetStaticBox(), wxID_ANY, "Clipboard:");
    static_box->Add(m_txt_clipboard, wxSizerFlags().Border(wxALL));

    node_sizer->Add(static_box, wxSizerFlags().Expand().Border(wxALL));
    m_page_node->SetSizerAndFit(node_sizer);

    m_page_xrc = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_page_xrc, "XRC");
    m_page_xrc->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    m_scintilla = new wxStyledTextCtrl(m_page_xrc, wxID_ANY);
    {
        m_scintilla->SetLexer(wxSTC_LEX_XML);
        m_scintilla->SetReadOnly(true);
        m_scintilla->SetEOLMode(wxSTC_EOL_LF);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_scintilla->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetProperty("fold", "1");
        m_scintilla->SetMarginWidth(1, 16);
        m_scintilla->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
        m_scintilla->SetMarginMask(1, wxSTC_MASK_FOLDERS);
        m_scintilla->SetMarginSensitive(1, true);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_ARROWDOWN);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_ARROW);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_BACKGROUND);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_BACKGROUND);
        m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_BACKGROUND);
        m_scintilla->SetBackSpaceUnIndents(true);
    }
    box_sizer_3->Add(m_scintilla, wxSizerFlags(1).Expand().Border(wxALL));

    page_sizer->Add(box_sizer_3, wxSizerFlags(1).Expand().Border(wxALL));
    m_page_xrc->SetSizerAndFit(page_sizer);

    SetSizerAndFit(parent_sizer);

    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_CLOSE_WINDOW, &MsgFrameBase::OnClose, this);
    Bind(wxEVT_MENU, &MsgFrameBase::OnSaveAs, this, wxID_SAVEAS);
    Bind(wxEVT_MENU, &MsgFrameBase::OnClear, this, wxID_CLEAR);
    Bind(wxEVT_MENU, &MsgFrameBase::OnHide, this, id_hide);
    Bind(wxEVT_MENU, &MsgFrameBase::OnWarnings, this, id_warning_msgs);
    Bind(wxEVT_MENU, &MsgFrameBase::OnEvents, this, id_event_msgs);
    Bind(wxEVT_MENU, &MsgFrameBase::OnInfo, this, wxID_INFO);
    m_notebook->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, &MsgFrameBase::OnPageChanged, this);
    btn->Bind(wxEVT_BUTTON, &MsgFrameBase::OnParent, this);
}

namespace wxue_img
{

    const unsigned char hide_png[242] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,9,112,72,89,115,0,0,11,
    19,0,0,11,19,1,0,154,156,24,0,0,0,164,73,68,65,84,72,199,237,149,75,2,128,32,8,68,25,239,127,103,90,212,66,17,100,176,
    218,201,14,133,158,124,19,57,146,8,140,174,34,34,170,122,95,2,248,5,208,67,30,16,235,79,25,84,33,75,80,116,225,66,38,
    231,25,138,82,4,12,196,1,13,74,219,73,143,213,205,3,52,162,165,31,183,231,54,50,47,146,86,73,135,133,37,145,12,17,104,
    104,224,116,79,161,38,104,236,192,20,90,86,188,34,35,115,180,57,143,108,251,215,83,69,206,192,11,40,232,85,177,1,65,121,
    85,48,93,213,157,35,26,180,145,14,208,5,13,107,146,53,79,117,61,63,243,1,122,221,38,32,4,54,175,255,35,159,69,124,68,
    46,21,182,88,38,116,19,247,168,0,0,0,0,73,69,78,68,174,66,96,130
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
