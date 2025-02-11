#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the types of AST nodes
typedef enum {
    AST_PROGRAM,
    AST_GLOBAL_DECLARATIONS,
    AST_GLOBAL_DECLARATION,
    AST_TYPEDEF_DECLARATION,
    AST_ENUM_DECLARATION,
    AST_CLASS_DECLARATION,
    AST_UNION_DECLARATION,
    AST_GLOBAL_VAR_DECLARATION,
    AST_FUNC_DECLARATION,
    AST_TYPE_NAME,
    AST_STANDARD_TYPE,
    AST_LISTSPEC,
    AST_DIMS,
    AST_DIM,
    AST_ENUM_BODY,
    AST_ID_LIST,
    AST_INITIALIZER,
    AST_INIT_VALUE,
    AST_EXPRESSION,
    AST_VARIABLE,
    AST_CONSTANT,
    AST_EXPRESSION_LIST,
    AST_LISTEXPRESSION,
    AST_INIT_VALUES,
    AST_CLASS_BODY,
    AST_PARENT,
    AST_MEMBERS_METHODS,
    AST_ACCESS,
    AST_MEMBER_OR_METHOD,
    AST_MEMBER,
    AST_ANONYMOUS_UNION,
    AST_UNION_BODY,
    AST_FIELDS,
    AST_FIELD,
    AST_METHOD,
    AST_SHORT_FUNC_DECLARATION,
    AST_SHORT_PAR_FUNC_HEADER,
    AST_FUNC_HEADER_START,
    AST_PARAMETER_TYPES,
    AST_PASS_LIST_DIMS,
    AST_NOPAR_FUNC_HEADER,
    AST_FULL_FUNC_DECLARATION,
    AST_FULL_PAR_FUNC_HEADER,
    AST_CLASS_FUNC_HEADER_START,
    AST_FUNC_CLASS,
    AST_PARAMETER_LIST,
    AST_PASS_VARIABLEDEF,
    AST_NOPAR_CLASS_FUNC_HEADER,
    AST_DECL_STATEMENTS,
    AST_DECLARATIONS,
    AST_DECLTYPE,
    AST_STATEMENTS,
    AST_STATEMENT,
    AST_EXPRESSION_STATEMENT,
    AST_IF_STATEMENT,
    AST_IF_TAIL,
    AST_WHILE_STATEMENT,
    AST_FOR_STATEMENT,
    AST_OPTEXPR,
    AST_SWITCH_STATEMENT,
    AST_SWITCH_TAIL,
    AST_DECL_CASES,
    AST_CASESTATEMENTS,
    AST_CASESTATEMENT,
    AST_SINGLE_CASESTATEMENT,
    AST_RETURN_STATEMENT,
    AST_IO_STATEMENT,
    AST_IN_LIST,
    AST_IN_ITEM,
    AST_OUT_LIST,
    AST_OUT_ITEM,
    AST_COMP_STATEMENT,
    AST_MAIN_FUNCTION,
    AST_MAIN_HEADER
} ASTNodeType;

// Define the AST node structure
typedef struct ASTNode {
    ASTNodeType type;
    char *value;
    int intValue;
    float floatValue;
    char charValue;
    struct ASTNode *children;
    struct ASTNode *next;
} ASTNode;

// Function prototypes
struct ASTNode* createASTNode(ASTNodeType type, const char *value, int intValue, float floatValue, char charValue);
void addChild(ASTNode *parent, ASTNode *child);
void addSibling(ASTNode *node, ASTNode *sibling);
void printAST(ASTNode *node, int level);
void freeAST(ASTNode *node);

#endif // AST_H