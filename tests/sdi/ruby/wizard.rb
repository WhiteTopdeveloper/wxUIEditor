###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'

require_relative 'images'

class Wizard < Wx::Wizard
  def initialize(parent, id = Wx::ID_ANY, title = 'Wizard Tests',
                 bitmap = wxue_get_bundle($wiztest_png), pos =
                 Wx::DEFAULT_POSITION, style = Wx::DEFAULT_DIALOG_STYLE)

    super(parent, id, title, bitmap, pos, style)
    set_extra_style(get_extra_style() | Wx::WIZARD_EX_HELPBUTTON)
    set_border(15)

    wizPage = Wx::WizardPageSimple.new(self)

    box_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText = Wx::StaticText.new(wizPage, Wx::ID_ANY,
      'This is the first Wizard page')
    box_sizer.add(@staticText, Wx::SizerFlags.new.border(Wx::ALL))

    @calendar = Wx::CalendarCtrl.new(wizPage, Wx::ID_ANY, DateTime.now,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::CAL_SHOW_HOLIDAYS)
    box_sizer.add(@calendar, Wx::SizerFlags.new.border(Wx::ALL))
    wizPage.set_sizer_and_fit(box_sizer)

    wizPage2 = Wx::WizardPageSimple.new(self)

    box_sizer2 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText2 = Wx::StaticText.new(wizPage2, Wx::ID_ANY,
      'This is the second Wizard page which is wider.')
    box_sizer2.add(@staticText2, Wx::SizerFlags.new.border(Wx::ALL))

    parent_sizer3 = Wx::BoxSizer.new(Wx::VERTICAL)

    box_sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @staticText = Wx::StaticText.new(wizPage2, Wx::ID_ANY, 'Scrollbar:')
    box_sizer_2.add(@staticText, Wx::SizerFlags.new.border(Wx::ALL))

    @scrollBar = Wx::ScrollBar.new(wizPage2, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SB_HORIZONTAL)
    @scrollBar.set_scrollbar(0, 1, 100, 1)
    box_sizer_2.add(@scrollBar, Wx::SizerFlags.new(1).expand.border(Wx::ALL))

    parent_sizer3.add(box_sizer_2, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_3 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @staticText_2 = Wx::StaticText.new(wizPage2, Wx::ID_ANY, 'Normal SpinCtrl')
    box_sizer_3.add(@staticText_2, Wx::SizerFlags.new.border(Wx::ALL))

    @spinCtrl = Wx::SpinCtrl.new(wizPage2, Wx::ID_ANY, (''),
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SP_ARROW_KEYS, 0, 100, 4)
    box_sizer_3.add(@spinCtrl, Wx::SizerFlags.new.border(Wx::ALL))

    parent_sizer3.add(box_sizer_3, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_4 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @staticText_3 = Wx::StaticText.new(wizPage2, Wx::ID_ANY, 'Double SpinCtrl')
    box_sizer_4.add(@staticText_3, Wx::SizerFlags.new.border(Wx::ALL))

    @spinCtrlDouble = Wx::SpinCtrlDouble.new(wizPage2)
    box_sizer_4.add(@spinCtrlDouble, Wx::SizerFlags.new.border(Wx::ALL))

    parent_sizer3.add(box_sizer_4, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_5 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @staticText_4 = Wx::StaticText.new(wizPage2, Wx::ID_ANY, 'Spin Button')
    box_sizer_5.add(@staticText_4, Wx::SizerFlags.new.border(Wx::ALL))

    @spinBtn = Wx::SpinButton.new(wizPage2, Wx::ID_ANY)
    @spinBtn.set_range(0, 10)
    box_sizer_5.add(@spinBtn, Wx::SizerFlags.new.border(Wx::ALL))

    parent_sizer3.add(box_sizer_5, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer2.add(parent_sizer3, Wx::SizerFlags.new.border(Wx::ALL))
    wizPage2.set_sizer_and_fit(box_sizer2)

    wizPage3 = Wx::WizardPageSimple.new(self, nil, nil, wxue_get_bundle($wiztest2_png))

    box_sizer3 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText3 = Wx::StaticText.new(wizPage3, Wx::ID_ANY,
      'This is the final Wizard page')
    box_sizer3.add(@staticText3, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_6 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    @hyperlink = Wx::HyperlinkCtrl.new(wizPage3, Wx::ID_ANY, 'Blank Page',
      'https://blank.page/')
    box_sizer_6.add(@hyperlink, Wx::SizerFlags.new.center.border(Wx::ALL))

    @searchCtrl = Wx::SearchCtrl.new(wizPage3, Wx::ID_ANY, '')
    @searchCtrl.set_hint('Search for something...')
    @searchCtrl.show_search_button(true)
    @searchCtrl.show_cancel_button(true)
    box_sizer_6.add(@searchCtrl, Wx::SizerFlags.new(1).border(Wx::ALL))

    box_sizer3.add(box_sizer_6, Wx::SizerFlags.new.expand.border(Wx::ALL))
    wizPage3.set_sizer_and_fit(box_sizer3)

    wizPage.chain(wizPage2).chain(wizPage3)
    get_page_area_sizer().add(wizPage)
    center(Wx::BOTH)

    # Event handlers
    evt_init_dialog(:OnInit)
    evt_wizard_before_page_changed(:on_before_page_change)
  end
# Unimplemented Event handler functions
# Copy any listed and paste them below the comment block, or to your inherited class.

=begin
  def on_before_page_change(event)
    event.skip
  end

=end
end
# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

def on_before_page_change(event)
  event.skip
end

def OnInit(event)
  event.skip
end
