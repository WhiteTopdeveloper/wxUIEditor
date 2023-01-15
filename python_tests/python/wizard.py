###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

import wx
import wx.adv

import images

class Wizard(wx.adv.Wizard):

    def __init__(self, parent, id=wx.ID_ANY, title="Wizard Tests", pos=
                wx.DefaultPosition, style=wx.DEFAULT_DIALOG_STYLE):
        wx.adv.Wizard.__init__(self)

        self.SetExtraStyle(self.GetExtraStyle() | wx.adv.WIZARD_EX_HELPBUTTON)
        self.SetBorder(15)
        if not self.Create(parent, id, title, wx.BitmapBundle.FromBitmap(
            images.wiztest_png.Bitmap), pos, style):
            return

        wizPage = wx.adv.WizardPageSimple(self)

        box_sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.m_staticText = wx.StaticText(wizPage, wx.ID_ANY,
            "This is the first Wizard page")
        box_sizer.Add(self.m_staticText, wx.SizerFlags().Border(wx.ALL))
        wizPage.SetSizerAndFit(box_sizer)

        m_wizPage2 = wx.adv.WizardPageSimple(self)

        box_sizer2 = wx.BoxSizer(wx.HORIZONTAL)

        self.m_staticText2 = wx.StaticText(m_wizPage2, wx.ID_ANY,
            "This is the second Wizard page which is wider.")
        box_sizer2.Add(self.m_staticText2, wx.SizerFlags().Border(wx.ALL))
        m_wizPage2.SetSizerAndFit(box_sizer2)

        m_wizPage3 = wx.adv.WizardPageSimple(self, None, None, wx.BitmapBundle.FromBitmap(
            images.wiztest2_png.Bitmap))

        box_sizer3 = wx.BoxSizer(wx.HORIZONTAL)

        self.m_staticText3 = wx.StaticText(m_wizPage3, wx.ID_ANY,
            "This is the final Wizard page")
        box_sizer3.Add(self.m_staticText3, wx.SizerFlags().Border(wx.ALL))
        m_wizPage3.SetSizerAndFit(box_sizer3)

        wizPage.Chain(m_wizPage2).Chain(m_wizPage3)
        self.GetPageAreaSizer().Add(wizPage)
        self.Center(wx.BOTH)

        # Bind Event handlers
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInit)
        self.Bind(wx.adv.EVT_WIZARD_BEFORE_PAGE_CHANGED, self.OnBeforeChange)

    # Unimplemented Event handler functions
    # Copy any listed and paste them below the comment block, or to your inherited class.
    """
    """


    # Add the following below the comment block to add a simple
    # Run() function to launch the wizard
    """
    def Run(self):
        return self.RunWizard(self.GetPageAreaSizer().GetItem(0).GetWindow())
    """

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

    def OnInit(self, event):
        event.Skip()

    def OnBeforeChange(self, event):
        event.Skip()

    def Run(self):
        return self.RunWizard(self.GetPageAreaSizer().GetItem(0).GetWindow())
