/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate Src and Hdr files for Base Class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <set>

#include "node_classes.h"  // Forward defintions of Node classes

#include "gen_enums.h"  // Enumerations for generators

class ProjectSettings;
class NodeCreator;
class WriteCode;
class wxWindow;

struct EmbededImage;

using EventVector = std::vector<NodeEvent*>;

namespace pugi
{
    class xml_node;
}

enum PANEL_TYPE : size_t
{
    NOT_PANEL,
    CPP_PANEL,
    HDR_PANEL,
};

namespace result
{
    // These enums are returned to indicate the result of generating a file
    enum
    {
        fail = -1,
        exists = 0,
        created = 1,
        ignored = 2,
        needs_writing = 3,
    };
}  // namespace result

int WriteCMakeFile(bool test_only = true);  // See gen_cmake.cpp

// If NeedsGenerateCheck is true, this will not write any files, but will return true if at
// least one file needs to be generated. If pClassList is non-null, it will contain the base
// class name over every form that needs updating.
bool GenerateCodeFiles(wxWindow* parent, bool NeedsGenerateCheck = false, std::vector<ttlib::cstr>* pClassList = nullptr);

#if defined(_DEBUG)
void GenerateTmpFiles(const std::vector<ttlib::cstr>& ClassList, pugi::xml_node root);
#endif  // _DEBUG

class BaseCodeGenerator
{
public:
    BaseCodeGenerator();

    void SetHdrWriteCode(WriteCode* cw) { m_header = cw; }
    void SetSrcWriteCode(WriteCode* cw) { m_source = cw; }

    void GenerateBaseClass(Node* project, Node* form_node, PANEL_TYPE panel_type = NOT_PANEL);

    // GenerateDerivedClass() is in gen_derived.cpp

    // Returns result::fail, result::exists, result::created, or result::ignored
    int GenerateDerivedClass(Node* project, Node* form_node, PANEL_TYPE panel_type = NOT_PANEL);

    auto GetHeaderWriter() { return m_header; }
    auto GetSrcWriter() { return m_source; }

    // Write code to m_source that will load any handlers needed by the form's class
    void GenerateHandlers();

protected:
    void WritePropSourceCode(Node* node, GenEnum::PropName prop);
    void WritePropHdrCode(Node* node, GenEnum::PropName prop);
    void GenCtxConstruction(Node* node);
    void AddPersistCode(Node* node);
    enum Permission
    {
        Protected,
        Public
    };

    ttlib::cstr GetDeclaration(Node* node);

    void CollectEventHandlers(Node* node, EventVector& events);
    void CollectIDs(Node* node, std::set<std::string>& set_ids);
    void CollectImageHeaders(Node* node, std::set<std::string>& embedset);
    void CollectIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr);
    void CollectMemberVariables(Node* node, Permission perm, std::set<std::string>& code_lines);
    void CollectValidatorVariables(Node* node, std::set<std::string>& code_lines);

    void GenerateClassHeader(Node* form_node, const EventVector& events);
    void GenerateClassConstructor(Node* form_node, const EventVector& events);

    void GenSrcEventBinding(Node* class_node, const EventVector& events);
    void GenHdrEvents(const EventVector& events);

    // Generates all the code lines for validator_variables initialized in the header file
    void GenValVarsBase(const NodeDeclaration* info, Node* node, std::set<std::string>& code_lines);

    // Recursive function for generating all get/set validator functions in the header file
    void GenValidatorFunctions(Node* node);

    // Recursive function for generating all include files needed by any nodes in the form
    void GatherGeneratorIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr);

    // Generates an enum of all use-defined ids
    void GenEnumIds(Node* class_node);

    // Determine if Header or Animation functions need to be generated, and whether the
    // wx/artprov.h is needed
    void ParseImageProperties(Node* class_node);

    // Generate node construction code
    void GenConstruction(Node* node);

    // This allows generators to create calls to a widget after it has been created.
    void GenSettings(Node* node);

    // Write everything in the set and then clear it
    void WriteSetLines(WriteCode* pDest, std::set<std::string>& code_lines);

    // Called after base class is fully constructed
    void GenContextMenuHandler(Node* form_node, Node* node_ctx_menu);

private:
    WriteCode* m_header;
    WriteCode* m_source;

    ttlib::cstr m_baseFullPath;
    EventVector m_CtxMenuEvents;

    std::vector<const EmbededImage*> m_embedded_images;
    std::set<wxBitmapType> m_type_generated;

    Node* m_form_node;

    PANEL_TYPE m_panel_type { NOT_PANEL };

    bool m_NeedArtProviderHeader { false };
    bool m_NeedHeaderFunction { false };
    bool m_NeedAnimationFunction { false };
};
