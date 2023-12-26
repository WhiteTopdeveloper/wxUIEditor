///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#if defined(INTERNAL_TESTING)

#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "../wxui/ui_images.h"

#include "msgframe_base.h"

bool MsgFrameBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{

    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    if (!wxFrame::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* menubar = new wxMenuBar();

    auto* menu_file = new wxMenu();
    auto* menu_item_saveas = new wxMenuItem(menu_file, wxID_SAVEAS, wxEmptyString);
    menu_item_saveas->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_FILE_SAVE_AS, wxART_MENU));

    menu_file->Append(menu_item_saveas);
    menu_file->AppendSeparator();
    auto* menu_item_clear = new wxMenuItem(menu_file, wxID_CLEAR, wxEmptyString);
    menu_item_clear->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_CUT, wxART_MENU));

    menu_file->Append(menu_item_clear);
    auto* menu_item_hide = new wxMenuItem(menu_file, id_hide, "&Hide");
    menu_item_hide->SetBitmap(wxue_img::bundle_hide_png());
    menu_file->Append(menu_item_hide);
    menubar->Append(menu_file, "&File");

    auto* menu_view = new wxMenu();
    m_menu_item_warnings = new wxMenuItem(menu_view, id_warning_msgs, "Warnings", wxEmptyString, wxITEM_CHECK);
    m_menu_item_warnings->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_WARNING, wxART_MENU));

    menu_view->Append(m_menu_item_warnings);
    m_menu_item_events = new wxMenuItem(menu_view, id_event_msgs, "Events", wxEmptyString, wxITEM_CHECK);
    m_menu_item_events->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_TIP, wxART_MENU));

    menu_view->Append(m_menu_item_events);
    m_menu_item_info = new wxMenuItem(menu_view, wxID_INFO, wxEmptyString, wxEmptyString, wxITEM_CHECK);
    m_menu_item_info->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_INFORMATION, wxART_MENU));

    menu_view->Append(m_menu_item_info);
    menubar->Append(menu_view, "&View");

    SetMenuBar(menubar);

    m_tool_bar = CreateToolBar();
    m_tool_bar->AddTool(wxID_SAVEAS, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_FILE_SAVE_AS, wxART_TOOLBAR));

    m_tool_bar->AddSeparator();
    auto* tool_item_clear = m_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_CUT,
        wxART_TOOLBAR));

    m_tool_bar->AddTool(id_hide, wxEmptyString, wxue_img::bundle_hide_png());

    m_tool_bar->Realize();

    m_aui_notebook = new wxAuiNotebook(this, wxID_ANY);
    m_aui_notebook->SetArtProvider(new wxAuiGenericTabArt());
    m_aui_notebook->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    m_page_log = new wxPanel(m_aui_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_aui_notebook->AddPage(m_page_log, "Log");
    m_page_log->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* log_sizer = new wxBoxSizer(wxVERTICAL);

    m_textCtrl = new wxTextCtrl(m_page_log, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
        wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxHSCROLL);
    m_textCtrl->SetMinSize(wxSize(350, 300));
    log_sizer->Add(m_textCtrl, wxSizerFlags(1).Expand().Border(wxALL, 0));
    m_page_log->SetSizerAndFit(log_sizer);

    m_page_node = new wxPanel(m_aui_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_aui_notebook->AddPage(m_page_node, "Node");
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

    m_page_xrc = new wxPanel(m_aui_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_aui_notebook->AddPage(m_page_xrc, "XRC");
    m_page_xrc->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    m_scintilla = new wxStyledTextCtrl(m_page_xrc);
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

    Centre(wxBOTH);

    // Event handlers
    m_aui_notebook->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &MsgFrameBase::OnPageChanged, this);
    btn->Bind(wxEVT_BUTTON, &MsgFrameBase::OnParent, this);
    Bind(wxEVT_CLOSE_WINDOW, &MsgFrameBase::OnClose, this);
    Bind(wxEVT_MENU, &MsgFrameBase::OnSaveAs, this, wxID_SAVEAS);
    Bind(wxEVT_MENU, &MsgFrameBase::OnClear, this, wxID_CLEAR);
    Bind(wxEVT_MENU, &MsgFrameBase::OnHide, this, id_hide);
    Bind(wxEVT_MENU, &MsgFrameBase::OnWarnings, this, id_warning_msgs);
    Bind(wxEVT_MENU, &MsgFrameBase::OnEvents, this, id_event_msgs);
    Bind(wxEVT_MENU, &MsgFrameBase::OnInfo, this, wxID_INFO);
    Bind(wxEVT_TOOL, &MsgFrameBase::OnSaveAs, this, wxID_SAVEAS);
    Bind(wxEVT_TOOL, &MsgFrameBase::OnClear, this, tool_item_clear->GetId());
    Bind(wxEVT_TOOL, &MsgFrameBase::OnHide, this, id_hide);

    return true;
}

#endif  // defined(INTERNAL_TESTING)

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
