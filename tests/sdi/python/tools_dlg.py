###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

"""ToolBarsDialog class generated by wxUiEditor."""

import wx
import wx.aui
import wx.ribbon
rbn_tool1 = wx.ID_HIGHEST + 1
rbn_tool2 = wx.ID_HIGHEST + 2
rbn_tool3 = wx.ID_HIGHEST + 3
rbn_tool_art = wx.ID_HIGHEST + 4
rbn_tool_list = wx.ID_HIGHEST + 5
rbn_tool_svg = wx.ID_HIGHEST + 6

import zlib
import base64
import images
from wx.lib.embeddedimage import PyEmbeddedImage

left_svg = (
    b"eNqFlU1zmzAQhvtTNPTSztgbrSQkcOyc20OvPeRGw4eZYOMBmtb99V0hEgMytjwwyLt6tNLuK23bt+Jp"
    b"m2Z5y8p0F9gP1MiDh6dtwcrja/uSnLJN0dS/T4c6zXZBlZyzJriYquRXVu2C74ekyIKeURBABP34vicj"
    b"KQPWNcmxzevmsAsOSdeUf78gcINKRHrF6Ue92IQaV2sE+29o+s9Y6EjE8ivxTkm3Z213riiKtGxPFMmm"
    b"PFblMXvMy6rafObU8vyx7Zr6NVv/KdNuv0Gg6QXNT6H8YGIlItCSmmI/mTAgNDXDvjEJMu4bUxBZ24ef"
    b"5BOzYM/sQE7CzsZxxWcgA5rFwJ3VB1mzfh88oNChCfXGaMnSofYMQfXPDLK3Tsq9/rlYvChQwzAFGp8w"
    b"sSuK6HkBI7gLFZlAcvMwFztGtG2LGAVqwITXdndkl8sQGuOcJL+C+LDaMT2Er9a0t9ZVAi5RFISOQpHF"
    b"dzhIeV3icFADB2mFdzgK4gUO5UU6DuXN3OK81xdyiJZgAkRPYygpe8sw3tefza8GY2E68mkR4BBaDOFQ"
    b"PFeQVmRElG5i2hnogVdFdvELqUjvqmxEmqtsTrotszFrLLMpZVFnozg8nc0DuSW0EccT2pxzS2ljzlxp"
    b"HmdRamPKNPMeY5Zzd+zb4xnpQPfvhrTuWnuh3D3A89xi+866PiUvZXfe4PQ858CFirS6nOi0wyIcyoDi"
    b"c/Vja0lwI4w0FL5CFSqjnL4GZ2EmTtNlyBCNv44mS+0yHorhsVfnp/8jr5kh")

undo_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAACXBIWXMAAAsTAAALEwEAmpwYAAADdElE"
    b"QVRIx+2VT2hdRRTGf2dm3n33vveCtkqERGsTUzTd1IYuBMVautSlINiFUFDBohQpVFGhOxWhlG4siApi"
    b"QchCUJdKaUGKbkqKQpW26Z8YaVOTtEnz3r13Zo6Lm6QJSY3WleCBYc5l5nzf/c6cOQP/dZO1Ngwfn1Cd"
    b"C2hQVBUFUMAImhme33mf3BHBR9+MqZmjAtWlM8u/Ad8Q9j67Qf42waEvLmuY9fMAt4BWgM/7MYJpOd7Z"
    b"vVHWJDjw6ajGaV8Bzg8UQvSI2FtEUYkLZLGaZV3CwVcektsSvHh4RBvXE5Al4CI80F1QlIHfJ7Nlfx+X"
    b"gMdQ+cW9JUf3bV3EdcvYZlNuzJUVgQgI9Pd49ux6mEOfn2Umj/igtPNIJw/kRaQsFV9GQlAkKvWpZFlG"
    b"Fgl2vHVKJ690wAgYiAoDvZ7XXxgkSxPOjnc4NuIpfKVNFYiKxnkVIVaVdrnNlndHdeTNPlmh4MKVnJtF"
    b"ZK6I9PdE3n5piCxNUFU+eHWAoiwBCBFGxzt8eWKC4eNtSm/QYFAfiV6ZG7+5UsGlScf1q7OYmkGcwSSG"
    b"0pfkebXuQyAEXTy5rY+sY9vme3hyyxivfTiJ9wb1gvi4eorECbZuMTWDqRl+vWbYc/gXDr68kayesO/j"
    b"UU5esIuB3c2C93d189RQNzsenebYz4ZYClIuL0yz4NhEMHWLTS02c9jM8eNvKXs/ucj0jVlILK6V4rpS"
    b"XCvlD7o48t0keZEztCldjLGpW11BvdbG1i22biqixGISw+nphP3DVwkx4FoOkaqGNSq55JRlibGKazhi"
    b"EQjmNgpOv7dNbGqxqcNlDtewuIbDNRxn8rs5F9dTa9Wq0VWj1nJsH1DKouT8VMA13HysXV0BQFdfi3yy"
    b"qNJUt9jM0t+a4fH7FZHq0i1YbzMw9GAXY9dmOTmR4RoOMULS02Dkjb7VL9pPBzbJ4P4zalOHzSwuc2xY"
    b"LzyzOV3Rr0of+OHiDEfPN/HNBs4GxAh39SV/3YseO3JO21OmkpxZ0lpJs1ZinME4qVSoMhcshWkS8kDo"
    b"BHzbkzY93+/ukzW76ROfXdKiU+XfNWuLhy81gxiBqESvhCIQ2oHQ9lhbcOK5XvlHD872r6bVJgbbcLjU"
    b"YeoVgUYllpHQCcQ88O3Oltzxiwbw9KlSxRnESVWmVB3060Ej/G//1v4EvrC4VZwjYRAAAAAASUVORK5C"
    b"YII=")

redo_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAACXBIWXMAAAsTAAALEwEAmpwYAAADY0lE"
    b"QVRIx+2VTWgdVRTHf+fcO/Pe5IO0hQgtVWxNQaiQJrsitAqFbvxAoSAEBBdKRRCpi2xEilLqQkEsSEUs"
    b"biqI7sRlEUHRRbFQhNDWJLUxkaatiTXvvcybufe4mNfXpE2s1pXghcsMw5n/757PC//1JXcy+OTUZZNW"
    b"hGgg1Q8igjhBehwH9g7KXQHe/fyS+aZ1BDuiwoot3Wfsgecf2yp/G/DmiYsWl0pUbxVe8X4DTPXN9Xle"
    b"eeZeuSPg0PuTZgvtSqwDUAFR6QqbBZz6myHrbN3gOfzcNlkXMPb2GUuvJoiCOulC9BYvNm9qkSaOmfkU"
    b"zLoADJoDbT58ebir61cCZi5AvtjAVHBO8ImSJEItVeo1R1ZTvBO2+ISXxoZ45+NzTM15MBAzMEhcfe0Q"
    b"DR+dtktf/FxVhxPEaRUiFeiEB4TUC/tGPR+9PkqzlfPG8Ql+mvWoABGIxrW+yFdHRmSVB825Bpo61Avi"
    b"FXFC4iMH9mY8tWeQbVvqOK1s0yTBzMjqKa+98CBPvvoDU3NKT6r0pkp/X8KaIXJ1Rb0iXvHeeO/FQfbv"
    b"3kqIkcXrTUKo7EoN5HkOQFEWaKosm9BqBK4sFgxszNYB1ByaKJooj+6MPDJ6D6cnLjN+cp75Rtq1231/"
    b"4NjBIVp5m0MfXOT81RRfj8RCqmrzsp4HHk0rwOgOJW/nHD/1G9fox/fdqFEgXWbx+hLjJ3/l9Gwdl0XE"
    b"R8QFUMGl6wIcrqZVLlygKApyUZLepEq2gJnRCiXjn81zdrEf3xuJ7UhoB0Sr7qslrbUBPnNo6nB1x9RC"
    b"m6JdsHfImDzvkU6GzYzJsIlYSFc8+oA4IYiABM6+NXJ7H1w49pAMH5229u9tXOb47krG01eX2L+zn8G+"
    b"BWYb7uZJzDCDb38Rppb6CVoJA/RsyVb1wSoPBranLJyLuJqjrNc4cqbJ2PY/2LW5zi7vbptZM82cGavC"
    b"J6469I+Hd8hfzqKHT0zbcsPjM9/JiSONDXpcqGaFGbE0YhlpFAnLRUJoBcpmSbYx8v3BB+SO03TPp7MW"
    b"QorLPC5zuE4DooJFw4pIyCMhD5SNgrJZktZLvnn2PvlHF86+U0umtSrpmijSAcQ8Ui6XlM2S2I58/cQG"
    b"uesbDeDxiWgisiLHRlwOfDmSCP+vf7v+BCTXR/QXGtTnAAAAAElFTkSuQmCC")

# redo@2x.png
redo_2x_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAYAAABXAvmHAAAACXBIWXMAAAsTAAALEwEAmpwYAAAEoklE"
    b"QVRo3u2YXUwcVRTHf7Ozyy7Q3aUsiJQlLVBtmgpK0JhCYqAvpIoxfoUXbWoTPxIT01LaBPpgUrGtLV9F"
    b"jba2NW2sWE1Imxhj1fhkiKkNEhvjR2MbilILCWxZ2I9ZlvHh3q2zE0aIKSbu7nn575mZe2/2/z/3nHOv"
    b"wjKbt9D/GcBrHV2bAV55sVm5nfPb+J+bfbkXeKCufgVADIIALXu6RwC6X29ZnVHgv1DArio2gNpNm90A"
    b"318YVAF2tHWOAfTsb12VUWA5zaaIpHMzNAdAQXlNDkBurlsF2N52aBygd/+uOzIKLI8CqmJUYjY6D4Cz"
    b"8C4nwMb6FXkAuq5PAhw+sLtADp3PKLBE8wB4fMVNAKVl65oAKqvuuxvgwdracqGAZExSFokJgtXsOx0A"
    b"DzU2eeV8AalEofSjKa3Av+5Lcr1FDQDNzz53CmDLtpdKALLdeYpgWHwX0gTT0+E4ANqcDkB8XuBcXKL0"
    b"V6pBHWDw/LmwUGJXsVxyOrMHAMrWV/cAHOzqeQFgVUV1jsjzguHgdDyZYZlLdH1hySeCMYzjf7c5FYC6"
    b"h5/OEXtGuQHQs691jRxyIz0VKCipeB6g752TLwM480sdAEEZ26qkQpccSwEA8UOWgVuYyEIJ5hOW2Ath"
    b"3QVAVpZTBcj2eFYDhKen00+BbIDtO3buNTIflQzaRaG9FeO6/KHryZOY/Ynp2IKLbShxAnDp6080gDe7"
    b"99RJ5i+mZxYqXnPPIdHPNxUBBCKJmFeS8rhN+nk5YkqHXb6PRkSsa+L52JSW1BMlrNIvmB/+8mMNoLer"
    b"/X6A2OzspfTuhR59/Ml6AM3mVkR+n0vOTl6HiOk/fosAHD3y4WWA4aHvRgF8vvz1AO0HT5QBXA9oSfWg"
    b"0p8FwNAXZ6IAfW/srgKIadqvmW4UYG15eR5AMDInK6x4XuQVQwdOH7kOcOLY2y0AU2MjHxnHP/LU1m8A"
    b"/gxoZQAhGftVfqHcxfOC+a6OtnVihDaSOZEZ37k97hxj3s+yi/985afhEMC7hzu3AMzeHP9qoUlmZmbi"
    b"xi70Xr9Y8sLnZyLyfqhCfjqWORObzAkQDIXnAdwybXhlnn//g+M//hPzZqsoUAE41386LLrLnYmbuYnM"
    b"vZCFzQL8/MPQKMDamkafyEJiLwQCk6NLWWByclIFONt/MgTQu6/VL19N3ZZbj5SvA98ODvYBNDWPdwNE"
    b"HbkOAIdN0Yy3EoBqIkUB2NTQWC6Z32B6v1Ji3IRzJoyn7a1ElpHhjs73BgCqNzb4AAb6j00AHH/rwFaT"
    b"AqppbiXpaPY3WjGfOChoFr6WsgrYjPnfjB6PrxSgu+/oqwAutzsfYNszT3QBaOGZa6Z9pVooYMW4memo"
    b"hZ/ASMop4LRAV7JvzwNobd/7GMDlX66oAJ+ePTUEEI9rQdMeUk3Ma0thdgnP01aBZKypqfGJijvjBbh6"
    b"7aq8/NQ0096Km2LdHONWzFspMJtyCigWjGdZ+GZ0ALhcLgdAJBJRLOpBzEIRbYl7JGQcl9KVWDUpksS0"
    b"Ae0mtC1SJOdNaO55EuvOmFAz1ZPU74UWU8Zu0QMt2JUuwPxiXaieFueBvwBx6KjY2o3M3gAAAABJRU5E"
    b"rkJggg==")

class ToolBarsDialog(wx.Dialog):
    def __init__(self, parent, id=wx.ID_ANY, title="Test Dialog", pos=
                wx.DefaultPosition, size=wx.DefaultSize,
                style=wx.DEFAULT_DIALOG_STYLE, name=wx.DialogNameStr):
        wx.Dialog.__init__(self)

        if not self.Create(parent, id, title, pos, size, style, name):
            return

        box_sizer = wx.BoxSizer(wx.VERTICAL)

        self.tool_bar = wx.ToolBar(self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TB_HORIZONTAL)
        _svg_string_ = zlib.decompress(base64.b64decode(left_svg))
        tool_svg = self.tool_bar.AddTool(wx.ID_ANY, "",
            wx.BitmapBundle.FromSVG(_svg_string_, wx.Size(24, 24)))

        self.tool_bar.AddTool(wx.ID_ANY, "", wx.ArtProvider.GetBitmapBundle(wx.ART_CUT,
            wx.ART_TOOLBAR))

        self.tool_bar.AddTool(wx.ID_ANY, "", undo_png.Bitmap)

        self.tool_bar.AddTool(wx.ID_ANY, "", wx.BitmapBundle.FromBitmaps(redo_png.Bitmap,
            redo_2x_png.Bitmap))

        self.tool_bar.AddTool(wx.ID_ANY, "", wx.BitmapBundle.FromBitmaps([ images.
            wxPython_png.Bitmap,
                    images.wxPython_1_5x_png.Bitmap,
                    images.wxPython_2x_png.Bitmap ]))

        self.tool_bar.AddTool(wx.ID_ANY, "", wx.BitmapBundle.FromBitmaps([ images.
            fontPicker_png.Bitmap,
                    images.fontPicker_1_25x_png.Bitmap,
                    images.fontPicker_1_5x_png.Bitmap ]))

        self.tool_bar.Realize()
        box_sizer.Add(self.tool_bar, wx.SizerFlags().Border(wx.ALL))

        self.aui_tool_bar = wx.aui.AuiToolBar(self, wx.ID_ANY, wx.DefaultPosition,
            wx.DefaultSize, wx.aui.AUI_TB_PLAIN_BACKGROUND|wx.aui.AUI_TB_DEFAULT_STYLE)
        _svg_string_ = zlib.decompress(base64.b64decode(left_svg))
        self.aui_tool_bar.AddTool(wx.ID_ANY, "",
            wx.BitmapBundle.FromSVG(_svg_string_, wx.Size(24, 24)))
        self.aui_tool_bar.AddTool(wx.ID_ANY, "", wx.ArtProvider.GetBitmapBundle(wx.ART_CUT,
            wx.ART_TOOLBAR))
        self.aui_tool_bar.AddTool(wx.ID_ANY, "", wx.BitmapBundle.FromBitmaps(
            redo_png.Bitmap, redo_2x_png.Bitmap))
        self.aui_tool_bar.AddTool(wx.ID_ANY, "", wx.BitmapBundle.FromBitmaps([ images.
            wxPython_png.Bitmap,
                    images.wxPython_1_5x_png.Bitmap,
                    images.wxPython_2x_png.Bitmap ]))
        self.aui_tool_bar.AddTool(wx.ID_ANY, "", wx.BitmapBundle.FromBitmaps([ images.
            fontPicker_png.Bitmap,
                    images.fontPicker_1_25x_png.Bitmap,
                    images.fontPicker_1_5x_png.Bitmap ]))
        self.aui_tool_bar.Realize()
        box_sizer.Add(self.aui_tool_bar, wx.SizerFlags().Border(wx.ALL))

        self.rbnBar = wx.ribbon.RibbonBar(self, wx.ID_ANY)

        self.rbnBar.SetArtProvider(wx.ribbon.RibbonDefaultArtProvider())
        box_sizer.Add(self.rbnBar, wx.SizerFlags().Border(wx.ALL))

        rbnPage = wx.ribbon.RibbonPage(self.rbnBar, wx.ID_ANY, "Page 1")

        rbnPanel = wx.ribbon.RibbonPanel(rbnPage, wx.ID_ANY, "Page 1, panel 1")

        rbnToolBar = wx.ribbon.RibbonToolBar(rbnPanel, wx.ID_ANY)
        _svg_string_ = zlib.decompress(base64.b64decode(left_svg))
        rbnToolBar.AddTool(rbn_tool_svg,
            wx.BitmapBundle.FromSVG(_svg_string_,
            self.FromDIP(wx.Size(24, 24))).GetBitmap(wx.DefaultSize), "",
            wx.ribbon.RIBBON_BUTTON_NORMAL)
        rbnToolBar.AddTool(rbn_tool_art, wx.ArtProvider.GetBitmap(wx.ART_CUT,
            wx.ART_TOOLBAR), "", wx.ribbon.RIBBON_BUTTON_NORMAL)
        rbnToolBar.AddTool(rbn_tool1, wx.Bitmap(undo_png.Image.Rescale(
            self.FromDIP(24), self.FromDIP(24), wx.IMAGE_QUALITY_BILINEAR)), "",
            wx.ribbon.RIBBON_BUTTON_NORMAL)
        rbnToolBar.AddTool(rbn_tool2, wx.BitmapBundle.FromBitmaps(redo_png.Bitmap,
            redo_2x_png.Bitmap).GetBitmap(wx.Size(
            self.FromDIP(24), self.FromDIP(24))), "", wx.ribbon.RIBBON_BUTTON_NORMAL)
        rbnToolBar.AddTool(rbn_tool3, wx.BitmapBundle.FromBitmaps([ images.wxPython_png.Bitmap,
                    images.wxPython_1_5x_png.Bitmap,
                    images.wxPython_2x_png.Bitmap ])
            .GetBitmap(wx.Size(self.FromDIP(16), self.FromDIP(16))), "",
            wx.ribbon.RIBBON_BUTTON_NORMAL)
        rbnToolBar.AddTool(rbn_tool_list, wx.BitmapBundle.FromBitmaps([ images.
            fontPicker_png.Bitmap,
                    images.fontPicker_1_25x_png.Bitmap,
                    images.fontPicker_1_5x_png.Bitmap ])
            .GetBitmap(wx.Size(self.FromDIP(22), self.FromDIP(22))), "",
            wx.ribbon.RIBBON_BUTTON_NORMAL)
        rbnToolBar.Realize()

        self.SetSizer(box_sizer)
        self.SetMinSize(self.ConvertDialogToPixels(wx.Size(200, -1)))
        self.Fit()
        self.Centre(wx.BOTH)

        # Bind Event handlers
        self.Bind(wx.EVT_INIT_DIALOG, self.on_init)
        self.Bind(wx.EVT_TOOL, self.OnTool, id=tool_svg.GetId())

    # Event handler functions
    # Add these below the comment block, or to your inherited class.
    """
    def OnTool(self, event):
        event.Skip()

    def on_init(self, event):
        event.Skip()

    """

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

    def OnTool(self, event):
        event.Skip()

    def on_init(self, event):
        event.Skip()

