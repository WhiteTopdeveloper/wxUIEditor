###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'
require 'wx/html'
require 'wx/pg'
require 'wx/rbn'
require 'wx/rtc'
require 'wx/stc'

$TXT_CTRL = 6000
$DLG_MAINTEST = Wx::ID_HIGHEST + 100
$ID_RICHTEXT = 100

require_relative 'images'
require 'base64'

class MainTestDialog < Wx::Dialog
  def initialize(parent, id = DLG_MAINTEST, title = '',
                 pos = Wx::DEFAULT_POSITION, size = Wx::DEFAULT_SIZE,
                 style = Wx::DEFAULT_DIALOG_STYLE)

    @TXT_CTRL6000

    super(parent, id, title, pos, size, style)

    dlg_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @notebook = Wx::Notebook.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::BK_TOP|Wx::NB_MULTILINE)
    dlg_sizer.add(@notebook, Wx::SizerFlags.new.expand.border(Wx::ALL))

    page_2 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_2, 'Text')

    page_sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)

    @text_ctrl = Wx::TextCtrl.new(page_2, TXT_CTRL, '', Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TE_MULTILINE|Wx::TE_READONLY|Wx::TE_RICH2)
    @text_ctrl.set_hint('wxTextCtrl')
    page_sizer_1.add(@text_ctrl, Wx::SizerFlags.new.expand.border(Wx::ALL))

    grid_sizer2 = Wx::GridSizer.new(2, 0, 0)

    @static_text = Wx::StaticText.new(page_2, Wx::ID_ANY, '12-pt default font')
    font_info = Wx::FontInfo.new(11.5)
    font_info.face_name('Segoe UI')
    @static_text.set_font(Wx::Font.new(font_info))
    grid_sizer2.add(@static_text, Wx::SizerFlags.new.border(Wx::ALL))

    @static_text = Wx::StaticText.new(page_2, Wx::ID_ANY, 'Comic Sans MS')
    font_info = Wx::FontInfo.new(10.5)
    font_info.face_name('Comic Sans MS')
    @static_text.set_font(Wx::Font.new(font_info))
    grid_sizer2.add(@static_text, Wx::SizerFlags.new.border(Wx::ALL))

    @static_text2 = Wx::StaticText.new(page_2, Wx::ID_ANY, 'italic')
    font = Wx::Font.new(Wx::SystemSettings.get_font(Wx::SYS_DEFAULT_GUI_FONT))
    font.set_style(Wx::FONTSTYLE_ITALIC)
    @static_text2.set_font(font)
    grid_sizer2.add(@static_text2, Wx::SizerFlags.new.border(Wx::ALL))

    @static_text3 = Wx::StaticText.new(page_2, Wx::ID_ANY,
      'bold, underlined Times New Roman, 12.5')
    font_info = Wx::FontInfo.new(12.5)
    font_info.face_name('Times New Roman').weight(Wx::FONTWEIGHT_BOLD).underlined()
    @static_text3.set_font(Wx::Font.new(font_info))
    grid_sizer2.add(@static_text3, Wx::SizerFlags.new.border(Wx::ALL))

    page_sizer_1.add(grid_sizer2, Wx::SizerFlags.new.border(Wx::ALL))

    @richText = Wx::RTC::RichTextCtrl.new(page_2, ID_RICHTEXT, '',
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::RTC::RE_MULTILINE|Wx::VSCROLL|
      Wx::HSCROLL|Wx::NO_BORDER|Wx::WANTS_CHARS)
    @richText.set_hint('wxRichTextCtrl')
    @richText.set_min_size(convert_dialog_to_pixels(Wx::Size.new(150, 30)))
    page_sizer_1.add(@richText, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @scintilla = Wx::STC::StyledTextCtrl.new(page_2, Wx::ID_ANY)
    @scintilla.set_lexer(Wx::STC::STC_LEX_CPP)
    @scintilla.set_eol_mode(Wx::STC::STC_EOL_LF)
    @scintilla.set_view_white_space(Wx::STC::STC_WS_VISIBLEALWAYS)
    # Sets text margin scaled appropriately for the current DPI on Windows,
    # 5 on wxGTK or wxOSX
    @scintilla.set_margin_left(Wx::SizerFlags.get_default_border())
    @scintilla.set_margin_right(Wx::SizerFlags.get_default_border())
    @scintilla.set_margin_width(1, 0) # Remove default margin
    @scintilla.set_back_space_un_indents(true)
    @scintilla.set_min_size(convert_dialog_to_pixels(Wx::Size.new(150, 60)))
    page_sizer_1.add(@scintilla, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @htmlWin = Wx::HTML::HtmlWindow.new(page_2, Wx::ID_ANY)
    @htmlWin.set_page('This is an <b>HTML</b> window')
    @htmlWin.set_min_size(convert_dialog_to_pixels(Wx::Size.new(100, 60)))
    page_sizer_1.add(@htmlWin, Wx::SizerFlags.new.expand.border(Wx::ALL))
    page_2.set_sizer_and_fit(page_sizer_1)

    page_4 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_4, 'Buttons')

    box_sizer_3 = Wx::BoxSizer.new(Wx::VERTICAL)

    grid_bag_sizer = Wx::GridBagSizer.new

    @btn = Wx::Button.new(page_4, Wx::ID_ANY, 'Normal')
    @btn.set_tool_tip('A normal button')
    grid_bag_sizer.add(@btn, Wx::GBPosition.new(0, 0), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @btn_2 = Wx::Button.new(page_4, Wx::ID_ANY, (''))
    @btn_2.set_label_markup('<b><span foreground=\'red\'>Markup</span></b>')
    @btn_2.set_tool_tip('Text should be Bold and Red.')
    grid_bag_sizer.add(@btn_2, Wx::GBPosition.new(0, 1), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @btn_bitmaps = Wx::Button.new(page_4, Wx::ID_ANY, 'Bitmaps')
    @btn_bitmaps.set_bitmap(wxue_get_bundle($normal_png))
    @btn_bitmaps.set_bitmap_disabled(wxue_get_bundle($no_hour_png))
    @btn_bitmaps.set_bitmap_current(wxue_get_bundle($focus_png))
    @btn_bitmaps.set_tool_tip(
    'Bitmap should change when mouse is over button, or button is disabled.')
    grid_bag_sizer.add(@btn_bitmaps, Wx::GBPosition.new(0, 2), Wx::GBSpan.new(1,
      1), Wx::ALL, 5)

    @btn_4 = Wx::Button.new(page_4, Wx::ID_ANY, 'Right')
    @btn_4.set_bitmap_position(Wx::RIGHT)
    @btn_4.set_bitmap(wxue_get_bundle($normal_png))
    @btn_4.set_tool_tip(
    'Bitmap should be on the right side (fails in wxPython 4.2).')
    grid_bag_sizer.add(@btn_4, Wx::GBPosition.new(0, 3), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @toggleBtn = Wx::ToggleButton.new(page_4, Wx::ID_ANY, 'Toggle',
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::BU_EXACTFIT)
    @toggleBtn.set_tool_tip(
    'Style set to exact fit, so it should be a bit smaller than usual.')
    grid_bag_sizer.add(@toggleBtn, Wx::GBPosition.new(0, 4), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    disable_bitmaps = Wx::CheckBox.new(page_4, Wx::ID_ANY, 'Disable')
    disable_bitmaps.set_tool_tip(
    'This will change the enable state and bitmap of the Bitmaps button.')
    grid_bag_sizer.add(disable_bitmaps, Wx::GBPosition.new(2, 2), Wx::GBSpan.new(
      1, 1), Wx::ALL, 5)

    box_sizer_3.add(grid_bag_sizer, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_7 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @btn_5 = Wx::CommandLinkButton.new(page_4, Wx::ID_ANY, 'Command',
      'wxCommandLinkButton')
    @btn_5.set_bitmap(Wx::ArtProvider.get_bitmap_bundle(Wx::ART_GO_FORWARD,
      Wx::ART_OTHER))
    @btn_5.set_tool_tip('The bitmap for this is from Art Provider.')
    box_sizer_7.add(@btn_5, Wx::SizerFlags.new.border(Wx::ALL))

    # Trailing spaces added to avoid clipping
    radioBox = Wx::RadioBox.new(page_4, Wx::ID_ANY, 'Radio Box',
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, ['Button zero ','Button one ',
    'Button two '], 0, Wx::RA_SPECIFY_ROWS)
    radioBox.set_selection(1)
    box_sizer_7.add(radioBox, Wx::SizerFlags.new.border(Wx::ALL))

    # wxPython currently does not support a checkbox as a static box label
    static_box_4 = Wx::StaticBoxSizer.new(Wx::VERTICAL, page_4, 'Checkbox')

    @radioBtn_4 = Wx::RadioButton.new(static_box_4.get_static_box, Wx::ID_ANY,
      'First button')
    static_box_4.add(@radioBtn_4, Wx::SizerFlags.new.border(Wx::ALL))

    @radioBtn_2 = Wx::RadioButton.new(static_box_4.get_static_box, Wx::ID_ANY,
      'Second button')
    @radioBtn_2.set_value(true)
    static_box_4.add(@radioBtn_2, Wx::SizerFlags.new.border(Wx::ALL))

    @radioBtn_3 = Wx::RadioButton.new(static_box_4.get_static_box, Wx::ID_ANY,
      'Third button')
    static_box_4.add(@radioBtn_3, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_7.add(static_box_4, Wx::SizerFlags.new.border(Wx::ALL))

    # wxPython currently does not support a radio button as a static box label
    static_box_5 = Wx::StaticBoxSizer.new(Wx::VERTICAL, page_4, 'Radio')

    @radioBtn_5 = Wx::RadioButton.new(static_box_5.get_static_box, Wx::ID_ANY,
      'First button')
    static_box_5.add(@radioBtn_5, Wx::SizerFlags.new.border(Wx::ALL))

    @radioBtn_6 = Wx::RadioButton.new(static_box_5.get_static_box, Wx::ID_ANY,
      'Second button')
    @radioBtn_6.set_value(true)
    static_box_5.add(@radioBtn_6, Wx::SizerFlags.new.border(Wx::ALL))

    @radioBtn_7 = Wx::RadioButton.new(static_box_5.get_static_box, Wx::ID_ANY,
      'Third button')
    static_box_5.add(@radioBtn_7, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_7.add(static_box_5, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_3.add(box_sizer_7, Wx::SizerFlags.new.border(Wx::ALL))

    static_line = Wx::StaticLine.new(page_4, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, convert_dialog_to_pixels(Wx::Size.new(20, -1)),
      Wx::LI_HORIZONTAL)
    box_sizer_3.add(static_line, Wx::SizerFlags.new.expand.border(Wx::ALL))

    box_sizer_19 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    wrap_sizer = Wx::WrapSizer.new(Wx::HORIZONTAL, Wx::EXTEND_LAST_ON_EACH_LINE|
      Wx::REMOVE_LEADING_SPACES)

    @btn_3 = Wx::Button.new(page_4, Wx::ID_ANY, 'First btn')
    wrap_sizer.add(@btn_3, Wx::SizerFlags.new.border(Wx::ALL))

    btn2 = Wx::Button.new(page_4, Wx::ID_ANY, 'Popup')
    wrap_sizer.add(btn2, Wx::SizerFlags.new.border(Wx::ALL))

    @radioBtn = Wx::RadioButton.new(page_4, Wx::ID_ANY, 'First radio',
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::RB_GROUP)
    wrap_sizer.add(@radioBtn, Wx::SizerFlags.new.center.border(Wx::ALL))

    @radioBtn2 = Wx::RadioButton.new(page_4, Wx::ID_ANY, 'Second radio')
    wrap_sizer.add(@radioBtn2, Wx::SizerFlags.new.center.border(Wx::ALL))

    @checkBox = Wx::CheckBox.new(page_4, Wx::ID_ANY, 'Checkbox',
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::CHK_3STATE)
    @checkBox.set3_state_value(Wx::CHK_UNDETERMINED)
    wrap_sizer.add(@checkBox, Wx::SizerFlags.new.center.border(Wx::ALL))

    box_sizer_19.add(wrap_sizer, Wx::SizerFlags.new.expand.border(Wx::ALL))

    # wxPython currently does not support a checkbox as a static box label
    static_box_3 = Wx::StaticBoxSizer.new(Wx::VERTICAL, page_4, 'Play Animation')

    @toggleBtn_2 = Wx::ToggleButton.new(static_box_3.get_static_box, Wx::ID_ANY,
      'Play Animation', Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::BU_EXACTFIT)
    static_box_3.add(@toggleBtn_2, Wx::SizerFlags.new.border(Wx::ALL))

    @animation_ctrl = Wx::AnimationCtrl.new(static_box_3.get_static_box,
      Wx::ID_ANY, get_animation($clr_hourglass_gif), Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::AC_DEFAULT_STYLE)
    @animation_ctrl.set_inactive_bitmap(wxue_get_bundle($disabled_png))
    static_box_3.add(@animation_ctrl, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_19.add(static_box_3, Wx::SizerFlags.new.border(Wx::ALL))

    @indicator = Wx::ActivityIndicator.new(page_4, Wx::ID_ANY)
    @indicator.start
    box_sizer_19.add(@indicator, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_3.add(box_sizer_19, Wx::SizerFlags.new.expand.border(Wx::ALL))
    page_4.set_sizer_and_fit(box_sizer_3)

    page_5 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_5, 'Lists')

    box_sizer_5 = Wx::BoxSizer.new(Wx::VERTICAL)

    flex_grid_sizer = Wx::FlexGridSizer.new(2, 0, 0)

    box_sizer_10 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_2 = Wx::StaticText.new(page_5, Wx::ID_ANY, 'wxRearrangeCtrl')
    box_sizer_10.add(@staticText_2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @rearrange = Wx::RearrangeCtrl.new(page_5, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, [], [])
    box_sizer_10.add(@rearrange, Wx::SizerFlags.new.border(Wx::ALL))

    flex_grid_sizer.add(box_sizer_10, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_11 = Wx::BoxSizer.new(Wx::VERTICAL)

    staticText_3 = Wx::StaticText.new(page_5, Wx::ID_ANY, 'wxCheckListBox')
    box_sizer_11.add(staticText_3, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @checkList = Wx::CheckListBox.new(page_5, Wx::ID_ANY)
    box_sizer_11.add(@checkList, Wx::SizerFlags.new.border(Wx::ALL))

    flex_grid_sizer.add(box_sizer_11, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_12 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_4 = Wx::StaticText.new(page_5, Wx::ID_ANY, 'wxListView')
    box_sizer_12.add(@staticText_4, Wx::SizerFlags.new.border(Wx::ALL))

    @listview = Wx::ListView.new(page_5, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::LC_SINGLE_SEL|Wx::LC_REPORT)
    @listview.append_column('name')
    @listview.append_column('value')
    info = Wx::ListItem.new
    info.clear
    info.set_id(0)
    idx = @listview.insert_item(info)
    @listview.set_item(idx, 0, 'meaning')
    @listview.set_item(idx, 1, '42')
    @listview.set_tool_tip('Separate content columns with a semi-colon (;)')
    box_sizer_12.add(@listview, Wx::SizerFlags.new.border(Wx::ALL))

    flex_grid_sizer.add(box_sizer_12, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_13 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @edit_listbox = Wx::EditableListBox.new(page_5, Wx::ID_ANY,
      'My Editable ListBox', Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE,
      Wx::EL_ALLOW_NEW|Wx::EL_ALLOW_EDIT|Wx::EL_ALLOW_DELETE)
    box_sizer_13.add(@edit_listbox, Wx::SizerFlags.new.border(Wx::ALL))

    flex_grid_sizer.add(box_sizer_13, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer2 = Wx::BoxSizer.new(Wx::VERTICAL)

    staticText2 = Wx::StaticText.new(page_5, Wx::ID_ANY, 'wxSimpleHtmlLiseBox')
    box_sizer2.add(staticText2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @html_listbox = Wx::HTML::SimpleHtmlListBox.new(page_5, Wx::ID_ANY)
    @html_listbox.append('<b>bold</b>')
    @html_listbox.append('<i>italics</i>')
    @html_listbox.set_min_size(
      convert_dialog_to_pixels(Wx::Size.new(-1, 40)))
    box_sizer2.add(@html_listbox, Wx::SizerFlags.new(1).expand.border(Wx::ALL))

    flex_grid_sizer.add(box_sizer2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_5.add(flex_grid_sizer, Wx::SizerFlags.new.expand.border(Wx::ALL))
    page_5.set_sizer_and_fit(box_sizer_5)

    page_3 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_3, 'Combos')

    page_sizer_2 = Wx::BoxSizer.new(Wx::VERTICAL)

    static_box = Wx::StaticBoxSizer.new(Wx::VERTICAL, page_3,
      'Combos and Choices')

    box_sizer3 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    static_box.get_static_boxstatic_box_sizer2 = Wx::StaticBoxSizer.new(
      Wx::VERTICAL, static_box, 'Combo')

    @staticText3 = Wx::StaticText.new(static_box_sizer2.get_static_box, Wx::ID_ANY,
      'Unsorted')
    static_box_sizer2.add(@staticText3, Wx::SizerFlags.new.border(Wx::ALL))

    @comboBox = Wx::ComboBox.new(static_box_sizer2.get_static_box, Wx::ID_ANY)
    @comboBox.append('item #1')
    @comboBox.append('item #2')
    @comboBox.append('item #0')
    @comboBox.set_string_selection('item #2')
    @comboBox.set_tool_tip('Item #0 should be selected by default')
    static_box_sizer2.add(@comboBox, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @staticText4 = Wx::StaticText.new(static_box_sizer2.get_static_box, Wx::ID_ANY,
      'Sorted')
    static_box_sizer2.add(@staticText4, Wx::SizerFlags.new.border(Wx::ALL))

    @comboBox2 = Wx::ComboBox.new(static_box_sizer2.get_static_box, Wx::ID_ANY, (''),
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, [], Wx::CB_SORT)
    @comboBox2.append('item #1')
    @comboBox2.append('item #2')
    @comboBox2.append('item #0')
    @comboBox2.set_string_selection('item #2')
    @comboBox2.set_tool_tip('Item #2 should be selected by default')
    static_box_sizer2.add(@comboBox2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer3.add(static_box_sizer2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    static_box.get_static_boxstatic_box_sizer3 = Wx::StaticBoxSizer.new(
      Wx::VERTICAL, static_box, 'Choice')

    @staticText5 = Wx::StaticText.new(static_box_sizer3.get_static_box, Wx::ID_ANY,
      'Unsorted')
    static_box_sizer3.add(@staticText5, Wx::SizerFlags.new.border(Wx::ALL))

    @choice = Wx::Choice.new(static_box_sizer3.get_static_box, Wx::ID_ANY)
    @choice.append('item #1')
    @choice.append('item #2')
    @choice.append('item #0')
    @choice.set_selection(2)
    @choice.set_tool_tip('Item #0 should be selected by default')
    static_box_sizer3.add(@choice, Wx::SizerFlags.new.border(Wx::ALL))

    @staticText6 = Wx::StaticText.new(static_box_sizer3.get_static_box, Wx::ID_ANY,
      'Sorted')
    static_box_sizer3.add(@staticText6, Wx::SizerFlags.new.border(Wx::ALL))

    @choice2 = Wx::Choice.new(static_box_sizer3.get_static_box, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, [], Wx::CB_SORT)
    @choice2.append('item #1')
    @choice2.append('item #2')
    @choice2.append('item #0')
    @choice2.set_selection(2)
    @choice2.set_tool_tip('Item #2 should be selected by default')
    static_box_sizer3.add(@choice2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer3.add(static_box_sizer3, Wx::SizerFlags.new.expand.border(Wx::ALL))

    static_box.get_static_boxstatic_box_sizer4 = Wx::StaticBoxSizer.new(
      Wx::VERTICAL, static_box, 'List')

    @staticText7 = Wx::StaticText.new(static_box_sizer4.get_static_box, Wx::ID_ANY,
      'Unsorted')
    static_box_sizer4.add(@staticText7, Wx::SizerFlags.new.border(Wx::ALL))

    @listbox = Wx::ListBox.new(static_box_sizer4.get_static_box, Wx::ID_ANY)
    @listbox.append('item #1')
    @listbox.append('item #2')
    @listbox.append('item #0')
    static_box_sizer4.add(@listbox, Wx::SizerFlags.new.border(Wx::ALL))

    @staticText8 = Wx::StaticText.new(static_box_sizer4.get_static_box, Wx::ID_ANY,
      'Sorted')
    static_box_sizer4.add(@staticText8, Wx::SizerFlags.new.border(Wx::ALL))

    @listBox2 = Wx::ListBox.new(static_box_sizer4.get_static_box, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, [], Wx::LB_SINGLE|Wx::LB_SORT)
    @listBox2.append('item #1')
    @listBox2.append('item #2')
    @listBox2.append('item #0')
    static_box_sizer4.add(@listBox2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer3.add(static_box_sizer4, Wx::SizerFlags.new.expand.border(Wx::ALL))

    static_box.get_static_boxstatic_box_sizer5 = Wx::StaticBoxSizer.new(
      Wx::VERTICAL, static_box, 'Checked')

    @staticText9 = Wx::StaticText.new(static_box_sizer5.get_static_box, Wx::ID_ANY,
      'Unsorted')
    static_box_sizer5.add(@staticText9, Wx::SizerFlags.new.border(Wx::ALL))

    @checkList_2 = Wx::CheckListBox.new(static_box_sizer5.get_static_box,
      Wx::ID_ANY)
    @checkList_2.append('item #1')
    @checkList_2.append('item #2')
    @checkList_2.append('item #0')
    static_box_sizer5.add(@checkList_2, Wx::SizerFlags.new.border(Wx::ALL))

    @staticText10 = Wx::StaticText.new(static_box_sizer5.get_static_box,
      Wx::ID_ANY, 'Sorted')
    static_box_sizer5.add(@staticText10, Wx::SizerFlags.new.border(Wx::ALL))

    @checkList2 = Wx::CheckListBox.new(static_box_sizer5.get_static_box,
      Wx::ID_ANY, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, [], Wx::LB_SINGLE|
      Wx::LB_SORT)
    @checkList2.append('item #1')
    @checkList2.append('item #2')
    @checkList2.append('item #0')
    static_box_sizer5.add(@checkList2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer3.add(static_box_sizer5, Wx::SizerFlags.new.expand.border(Wx::ALL))

    static_box.add(box_sizer3, Wx::SizerFlags.new.expand.border(Wx::ALL))

    page_sizer_2.add(static_box, Wx::SizerFlags.new.expand.border(Wx::ALL))

    box_sizer_20 = Wx::BoxSizer.new(Wx::VERTICAL)

    @collapsible_pane = Wx::CollapsiblePane.new(page_3, Wx::ID_ANY,
      'Collapsible Pane')
    @collapsible_pane.expand
    box_sizer_20.add(@collapsible_pane,
      Wx::SizerFlags.new.expand.border(Wx::ALL))

    box_sizer_21 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @staticText_5 = Wx::StaticText.new(@collapsible_pane.get_pane(), Wx::ID_ANY,
      'This text will be hidden if the Pane is collapsed.')
    box_sizer_21.add(@staticText_5, Wx::SizerFlags.new.border(Wx::ALL))
    @collapsible_pane.get_pane().set_sizer_and_fit(box_sizer_21)

    page_sizer_2.add(box_sizer_20, Wx::SizerFlags.new.border(Wx::ALL))
    page_3.set_sizer_and_fit(page_sizer_2)

    page_6 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::BORDER_THEME|Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_6, 'Pickers')

    parent_sizer2 = Wx::BoxSizer.new(Wx::VERTICAL)

    static_box_2 = Wx::StaticBoxSizer.new(Wx::VERTICAL, page_6, 'Pickers')

    grid_sizer = Wx::GridSizer.new(2, 0, 0)

    box_sizer = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText__2 = Wx::StaticText.new(static_box_2.get_static_box, Wx::ID_ANY,
      'File:')
    box_sizer.add(staticText__2, Wx::SizerFlags.new.center.border(Wx::ALL))

    @filePicker = Wx::FilePickerCtrl.new(static_box_2.get_static_box, Wx::ID_ANY, (''),
      Wx::FileSelectorPromptStr, 'BMP files|*.bmp', Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::FLP_USE_TEXTCTRL|Wx::FLP_OPEN|Wx::FLP_FILE_MUST_EXIST)
    box_sizer.add(@filePicker, Wx::SizerFlags.new.border(Wx::ALL))

    grid_sizer.add(box_sizer, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText__3 = Wx::StaticText.new(static_box_2.get_static_box, Wx::ID_ANY,
      'Directory:')
    box_sizer_2.add(staticText__3, Wx::SizerFlags.new.center.border(Wx::ALL))

    @dirPicker = Wx::DirPickerCtrl.new(static_box_2.get_static_box, Wx::ID_ANY,
      '.', Wx::DIR_SELECTOR_PROMPT_STR, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE,
      Wx::DIRP_DEFAULT_STYLE|Wx::DIRP_SMALL)
    box_sizer_2.add(@dirPicker, Wx::SizerFlags.new.border(Wx::ALL))

    grid_sizer.add(box_sizer_2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_4 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText__4 = Wx::StaticText.new(static_box_2.get_static_box, Wx::ID_ANY,
      'Colour:')
    box_sizer_4.add(staticText__4, Wx::SizerFlags.new.center.border(Wx::ALL))

    @colourPicker = Wx::ColourPickerCtrl.new(static_box_2.get_static_box,
      Wx::ID_ANY, Wx::BLACK)
    box_sizer_4.add(@colourPicker, Wx::SizerFlags.new.border(Wx::ALL))

    grid_sizer.add(box_sizer_4, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_9 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText__7 = Wx::StaticText.new(static_box_2.get_static_box, Wx::ID_ANY,
      'Font:')
    box_sizer_9.add(staticText__7, Wx::SizerFlags.new.center.border(Wx::ALL))

    @fontPicker = Wx::FontPickerCtrl.new(static_box_2.get_static_box, Wx::ID_ANY,
      Wx::Font(Wx::NORMAL_FONT.get_point_size(), Wx::FONTFAMILY_DEFAULT,
      Wx::FONTSTYLE_NORMAL, Wx::FONTWEIGHT_NORMAL, false, 'Comic Sans MS'),
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::FNTP_DEFAULT_STYLE|
      Wx::FNTP_USE_TEXTCTRL)
    box_sizer_9.add(@fontPicker, Wx::SizerFlags.new.border(Wx::ALL))

    grid_sizer.add(box_sizer_9, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_6 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText__5 = Wx::StaticText.new(static_box_2.get_static_box, Wx::ID_ANY,
      'Date:')
    box_sizer_6.add(staticText__5, Wx::SizerFlags.new.center.border(Wx::ALL))

    @datePicker = Wx::DatePickerCtrl.new(static_box_2.get_static_box, Wx::ID_ANY,
      DateTime.now)
    box_sizer_6.add(@datePicker, Wx::SizerFlags.new.border(Wx::ALL))

    grid_sizer.add(box_sizer_6, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_8 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText__6 = Wx::StaticText.new(static_box_2.get_static_box, Wx::ID_ANY,
      'Time:')
    box_sizer_8.add(staticText__6, Wx::SizerFlags.new.center.border(Wx::ALL))

    @timePicker = Wx::TimePickerCtrl.new(static_box_2.get_static_box, Wx::ID_ANY,
      DateTime.now)
    box_sizer_8.add(@timePicker, Wx::SizerFlags.new.border(Wx::ALL))

    grid_sizer.add(box_sizer_8, Wx::SizerFlags.new.border(Wx::ALL))

    static_box_2.add(grid_sizer, Wx::SizerFlags.new.border(Wx::ALL))

    parent_sizer2.add(static_box_2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @fileCtrl = Wx::FileCtrl.new(page_6, Wx::ID_ANY, '', '',
      Wx::FileSelectorDefaultWildcardStr, Wx::FC_OPEN, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE)
    parent_sizer2.add(@fileCtrl, Wx::SizerFlags.new.border(Wx::ALL))
    page_6.set_sizer_and_fit(parent_sizer2)

    page = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page, 'RibbonBar')

    page_sizer_3 = Wx::BoxSizer.new(Wx::VERTICAL)

    @rbnBar = Wx::RBN::RibbonBar.new(page, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::RBN::RIBBON_BAR_SHOW_PAGE_LABELS|
      Wx::RBN::RIBBON_BAR_SHOW_PAGE_ICONS|Wx::RBN::RIBBON_BAR_FLOW_HORIZONTAL)

    @rbnBar.set_art_provider(Wx::RBN::RibbonAUIArtProvider.new)
    page_sizer_3.add(@rbnBar, Wx::SizerFlags.new.expand.border(Wx::ALL))

    rbnPage = Wx::RBN::RibbonPage.new(@rbnBar, Wx::ID_ANY, 'First')
    @rbnBar.set_active_page(rbnPage)

    rbnPanel = Wx::RBN::RibbonPanel.new(rbnPage, Wx::ID_ANY, 'English',
      wxue_get_bundle($english_png),
      .get_bitmap(Wx::Size.new(
      FromDIP(19), FromDIP(15))))

    first_parent_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    box_sizer_15 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText = Wx::StaticText.new(rbnPanel, Wx::ID_ANY,
      'This is a sentence in English.')
    @staticText.wrap(200)
    box_sizer_15.add(@staticText, Wx::SizerFlags.new.border(Wx::ALL))

    @btn_6 = Wx::Button.new(rbnPanel, Wx::ID_ANY, 'Switch')
    box_sizer_15.add(@btn_6, Wx::SizerFlags.new.center.border(Wx::ALL))

    first_parent_sizer.add(box_sizer_15,
    Wx::SizerFlags.new(1).expand.border(Wx::ALL))
    rbnPanel.set_sizer_and_fit(first_parent_sizer)

    rbnPanel_2 = Wx::RBN::RibbonPanel.new(rbnPage, Wx::ID_ANY, 'French',
      wxue_get_bundle($french_png),
      .get_bitmap(Wx::Size.new(
      FromDIP(19), FromDIP(15))))
    rbnPanel_2.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_MENU))

    first_parent_sizer_2 = Wx::BoxSizer.new(Wx::VERTICAL)

    box_sizer_16 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_3 = Wx::StaticText.new(rbnPanel_2, Wx::ID_ANY,
      'Ceci est une phrase en français.')
    @staticText_3.wrap(200)
    box_sizer_16.add(@staticText_3, Wx::SizerFlags.new.border(Wx::ALL))

    @btn_7 = Wx::Button.new(rbnPanel_2, Wx::ID_ANY, 'Switch')
    box_sizer_16.add(@btn_7, Wx::SizerFlags.new.center.border(Wx::ALL))

    first_parent_sizer_2.add(box_sizer_16,
    Wx::SizerFlags.new(1).expand.border(Wx::ALL))
    rbnPanel_2.set_sizer_and_fit(first_parent_sizer_2)

    ribbonPage2 = Wx::RBN::RibbonPage.new(@rbnBar, Wx::ID_ANY, 'Second')

    ribbonPanel2 = Wx::RBN::RibbonPanel.new(ribbonPage2, Wx::ID_ANY,
      'Button Panel')

    rbnBtnBar = Wx::RBN::RibbonButtonBar.new(ribbonPanel2, Wx::ID_ANY)
    rbnBtnBar.add_button(Wx::ID_ANY, 'Forward', Wx::ArtProvider.get_bitmap(
      Wx::ART_GO_FORWARD, Wx::ART_OTHER), '', Wx::RBN::RIBBON_BUTTON_NORMAL)
    rbnBtnBar.add_button(Wx::ID_ANY, 'Backward', wxue_get_bundle($left_png),
      .get_bitmap(Wx::Size.new(
      FromDIP(24), FromDIP(24))), '', Wx::RBN::RIBBON_BUTTON_NORMAL)
    rbnBtnBar.realize

    ribbonPage_2 = Wx::RBN::RibbonPage.new(@rbnBar, Wx::ID_ANY, 'Third')

    ribbonPanel_2 = Wx::RBN::RibbonPanel.new(ribbonPage_2, Wx::ID_ANY,
      'Tool Panel')

    rbnToolBar = Wx::RBN::RibbonToolBar.new(ribbonPanel_2, Wx::ID_ANY)
    rbnToolBar.add_tool(Wx::ID_FILE1, Wx::ArtProvider.get_bitmap(
      Wx::ART_GOTO_FIRST, Wx::ART_TOOLBAR), '', Wx::RBN::RIBBON_BUTTON_NORMAL)
    rbnToolBar.add_separator
    rbnToolBar.add_tool(Wx::ID_FILE9, Wx::ArtProvider.get_bitmap(
      Wx::ART_GOTO_LAST, Wx::ART_TOOLBAR), '', Wx::RBN::RIBBON_BUTTON_NORMAL)
    rbnToolBar.realize

    ribbonPage_3 = Wx::RBN::RibbonPage.new(@rbnBar, Wx::ID_ANY, 'Fourth')

    rbnPanel_3 = Wx::RBN::RibbonPanel.new(ribbonPage_3, Wx::ID_ANY,
      'Gallery Panel')

    rbnGallery = Wx::RBN::RibbonGallery.new(rbnPanel_3, Wx::ID_ANY)
    rbnGallery.append(wxue_get_bundle($toggle_button_png),
      .get_bitmap(Wx::Size.new(
      FromDIP(22), FromDIP(22))), Wx::ID_ANY)
    rbnGallery.realize
    page.set_sizer_and_fit(page_sizer_3)

    page_7 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_7, 'Banners')
    page_7.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    page_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    box_sizer_17 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    # wxRuby3 does not support wxBannerWindow
    box_sizer_17.add(@banner_left, Wx::SizerFlags.new.border(Wx::ALL))

    # wxRuby3 does not support wxBannerWindow
    box_sizer_17.add(@banner_top, Wx::SizerFlags.new.border(Wx::ALL))

    # wxRuby3 does not support wxBannerWindow
    box_sizer_17.add(@banner_right, Wx::SizerFlags.new.border(Wx::ALL))

    page_sizer.add(box_sizer_17, Wx::SizerFlags.new(1).border(Wx::ALL))

    box_sizer_18 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    # wxRuby3 does not support wxBannerWindow
    box_sizer_18.add(@banner, Wx::SizerFlags.new.border(Wx::ALL))

    page_sizer.add(box_sizer_18, Wx::SizerFlags.new.border(Wx::ALL))
    page_7.set_sizer_and_fit(page_sizer)

    page_8 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_8, 'Data')
    page_8.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    page_sizer_4 = Wx::BoxSizer.new(Wx::VERTICAL)

    @propertyGrid = Wx::PropertyGrid.new(page_8, Wx::ID_ANY)
    page_sizer_4.add(@propertyGrid, Wx::SizerFlags.new.expand.border(Wx::ALL))

    @propertyGridItem = @propertyGrid.append(Wx::PG::PropertyCategory.new(
    'CategoryName', 'CategoryName'))

    @propertyGridItem_2 = @propertyGrid.append(Wx::PG::StringProperty.new(
    'String', ''))

    @propertyGridItem_3 = @propertyGrid.append(Wx::PG::IntProperty.new('Integer', ''
      ))
    page_8.set_sizer_and_fit(page_sizer_4)

    box_sizer_14 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    staticText_4 = Wx::StaticText.new(self, Wx::ID_ANY, 'Events:')
    box_sizer_14.add(staticText_4, Wx::SizerFlags.new.center.border(Wx::ALL))

    btn = Wx::Button.new(self, Wx::ID_ANY, 'Clear Events')
    box_sizer_14.add(btn, Wx::SizerFlags.new.border(Wx::ALL))

    dlg_sizer.add(box_sizer_14, Wx::SizerFlags.new.border(Wx::ALL))

    @events_list = Wx::ListBox.new(self, Wx::ID_ANY)
    @events_list.set_min_size(
      convert_dialog_to_pixels(Wx::Size.new(-1, 60)))
    dlg_sizer.add(@events_list, Wx::SizerFlags.new(1).expand.border(Wx::ALL))

    if Wx::PLATFORM != 'WXMAC'
      stdBtn_line = Wx::StaticLine.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
                                  Wx::Size.new(20, -1))
      dlg_sizer.add(stdBtn_line, Wx::SizerFlags.new.expand.border(Wx::ALL))
    end
    stdBtn = Wx::StdDialogButtonSizer.new
    _ok_btn = Wx::Button.new(self, Wx::ID_OK)
    stdBtn.add_button(_ok_btn)
    _ok_btn.set_default
    stdBtn.add_button(Wx::Button.new(self, Wx::ID_CANCEL))
    stdBtn.realize
    dlg_sizer.add(stdBtn, Wx::SizerFlags.new.expand.border(Wx::ALL))

    set_sizer_and_fit(dlg_sizer)
    centre(Wx::BOTH)

    # Event handlers
    evt_button(@btn.get_id, :OnEvent)
    evt_button(@btn_3.get_id, :OnEvent)
    evt_button(btn2.get_id, :OnPopupBtn)
    evt_button(@btn_7.get_id, :OnEvent)
    evt_button(@btn_2.get_id, :OnEvent)
    evt_button(@btn_bitmaps.get_id, :OnEvent)
    evt_button(@btn_4.get_id, :OnEvent)
    evt_button(@btn_6.get_id, :OnEvent)
    evt_button(btn.get_id, :OnClearList)
    evt_button(@btn_5.get_id, :OnEvent)
    m_checkPlayAnimation.evt_checkbox(static_box_3.get_id, :OnEvent))
    evt_checkbox(disable_bitmaps.get_id, :OnDisableBitmapsBtn)
    evt_checklistbox(@checkList2.get_id, :OnEvent)
    evt_checklistbox(@checkList_2.get_id, :OnEvent)
    evt_choice(@choice.get_id, :OnEvent)
    evt_choice(@choice2.get_id, :OnEvent)
    evt_colourpicker_changed(@colourPicker.get_id, :OnEvent)
    evt_combobox(@comboBox.get_id, :OnEvent)
    evt_combobox(@comboBox2.get_id, :OnEvent)
    evt_date_changed(@datePicker.get_id, :OnEvent)
    evt_dirpicker_changed(@dirPicker.get_id, :OnEvent)
    evt_filepicker_changed(@filePicker.get_id, :OnEvent)
    evt_fontpicker_changed(@fontPicker.get_id, :OnEvent)
    evt_init_dialog(:OnInit)
    evt_listbox(@listbox.get_id, :OnEvent)
    evt_listbox(@listBox2.get_id, :OnEvent)
    evt_notebook_page_changed(@notebook.get_id, :OnPageChanged)
    evt_radiobox(radioBox.get_id, :OnEvent)
    evt_radiobutton(@radioBtn_4.get_id, :OnEvent)
    evt_radiobutton(@radioBtn_2.get_id, :OnEvent)
    evt_radiobutton(@radioBtn_7.get_id, :OnEvent)
    evt_radiobutton(@radioBtn.get_id, :OnEvent)
    evt_radiobutton(@radioBtn_6.get_id, :OnEvent)
    evt_radiobutton(@radioBtn2.get_id, :OnEvent)
    evt_radiobutton(@radioBtn_5.get_id, :OnEvent)
    evt_radiobutton(@radioBtn_3.get_id, :OnEvent)
    evt_stc_change(@scintilla.get_id, :OnEvent)
    evt_text(@text_ctrl.get_id, :OnEvent)
    evt_text(@richText.get_id, :OnEvent)
    evt_time_changed(@timePicker.get_id, :OnEvent)
    evt_togglebutton(@toggleBtn.get_id, :OnEvent)
    evt_togglebutton(@toggleBtn_2.get_id, :OnEvent)
  end
# Event handler functions
# Add these below the comment block, or to your inherited class.

=begin
  def OnClearList(event)
    event.skip
  end

  def OnDisableBitmapsBtn(event)
    event.skip
  end

  def OnEvent(event)
    event.skip
  end

  def OnInit(event)
    event.skip
  end

  def OnPageChanged(event)
    event.skip
  end

  def OnPopupBtn(event)
    event.skip
  end

=end


  # Loads image from a string and returns a Wx::Animation object.
  def get_animation(image_name)
    animation = Wx::Animation.new
    animation.load(StringIO.new(image_name))
    return animation
  end
end

$clr_hourglass_gif = Base64.decode64(
  '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' +
  'b20vZ2lmd2l6YXJkLmh0bWwAOw==')

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************
