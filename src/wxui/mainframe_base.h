///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/event.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/toolbar.h>

class NavigationPanel;

namespace wxue_img
{
    // ../art_src/expand.svg
    extern const unsigned char expand_svg[648];
    // ../art_src/hidden.svg
    extern const unsigned char hidden_svg[1993];
    // ../art_src/magnify.svg
    extern const unsigned char magnify_svg[4117];
    // ../art_src/save.svg
    extern const unsigned char save_svg[1064];
}

class MainFrameBase : public wxFrame
{
public:
    enum
    {
        id_AlignBottom = wxID_HIGHEST + 1,
        id_AlignCenterHorizontal,
        id_AlignCenterVertical,
        id_AlignLeft,
        id_AlignRight,
        id_AlignTop,
        id_AppendCrafter,
        id_AppendDialogBlocks,
        id_AppendFormBuilder,
        id_AppendGlade,
        id_AppendSmith,
        id_AppendWinRes,
        id_AppendXRC,
        id_BorderBottom,
        id_BorderLeft,
        id_BorderRight,
        id_BorderTop,
        id_DifferentProject,
        id_Expand,
        id_GenerateCode,
        id_Magnify,
        id_MoveDown,
        id_MoveLeft,
        id_MoveRight,
        id_MoveUp,
        id_NewProject,
        id_OpenProject,
        id_PreferencesDlg,
        id_PreviewForm,
        id_SaveProjectAs,
        id_ShowHidden,
        id_insert_widget
    };

    MainFrameBase() {}
    MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxSize(1000, 1000), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL,
        const wxString &name = wxFrameNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }
    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxSize(1000, 1000), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL,
        const wxString &name = wxFrameNameStr);

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendCrafter(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendDialogBlocks(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendFormBuilder(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendGlade(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendSmith(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAppendXRC(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowseDocs(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowsePython(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowseRuby(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChangeAlignment(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChangeBorder(wxCommandEvent& event) { event.Skip(); }
    virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
    virtual void OnCopy(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCut(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDelete(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDifferentProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDuplicate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEditCustomIds(wxCommandEvent& event) { event.Skip(); }
    virtual void OnFindDialog(wxCommandEvent& event) { event.Skip(); }
    virtual void OnGenerateCode(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImportWindowsResource(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInsertWidget(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOpenProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPaste(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPreferencesDlg(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPreviewXrc(wxCommandEvent& event) { event.Skip(); }
    virtual void OnReloadProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveAsProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnToggleExpandLayout(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateBrowseDocs(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnUpdateBrowsePython(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnUpdateBrowseRuby(wxUpdateUIEvent& event) { event.Skip(); }

    // Class member variables

    NavigationPanel* m_nav_panel;
    wxBoxSizer* m_mainframe_sizer;
    wxBoxSizer* m_right_panel_sizer;
    wxMenu* m_menuEdit;
    wxMenu* m_menuFile;
    wxMenu* m_menuHelp;
    wxMenu* m_menuTools;
    wxMenu* m_submenu_recent;
    wxMenuBar* m_menubar;
    wxMenuItem* m_mi_preview;
    wxPanel* m_panel_right;
    wxSplitterWindow* m_MainSplitter;
    wxToolBar* m_toolbar;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
