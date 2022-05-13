/////////////////////////////////////////////////////////////////////////////
// Purpose:   Base widget generator class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <set>
#include <string>

#include "node_classes.h"  // Forward defintions of Node classes

class BaseCodeGenerator;
class MockupParent;
class NavPopupMenu;
class WriteCode;
class wxMouseEvent;
class wxObject;
class wxPropertyGridEvent;
class wxPropertyGridManager;
class wxWindow;

namespace pugi
{
    class xml_node;
}

namespace GenEnum
{
    enum GenCodeType : size_t
    {
        // Generate the name of the base class to use (e.g "wxWizard").
        code_base_class,
        // Generate the header declaration
        code_header,
        // Generate code after all children of the node have been created.
        code_after_children,
    };
}

using OptionalIncludes = std::optional<std::vector<std::string>>;

// This is the interface class that all generators derive from.
class BaseGenerator
{
public:
    BaseGenerator() {}
    virtual ~BaseGenerator() {}

    MockupParent* GetMockup();

    // Create an object to use in the Mockup panel (typically a sizer or widget).
    virtual wxObject* CreateMockup(Node* /*node*/, wxObject* /*parent*/) { return nullptr; }

    // Called after all children have been created
    virtual void AfterCreation(wxObject* /*wxobject*/, wxWindow* /*wxparent*/) {}

    // Generate the code used to construct the object
    virtual std::optional<ttlib::cstr> GenConstruction(Node*) { return {}; }

    // Return true if all construction and settings code was written to src_code
    virtual bool GenConstruction(Node*, BaseCodeGenerator* /* code_gen */) { return false; }

#if defined(XRC_ENABLED)
    // Generate object and all properties. Restore indendation, but do not add </object>.
    //
    // Return true if object was created
    virtual bool GenXRC(Node*, BaseCodeGenerator* /* code_gen */) { return false; }

    // Generate information about unsupported properties, writing to
    // code_gen->GetHeaderWriter().
    //
    // Return true if information was written
    virtual bool GenXRCInfo(Node*, BaseCodeGenerator* /* code_gen */) { return false; }
#endif // XRC_ENABLED


    // Return true if the Generic version of the control is being used.
    virtual bool IsGeneric(Node*) { return false; }

    // Generate specific additional code
    virtual std::optional<ttlib::cstr> GenAdditionalCode(GenEnum::GenCodeType /* command */, Node* /* node */) { return {}; }

    virtual std::optional<ttlib::cstr> GenEvents(NodeEvent*, const std::string&) { return {}; }
    virtual std::optional<ttlib::cstr> GenSettings(Node*, size_t&) { return {}; }

    // Add any required include files to base source and/or header file
    virtual bool GetIncludes(Node*, std::set<std::string>& /* set_src */, std::set<std::string>& /* set_hdr */)
    {
        return false;
    };

    // Return false if the entire Mockup contents should be recreated due to the property change
    virtual bool OnPropertyChange(wxObject*, Node*, NodeProperty*) { return false; }

    // Called while processing an wxEVT_PG_CHANGING event.
    virtual bool AllowPropertyChange(wxPropertyGridEvent*, NodeProperty*, Node*);

    // Bind wxEVT_LEFT_DOWN to this so that clicking on the widget will select it in the navigation panel
    void OnLeftClick(wxMouseEvent& event);

    // Get the Help menu item text
    virtual ttlib::cstr GetHelpText(Node*);

    // Get the HTML filename to browse to. Caller needs to supply the prefix.
    virtual ttlib::cstr GetHelpURL(Node*);

    // Change the enable/disable states in the Property Grid Panel based on the current
    // property.
    virtual void ChangeEnableState(wxPropertyGridManager*, NodeProperty*);

    // Call this to retrieve hint text for the property
    virtual std::optional<ttlib::cstr> GetHint(NodeProperty*);

    // Call this to use different help text then GetPropDeclaration()->GetDescription()
    virtual std::optional<ttlib::cstr> GetPropertyDescription(NodeProperty*) { return {}; }

    // Call this to convert wxWidgets constants to friendly names, and to fix conflicting bit
    // flags. Returns true if a change was made. Note that the change is *not* pushed to the
    // undo stack.
    virtual bool VerifyProperty(NodeProperty*);

    // If true, a control can be move left or right or into a new sizer. Override and return
    // false if the control can't do this (such as a book page).
    virtual bool CanChangeParent(Node* node);

    // Return true to automatically add submenu command to add child sizers.
    //
    // You will need to Bind to any commands you add.
    virtual bool PopupMenuAddCommands(NavPopupMenu*, Node*) { return false; }
};
