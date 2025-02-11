#include "ast.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <memory.h>

// Custom implementation of strdup
char* my_strdup(const char* str) {
    if (str == NULL) {
        return NULL;  // Handle the case where the input string is NULL.
    }
    size_t len = strlen(str) + 1;  // +1 for the null terminator.
    char* copy = (char*)malloc(len);  // Allocate memory.
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed for strdup\n");
        exit(EXIT_FAILURE);
    }
    memcpy(copy, str, len);  // Copy the string.
    return copy;
}

// Create a new AST node
struct ASTNode* createASTNode(ASTNodeType type, const char *value, int intValue, float floatValue, char charValue) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->value = value ? my_strdup(value) : NULL;  // Use my_strdup instead of strdup
    node->intValue = intValue;
    node->floatValue = floatValue;
    node->charValue = charValue;
    node->children = NULL;
    node->next = NULL;
    return node;
}

// Add a child to a node
void addChild(ASTNode *parent, ASTNode *child) {
    if (!parent || !child) {
        fprintf(stderr, "Invalid arguments for addChild\n");
        exit(EXIT_FAILURE);
    }
    if (!parent->children) {
        parent->children = child;
    } else {
        ASTNode *current = parent->children;
        while (current->next) {
            current = current->next;
        }
        current->next = child;
    }
}

// Add a sibling to a node
void addSibling(ASTNode *node, ASTNode *sibling) {
    if (!node || !sibling) {
        fprintf(stderr, "Invalid arguments for addSibling\n");
        exit(EXIT_FAILURE);
    }
    while (node->next) {
        node = node->next;
    }
    node->next = sibling;
}

// Print the AST
void printAST(ASTNode *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    switch (node->type) {
        case AST_PROGRAM: printf("Program\n"); break;
        case AST_GLOBAL_DECLARATIONS: printf("GlobalDeclarations\n"); break;
        case AST_GLOBAL_DECLARATION: printf("GlobalDeclaration\n"); break;
        case AST_TYPEDEF_DECLARATION: printf("TypedefDeclaration: %s\n", node->value); break;
        case AST_ENUM_DECLARATION: printf("EnumDeclaration: %s\n", node->value); break;
        case AST_CLASS_DECLARATION: printf("ClassDeclaration: %s\n", node->value); break;
        case AST_UNION_DECLARATION: printf("UnionDeclaration: %s\n", node->value); break;
        case AST_GLOBAL_VAR_DECLARATION: printf("GlobalVarDeclaration\n"); break;
        case AST_FUNC_DECLARATION: printf("FuncDeclaration\n"); break;
        case AST_TYPE_NAME: printf("TypeName: %s\n", node->value); break;
        case AST_STANDARD_TYPE: printf("StandardType: %d\n", node->intValue); break;
        case AST_LISTSPEC: printf("ListSpec: %d\n", node->intValue); break;
        case AST_DIMS: printf("Dims\n"); break;
        case AST_DIM: printf("Dim: %d\n", node->intValue); break;
        case AST_ENUM_BODY: printf("EnumBody\n"); break;
        case AST_ID_LIST: printf("IdList\n"); break;
        case AST_INITIALIZER: printf("Initializer\n"); break;
        case AST_INIT_VALUE: printf("InitValue\n"); break;
        case AST_EXPRESSION: printf("Expression: %d\n", node->intValue); break;
        case AST_VARIABLE: printf("Variable: %s\n", node->value); break;
        case AST_CONSTANT: printf("Constant: %d\n", node->intValue); break;
        case AST_EXPRESSION_LIST: printf("ExpressionList\n"); break;
        case AST_LISTEXPRESSION: printf("ListExpression\n"); break;
        case AST_INIT_VALUES: printf("InitValues\n"); break;
        case AST_CLASS_BODY: printf("ClassBody\n"); break;
        case AST_PARENT: printf("Parent: %s\n", node->value); break;
        case AST_MEMBERS_METHODS: printf("MembersMethods\n"); break;
        case AST_ACCESS: printf("Access: %d\n", node->intValue); break;
        case AST_MEMBER_OR_METHOD: printf("MemberOrMethod\n"); break;
        case AST_MEMBER: printf("Member\n"); break;
        case AST_ANONYMOUS_UNION: printf("AnonymousUnion\n"); break;
        case AST_UNION_BODY: printf("UnionBody\n"); break;
        case AST_FIELDS: printf("Fields\n"); break;
        case AST_FIELD: printf("Field\n"); break;
        case AST_METHOD: printf("Method\n"); break;
        case AST_SHORT_FUNC_DECLARATION: printf("ShortFuncDeclaration\n"); break;
        case AST_SHORT_PAR_FUNC_HEADER: printf("ShortParFuncHeader\n"); break;
        case AST_FUNC_HEADER_START: printf("FuncHeaderStart: %s\n", node->value); break;
        case AST_PARAMETER_TYPES: printf("ParameterTypes\n"); break;
        case AST_PASS_LIST_DIMS: printf("PassListDims\n"); break;
        case AST_NOPAR_FUNC_HEADER: printf("NoParFuncHeader\n"); break;
        case AST_FULL_FUNC_DECLARATION: printf("FullFuncDeclaration\n"); break;
        case AST_FULL_PAR_FUNC_HEADER: printf("FullParFuncHeader\n"); break;
        case AST_CLASS_FUNC_HEADER_START: printf("ClassFuncHeaderStart: %s\n", node->value); break;
        case AST_FUNC_CLASS: printf("FuncClass: %s\n", node->value); break;
        case AST_PARAMETER_LIST: printf("ParameterList\n"); break;
        case AST_PASS_VARIABLEDEF: printf("PassVariableDef\n"); break;
        case AST_NOPAR_CLASS_FUNC_HEADER: printf("NoParClassFuncHeader\n"); break;
        case AST_DECL_STATEMENTS: printf("DeclStatements\n"); break;
        case AST_DECLARATIONS: printf("Declarations\n"); break;
        case AST_DECLTYPE: printf("DeclType: %d\n", node->intValue); break;
        case AST_STATEMENTS: printf("Statements\n"); break;
        case AST_STATEMENT: printf("Statement\n"); break;
        case AST_EXPRESSION_STATEMENT: printf("ExpressionStatement\n"); break;
        case AST_IF_STATEMENT: printf("IfStatement\n"); break;
        case AST_IF_TAIL: printf("IfTail\n"); break;
        case AST_WHILE_STATEMENT: printf("WhileStatement\n"); break;
        case AST_FOR_STATEMENT: printf("ForStatement\n"); break;
        case AST_OPTEXPR: printf("OptExpr\n"); break;
        case AST_SWITCH_STATEMENT: printf("SwitchStatement\n"); break;
        case AST_SWITCH_TAIL: printf("SwitchTail\n"); break;
        case AST_DECL_CASES: printf("DeclCases\n"); break;
        case AST_CASESTATEMENTS: printf("CaseStatements\n"); break;
        case AST_CASESTATEMENT: printf("CaseStatement\n"); break;
        case AST_SINGLE_CASESTATEMENT: printf("SingleCaseStatement\n"); break;
        case AST_RETURN_STATEMENT: printf("ReturnStatement\n"); break;
        case AST_IO_STATEMENT: printf("IoStatement\n"); break;
        case AST_IN_LIST: printf("InList\n"); break;
        case AST_IN_ITEM: printf("InItem\n"); break;
        case AST_OUT_LIST: printf("OutList\n"); break;
        case AST_OUT_ITEM: printf("OutItem\n"); break;
        case AST_COMP_STATEMENT: printf("CompStatement\n"); break;
        case AST_MAIN_FUNCTION: printf("MainFunction\n"); break;
        case AST_MAIN_HEADER: printf("MainHeader\n"); break;
        default: printf("Unknown Node Type\n"); break;
    }
    printAST(node->children, level + 1);
    printAST(node->next, level);
}

// Free the AST
void freeAST(ASTNode *node) {
    if (!node) return;
    freeAST(node->children);
    freeAST(node->next);
    if (node->value) {
        free(node->value);
    }
    free(node);
}
