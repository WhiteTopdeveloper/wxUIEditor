///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "preferences_dlg.h"

bool PreferencesDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* notebook = new wxNotebook(this, wxID_ANY);
    dlg_sizer->Add(notebook, wxSizerFlags(1).Expand().Border(wxALL));

    auto* page_general = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    notebook->AddPage(page_general, "General", true);

    auto* page_sizer_1 = new wxBoxSizer(wxVERTICAL);

    m_box_dark_settings = new wxBoxSizer(wxHORIZONTAL);

    m_check_dark_mode = new wxCheckBox(page_general, wxID_ANY, "Dark Mode");
    m_check_dark_mode->SetToolTip("Requires closing and restarting wxUiEditor");
    m_box_dark_settings->Add(m_check_dark_mode, wxSizerFlags().Border(wxALL));

    m_check_high_contrast = new wxCheckBox(page_general, wxID_ANY, "High Contrast");
    m_check_high_contrast->SetToolTip("Only used if Dark Mode is selected");
    m_box_dark_settings->Add(m_check_high_contrast, wxSizerFlags().Border(wxALL));

    page_sizer_1->Add(m_box_dark_settings, wxSizerFlags().Expand().Border(wxALL));

    m_check_right_propgrid = new wxCheckBox(page_general, wxID_ANY, "Property Panel on Right");
    m_check_right_propgrid->SetToolTip("If checked, the Property panel will be moved to the right side");
    page_sizer_1->Add(m_check_right_propgrid, wxSizerFlags().Border(wxALL));

    m_check_load_last = new wxCheckBox(page_general, wxID_ANY, "Always load last project");
    page_sizer_1->Add(m_check_load_last, wxSizerFlags().Border(wxALL));

    auto* checkBox_wakatime = new wxCheckBox(page_general, wxID_ANY, "Enable WakaTime");
    checkBox_wakatime->SetValue(true);
    checkBox_wakatime->SetValidator(wxGenericValidator(&m_isWakaTimeEnabled));
    checkBox_wakatime->SetToolTip(
    "If you have WakaTime installed, checking this will record time spent in the editor as \"designing\". (See https://wakatime.com/about)");
    page_sizer_1->Add(checkBox_wakatime, wxSizerFlags().Border(wxALL));

    m_box_code_font = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_2 = new wxStaticText(page_general, wxID_ANY, "Code Font:");
    staticText_2->Wrap(200);
    m_box_code_font->Add(staticText_2, wxSizerFlags().Center().Border(wxALL));

    m_code_font_picker = new wxFontPickerCtrl(page_general, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize,
        wxFNTP_FONTDESC_AS_LABEL|wxFNTP_USEFONT_FOR_LABEL);
    m_code_font_picker->SetToolTip("This font will be used for all of the Code panels");
    m_box_code_font->Add(m_code_font_picker, wxSizerFlags(1).Expand().Border(wxALL));

    page_sizer_1->Add(m_box_code_font, wxSizerFlags().Expand().Border(wxALL));
    page_general->SetSizerAndFit(page_sizer_1);

    auto* page_cpp = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    notebook->AddPage(page_cpp, "C++");

    auto* page_sizer_2 = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_3 = new wxStaticText(page_cpp, wxID_ANY, "&Line Length");
    staticText_3->Wrap(200);
    box_sizer->Add(staticText_3, wxSizerFlags().Center().Border(wxALL));

    auto* text_cpp_line_length = new wxTextCtrl(page_cpp, wxID_ANY, wxEmptyString);
    text_cpp_line_length->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_cpp_line_length));
    text_cpp_line_length->SetToolTip(
    "Most generated code will not exceed this length. This will be the initial value when a new project is created.");
    box_sizer->Add(text_cpp_line_length, wxSizerFlags().Border(wxALL));

    page_sizer_2->Add(box_sizer, wxSizerFlags().Border(wxALL));

    m_check_cpp_snake_case = new wxCheckBox(page_cpp, wxID_ANY, "Default variables should use snake_case");
    m_check_cpp_snake_case->SetToolTip(
    "By default, default variables use camelCase. Check this to use snake_case instead (e.g., foo_bar instead of fooBar)");
    page_sizer_2->Add(m_check_cpp_snake_case, wxSizerFlags().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxHORIZONTAL);

    auto* static_text = new wxStaticText(page_cpp, wxID_ANY, "wxWidgets version");
    box_sizer_5->Add(static_text, wxSizerFlags().Border(wxALL));

    m_choice_cpp_version = new wxChoice(page_cpp, wxID_ANY);
    m_choice_cpp_version->Append("3.1");
    m_choice_cpp_version->Append("3.2");
    m_choice_cpp_version->SetStringSelection("3.2");
    m_choice_cpp_version->SetToolTip("Code requiring a newer version then this will be placed in a conditional block.");
    box_sizer_5->Add(m_choice_cpp_version, wxSizerFlags().Border(wxALL));

    page_sizer_2->Add(box_sizer_5, wxSizerFlags().Border(wxALL));

    auto* box_sizer_8 = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_7 = new wxStaticText(page_cpp, wxID_ANY, "wxWidgets &keyword color:");
    box_sizer_8->Add(staticText_7, wxSizerFlags().Center().Border(wxALL));

    m_colour_cpp = new wxColourPickerCtrl(page_cpp, wxID_ANY, *wxBLACK);
    box_sizer_8->Add(m_colour_cpp, wxSizerFlags().Border(wxALL));

    page_sizer_2->Add(box_sizer_8, wxSizerFlags().Border(wxALL));
    page_cpp->SetSizerAndFit(page_sizer_2);

    auto* page_python = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    notebook->AddPage(page_python, "Python");

    auto* page_sizer_3 = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_4 = new wxStaticText(page_python, wxID_ANY, "&Line Length");
    staticText_4->Wrap(200);
    box_sizer_3->Add(staticText_4, wxSizerFlags().Center().Border(wxALL));

    auto* text_python_line_length = new wxTextCtrl(page_python, wxID_ANY, wxEmptyString);
    text_python_line_length->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_python_line_length));
    text_python_line_length->SetToolTip(
    "Most generated code will not exceed this length. This will be the initial value when a new project is created.");
    box_sizer_3->Add(text_python_line_length, wxSizerFlags().Border(wxALL));

    page_sizer_3->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* box_sizer_6 = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText = new wxStaticText(page_python, wxID_ANY, "wxWidgets &keyword color:");
    box_sizer_6->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_colour_python = new wxColourPickerCtrl(page_python, wxID_ANY, *wxBLACK);
    box_sizer_6->Add(m_colour_python, wxSizerFlags().Border(wxALL));

    page_sizer_3->Add(box_sizer_6, wxSizerFlags().Border(wxALL));
    page_python->SetSizerAndFit(page_sizer_3);

    auto* page_ruby = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    notebook->AddPage(page_ruby, "Ruby");

    auto* page_sizer_4 = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_5 = new wxStaticText(page_ruby, wxID_ANY, "&Line Length");
    staticText_5->Wrap(200);
    box_sizer_4->Add(staticText_5, wxSizerFlags().Center().Border(wxALL));

    auto* text_ruby_line_length = new wxTextCtrl(page_ruby, wxID_ANY, wxEmptyString);
    text_ruby_line_length->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_ruby_line_length));
    text_ruby_line_length->SetToolTip(
    "Most generated code will not exceed this length. This will be the initial value when a new project is created.");
    box_sizer_4->Add(text_ruby_line_length, wxSizerFlags().Border(wxALL));

    page_sizer_4->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* box_sizer_7 = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_6 = new wxStaticText(page_ruby, wxID_ANY, "wxWidgets &keyword color:");
    box_sizer_7->Add(staticText_6, wxSizerFlags().Center().Border(wxALL));

    m_colour_ruby = new wxColourPickerCtrl(page_ruby, wxID_ANY, *wxBLACK);
    box_sizer_7->Add(m_colour_ruby, wxSizerFlags().Border(wxALL));

    page_sizer_4->Add(box_sizer_7, wxSizerFlags().Border(wxALL));
    page_ruby->SetSizerAndFit(page_sizer_4);

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_BUTTON, &PreferencesDlg::OnOK, this, wxID_OK);
    Bind(wxEVT_INIT_DIALOG, &PreferencesDlg::OnInit, this);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

#include "preferences.h"  // Set/Get wxUiEditor preferences

void PreferencesDlg::OnInit(wxInitDialogEvent& event)
{
    m_check_dark_mode->SetValue(UserPrefs.is_DarkMode());
    m_check_high_contrast->SetValue(UserPrefs.is_HighContrast());

    m_check_cpp_snake_case->SetValue(UserPrefs.is_CppSnakeCase());
    m_check_load_last->SetValue(UserPrefs.is_LoadLastProject());
    m_check_right_propgrid->SetValue(UserPrefs.is_RightPropGrid());
    m_isWakaTimeEnabled = UserPrefs.is_WakaTimeEnabled();
    m_choice_cpp_version->SetStringSelection(UserPrefs.get_CppWidgetsVersion().make_wxString());
    m_colour_cpp->SetColour(UserPrefs.get_CppColour());
    m_colour_python->SetColour(UserPrefs.get_PythonColour());
    m_colour_ruby->SetColour(UserPrefs.get_RubyColour());

    m_cpp_line_length = tt::itoa(UserPrefs.get_CppLineLength()).make_wxString();
    m_python_line_length = tt::itoa(UserPrefs.get_PythonLineLength()).make_wxString();
    m_ruby_line_length = tt::itoa(UserPrefs.get_RubyLineLength()).make_wxString();

    // We aren't ready for setting the font yet
    m_box_code_font->ShowItems(false);
    // m_code_font_picker = UserPrefs.get_CodeDisplayFont();

#if !wxCHECK_VERSION(3, 3, 0) || !defined(_WIN32)
    m_box_dark_settings->ShowItems(false);
    Fit();
#endif

    // This will transfer data from the validator variables to the controls
    event.Skip();
}

void PreferencesDlg::OnOK(wxCommandEvent& WXUNUSED(event))
{
    if (!Validate() || !TransferDataFromWindow())
    {
        // TODO: [Randalphwa - 08-01-2023]
        // If either of these fail, there's no warning to the user
        return;
    }

    auto old_prop_grid_setting = UserPrefs.is_RightPropGrid();
    auto old_dark_mode_setting = UserPrefs.is_DarkMode();
    auto old_high_contrast_setting = UserPrefs.is_HighContrast();

    UserPrefs.set_DarkMode(m_check_dark_mode->GetValue());
    UserPrefs.set_HighContrast(m_check_high_contrast->GetValue());

    UserPrefs.set_CppSnakeCase(m_check_cpp_snake_case->GetValue());
    UserPrefs.set_LoadLastProject(m_check_load_last->GetValue());
    UserPrefs.set_RightPropGrid(m_check_right_propgrid->GetValue());
    UserPrefs.set_WakaTimeEnabled(m_isWakaTimeEnabled);

    UserPrefs.set_CppWidgetsVersion(m_choice_cpp_version->GetStringSelection().ToStdString());

    UserPrefs.set_CppColour(m_colour_cpp->GetColour());
    UserPrefs.set_PythonColour(m_colour_python->GetColour());
    UserPrefs.set_RubyColour(m_colour_ruby->GetColour());

    auto line_length = tt::atoi(m_cpp_line_length.ToStdString());

    auto fix_line_length = [&]()
    {
        if (line_length < 40)
            line_length = 40;
        else if (line_length > 300)
            line_length = 300;
    };

    fix_line_length();
    UserPrefs.set_CppLineLength(line_length);

    line_length = tt::atoi(m_python_line_length.ToStdString());
    fix_line_length();
    UserPrefs.set_PythonLineLength(line_length);

    line_length = tt::atoi(m_ruby_line_length.ToStdString());
    fix_line_length();
    UserPrefs.set_RubyLineLength(line_length);

    // UserPrefs.set_CodeDisplayFont(m_code_font_picker->GetSelectedFontInfo());

    UserPrefs.WriteConfig();

    if (old_dark_mode_setting != UserPrefs.is_DarkMode() || old_high_contrast_setting != UserPrefs.is_HighContrast())
        wxMessageBox("You must close and reopen wxUiEditor for the Dark Mode setting to take effect.");
    if (old_prop_grid_setting != UserPrefs.is_RightPropGrid())
        wxMessageBox("You must close and reopen wxUiEditor for the Property Panel setting to take effect.");

    EndModal(wxID_OK);
}
