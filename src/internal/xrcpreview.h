////////////////////////////////////////////////////////////////////////////
// Original Code generated by wxUiEditor
//
// The code is generated only once. You can now modify the code as needed.
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "xrcpreview_base.h"

class XrcPreview : public XrcPreviewBase
{
public:
    XrcPreview();  // If you use this constructor, you must call Create(parent)
    XrcPreview(wxWindow* parent);

protected:
    void OnInit(wxInitDialogEvent& event) override;
    void OnXrcCopy(wxCommandEvent& event) override;
    void OnClipBoard(wxCommandEvent& event) override;
    // Handlers for XrcPreviewBase events
    void OnCreate(wxCommandEvent& WXUNUSED(event)) override;
    void OnPreview(wxCommandEvent& WXUNUSED(event)) override;
};
