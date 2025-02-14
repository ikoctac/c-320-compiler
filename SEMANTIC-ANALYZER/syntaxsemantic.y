%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <string.h>
    #include "hashtbl.h"
    #include "AST.h"
    #include "syntaxsemantic.tab.h"

    #define TYPE_INT    1
    #define TYPE_FLOAT  2
    #define TYPE_CHAR   3
    #define TYPE_STRING 4
    #define TYPE_VOID   5
    
    HASHTBL *hashtbl; /* define hashtable */ 
    int scope = 0;      //managing global scopes for the hashtable and the user to know where it ends 
    int error_count = 0;    //error counter
    extern FILE *yyin;      //file pointer for yyin defined in lex.yy.c, used to open the files
    extern int yylex();     //lexer function generated by flex returns integer tokens each time it is called representing different token types
    extern void yyterminate();  //used to stop lexer
    void yyerror(const char *s);    //custom error handler to terminate program when necessary
    /* Example definitions. You might refine these based on your type system. */

    int predicate_check_not_declared(char *id, int current_scope) {
    /* Assume hashtbl_get returns NULL if the identifier is not found in the given scope */
    return (hashtbl_get(hashtbl, current_scope) == NULL);
}

int predicate_check_type_compatibility(int type1, int type2) {
    /* Simple example: require that the types match exactly.
    You may want to allow promotion from int to float, etc. */
    return (type1 == type2);
}

int predicate_arithmetic_result(int type1, int type2) {
    if (type1 == type2) {
        return type1;  /* Same type => result is of that type */
    }
    /* Allow, for instance, mixing int and float by returning float */
    else if ((type1 == TYPE_INT && type2 == TYPE_FLOAT) ||
             (type1 == TYPE_FLOAT && type2 == TYPE_INT)) {
        return TYPE_FLOAT;
    }
    /* Otherwise, error. Return -1 to indicate type error */
    else {
        return -1;
    }
}

int lookupType(const char *typeName) {
    int type = hashtbl_lookup_type(hashtbl, typeName);
    if (type != 0) { // assuming 0 means "not found"
        return type;
    }
    /* Fallback for built-in types */
    if (strcmp(typeName, "int") == 0) {
        return TYPE_INT;
    } else if (strcmp(typeName, "float") == 0) {
        return TYPE_FLOAT;
    } else if (strcmp(typeName, "char") == 0) {
        return TYPE_CHAR;
    } else if (strcmp(typeName, "string") == 0) {
        return TYPE_STRING;
    } else if (strcmp(typeName, "void") == 0) {
        return TYPE_VOID;
    } else {
        fprintf(stderr, "Error: Unknown type name '%s'\n", typeName);
        exit(EXIT_FAILURE);
    }
}

void hashtbl_insert_debug(const char *id, int scope) {
        printf("Inserting '%s' into hashtable at scope %d...\n", id, scope);
        hashtbl_insert(hashtbl, id, NULL, scope);
    }

ASTNode* createASTNode(ASTNodeType type, const char *value, int intValue, float floatValue, char charValue);
void addChild(ASTNode *parent, ASTNode *child);
void addSibling(ASTNode *node, ASTNode *sibling);
void printAST(ASTNode *node, int level);
void freeAST(ASTNode *node);

%}

%union {
    int ival;      /* integer literal values or type codes */
    float fval;    /* floating point literal values */
    char cval;     /* character literal values */
    char* sval;    /* string literal values, identifier names, etc. */
    int type;      /* type information (e.g., TYPE_INT, TYPE_FLOAT, etc.) */
    ASTNode* astnode; /* AST node */
}
/* Token declarations … (your tokens remain unchanged) */





%token  T_TYPEDEF    "typedef"      //helps to identify specific words in grammar
%token  T_CHAR       "char"
%token  T_INT        "int"
%token  T_FLOAT      "float"
%token  T_STRING     "string"
%token  T_CLASS      "class"
%token  T_PRIVATE    "private"
%token  T_PROTECTED  "protected"
%token  T_PUBLIC     "public"
%token  T_VOID       "void"
%token  T_STATIC     "static"
%token  T_UNION      "union"
%token  T_ENUM       "enum"
%token  T_LIST       "list"
%token  T_CONTINUE   "continue"
%token  T_BREAK      "break"
%token  T_IF         "if"
%token  T_ELSE       "else"
%token  T_WHILE      "while"
%token  T_FOR        "for"
%token  T_SWITCH     "switch"
%token  T_CASE       "case"
%token  T_DEFAULT    "default"
%token  T_RETURN     "return"
%token  T_LENGTH     "length"
%token  T_NEW        "new"
%token  T_CIN        "cin"
%token  T_COUT       "cout"
%token  T_MAIN       "main"
%token  T_THIS       "this"
%token  <sval>     T_ID         "id"        //stores a string 
%token  <ival>     T_ICONST     "iconst"    //stores an integer
%token  <fval>     T_FCONST     "fconst"    //stores a float
%token  <cval>     T_CCONST     "cconst"    //stores a character
%token  <sval>     T_SCONST     "sconst"    //stores a string
%token  T_OROP       "||"
%token  T_ANDOP      "&&"
%token  T_EQUOP      "=="
%token  T_RELOP      ">"
%token  T_ADDOP      "+"
%token  T_MULOP      "*"
%token  T_NOTOP      "!"
%token  T_INCDEC     "++"
%token  T_SIZEOP     "sizeop"
%token  T_LISTFUNC   "listfunc"
%token  T_LPAREN     "("
%token  T_RPAREN     ")"
%token  T_SEMI       ";"
%token  T_DOT        "."
%token  T_COMMA      ","//comma
%token  T_ASSIGN     "="//assign
%token  T_COLON      ":"
%token  T_LBRACK     "["
%token  T_RBRACK     "]"
%token  T_REFER      "refer"
%token  T_LBRACE     "{"
%token  T_RBRACE     "}"
%token  T_METH       "meth"
%token  T_INP        "<<"
%token  T_OUT        ">>"
%token  T_EOF        0   "EOF" //end of file

/* Type declarations for expression-related nonterminals */
%type <astnode> program
%type <astnode> global_declarations
%type <astnode> global_declaration
%type <astnode> typedef_declaration
%type <astnode> typename
%type <type> standard_type
%type <ival> listspec
%type <astnode> dims
%type <astnode> dim
%type <astnode> enum_declaration
%type <astnode> enum_body
%type <astnode> id_list
%type <astnode> initializer
%type <astnode> init_value
%type <astnode> class_declaration
%type <astnode> class_body
%type <astnode> parent
%type <astnode> members_methods
%type <ival> access
%type <astnode> member_or_method
%type <astnode> member
%type <astnode> var_declaration
%type <astnode> variabledefs
%type <astnode> variabledef
%type <astnode> anonymous_union
%type <astnode> union_declaration
%type <astnode> union_body
%type <astnode> fields
%type <astnode> field
%type <astnode> method
%type <astnode> short_func_declaration
%type <astnode> short_par_func_header
%type <astnode> func_header_start
%type <astnode> parameter_types
%type <astnode> pass_list_dims
%type <astnode> nopar_func_header
%type <astnode> full_func_declaration
%type <astnode> full_par_func_header
%type <astnode> class_func_header_start
%type <astnode> func_class
%type <astnode> parameter_list
%type <astnode> pass_variabledef
%type <astnode> nopar_class_func_header
%type <astnode> global_var_declaration
%type <astnode> init_variabledefs
%type <astnode> init_variabledef
%type <astnode> expression
%type <astnode> general_expression
%type <astnode> assignment
%type <astnode> variable
%type <astnode> constant
%type <astnode> expression_list
%type <astnode> listexpression
%type <astnode> init_values
%type <astnode> statement
%type <astnode> expression_statement
%type <astnode> if_statement
%type <astnode> if_tail
%type <astnode> while_statement
%type <astnode> for_statement
%type <astnode> optexpr
%type <astnode> switch_statement
%type <astnode> switch_tail
%type <astnode> decl_cases
%type <astnode> casestatements
%type <astnode> casestatement
%type <astnode> single_casestatement
%type <astnode> return_statement
%type <astnode> io_statement
%type <astnode> in_list
%type <astnode> in_item
%type <astnode> out_list
%type <astnode> out_item
%type <astnode> comp_statement
%type <astnode> main_function
%type <astnode> main_header
%type <astnode> declarations
%type <astnode> decltype
%type <astnode> statements
%type <astnode> decl_statements

%left T_COMMA //https://en.cppreference.com/w/c/language/operator_precedence //proseteristikotita gia entoles opws kai theoria 
%right T_ASSIGN
%left T_OROP
%left T_ANDOP
%left T_EQUOP
%left T_RELOP
%left T_ADDOP
%left T_MULOP
%right T_NOTOP
%right T_SIZEOP
%right T_INCDEC
%left T_LPAREN
%left T_RPAREN
%left T_LBRACK
%left T_RBRACK
%left T_DOT
%left T_LISTFUNC
 
%nonassoc LOWER_THAN_ELSE  //shift/reduce sto state 305 to "if"
%nonassoc T_ELSE //https://en.cppreference.com/w/c/language/operator_precedence

%%

program: global_declarations main_function T_EOF
       | { } 
       ;

global_declarations: global_declarations global_declaration
                    | { }  
                    ;

global_declaration : typedef_declaration
                   | enum_declaration
                   | class_declaration
                   | union_declaration
                   | global_var_declaration
                   | func_declaration
                   ;
                                                                    
typedef_declaration : T_TYPEDEF typename listspec T_ID dims T_SEMI
                        {
                            printf("Processing typedef declaration for '%s'...\n", $4);
                            if (isDeclaredInScope(hashtbl, $4, scope)) {
                                yyerror("Variable already declared in the current scope");
                            } else {
                                hashtbl_insert_debug($4, scope);
                            }
                        }
                        ;


typename : standard_type
            | T_ID { 
                        hashtbl_insert_debug($1, scope);
                        $$ = lookupType($1);   /* lookupType converts a string into a type code */
                    }
                    ;

standard_type : T_CHAR   { $$ = TYPE_CHAR; }
              | T_INT    { $$ = TYPE_INT; }
              | T_FLOAT  { $$ = TYPE_FLOAT; }
              | T_STRING { $$ = TYPE_STRING; }
              | T_VOID   { $$ = TYPE_VOID; }
              ;

listspec : T_LIST { $$ = 1; }
         |           { $$ = 0; }
         ;

dims : dims dim
     | { }  
     ;

dim : T_LBRACK T_ICONST T_RBRACK 
    | T_LBRACK T_RBRACK
    ;

enum_declaration : T_ENUM T_ID enum_body T_SEMI
                    {
                    if (!predicate_check_not_declared($2, scope)) {
                        yyerror("Enum redeclaration: identifier already declared in current scope");
                    } else {
                        hashtbl_insert_debug($2, scope);
                    }
                    }
                    ;
                

enum_body : T_LBRACE id_list T_RBRACE
         ;

id_list : id_list T_COMMA T_ID initializer                      { hashtbl_insert_debug($3, scope);; }
        | T_ID initializer                                      { hashtbl_insert_debug($1, scope); }
        ;

initializer : T_ASSIGN init_value
            | { }  
            ;

init_value : expression                               //usualy after braces we change scope
           | T_LBRACE init_values T_RBRACE            {scope--; }
           ;

expression : expression T_OROP expression
           | expression T_ANDOP expression
           | expression T_EQUOP expression
           | expression T_RELOP expression
           | expression T_ADDOP expression
            {
                int resultType = predicate_arithmetic_result($1, $3);
                if (resultType == -1) {
                    yyerror("Type mismatch in addition operation");
                }
                $$ = resultType;
            }
           | expression T_MULOP expression
           | T_NOTOP expression
           | T_ADDOP expression
           | T_SIZEOP expression
           | T_INCDEC variable
           | variable T_INCDEC
           | variable
           | variable T_LPAREN expression_list T_RPAREN
           | T_LENGTH T_LPAREN general_expression T_RPAREN
           | T_NEW T_LPAREN general_expression T_RPAREN
           | constant
           | T_LPAREN general_expression T_RPAREN
           | T_LPAREN standard_type T_RPAREN
           | listexpression
           ;

variable : variable T_LBRACK general_expression T_RBRACK
         | variable T_DOT T_ID                                  { hashtbl_insert_debug($3, scope); }
         | T_LISTFUNC T_LPAREN general_expression T_RPAREN
         | decltype T_ID                                        { hashtbl_insert_debug($2, scope); }
         | T_THIS
         ;

general_expression : general_expression T_COMMA general_expression
                   | assignment
                   ;

assignment : variable T_ASSIGN assignment
            {
            if (!predicate_check_type_compatibility($1, $3)) {
                yyerror("Type mismatch in assignment");
            }
            /* Optionally, you could assign $$ the resulting type for later use */
            $$ = $1;  /* assuming the type of the assignment is that of the variable */
            }
            | expression
            ;

expression_list : general_expression
                | { }  
                ;

constant : T_CCONST | T_ICONST | T_FCONST | T_SCONST
         ;

listexpression : T_LBRACK expression_list T_RBRACK          
              ;

init_values : init_values T_COMMA init_value
            | init_value
            ;

class_declaration : T_CLASS T_ID class_body T_SEMI             
                    {
                    if (!predicate_check_not_declared($2, scope)) {
                        yyerror("Class redeclaration: identifier already declared in current scope");
                    } else {
                        hashtbl_insert_debug($2, scope);
                    }
                    }
                    ;

class_body : parent T_LBRACE members_methods T_RBRACE               {scope--; }
           ;

parent : T_COLON T_ID                                               { hashtbl_insert_debug($2, scope); }
       | { }  
       ;

members_methods : members_methods access member_or_method
                | access member_or_method
                ;
                                                //open scope for access
access : T_PRIVATE T_COLON                    { scope++; }
       | T_PROTECTED T_COLON                    { scope++; }
       | T_PUBLIC T_COLON                    { scope++; }
       | { }  
       ;

member_or_method : member
                 | method
                 ;

member : var_declaration
       | anonymous_union
       ;

/* --- Modified var_declaration with an error production --- */
var_declaration : typename variabledefs T_SEMI
                | typename variabledefs error { yyerror("Missing semicolon in variable declaration; recovering from error"); }
                ;

variabledefs : variabledefs T_COMMA variabledef
             | variabledef
             ;
                                                                
variabledef : listspec T_ID dims
                { // verifys that the parse first evaluates the predicate before inserting the variable, to check if it doesnt already exist
                if (!predicate_check_not_declared($2, scope)) {
                    yyerror("Variable redeclaration: identifier already declared in current scope");
                } else {
                    hashtbl_insert_debug($2, scope);
                }
                }
                ;
                                                                //open scope of declration of union type
anonymous_union : T_UNION union_body T_SEMI                     {scope++; }
                ;
                                                                //close scope of declration of union type
union_body : T_LBRACE fields T_RBRACE                          {hashtbl_get(hashtbl, scope); scope--; }
           ;

fields : fields field
       | field
       ;

field : var_declaration
      ;

method : short_func_declaration
       ;

short_func_declaration : short_par_func_header T_SEMI
                       | nopar_func_header T_SEMI
                       ;

short_par_func_header : func_header_start T_LPAREN parameter_types T_RPAREN
                      ;

func_header_start : typename listspec T_ID                           
                    {
                    if (!predicate_check_not_declared($3, scope)) {
                        yyerror("Function redeclaration: identifier already declared in current scope");
                    } else {
                        hashtbl_insert_debug($3, scope);
                    }
                    }
                    ;

parameter_types : parameter_types T_COMMA typename pass_list_dims
                | typename pass_list_dims
                ;

pass_list_dims : T_REFER
               | listspec dims
               ;

nopar_func_header : func_header_start T_LPAREN T_RPAREN
                  ;

union_declaration : T_UNION T_ID union_body T_SEMI
                    {
                    if (!predicate_check_not_declared($2, scope)) {
                        yyerror("Union redeclaration: identifier already declared in current scope");
                    } else {
                        hashtbl_insert_debug($2, scope);
                    }
                    }
                    ;


global_var_declaration : typename init_variabledefs T_SEMI
                       ;

init_variabledefs : init_variabledefs T_COMMA init_variabledef
                  | init_variabledef
                  ;

init_variabledef : variabledef initializer
                 ;

func_declaration : short_func_declaration
                 | full_func_declaration
                 ;

full_func_declaration : full_par_func_header T_LBRACE { scope++; } decl_statements T_RBRACE { hashtbl_get(hashtbl, scope); scope--; }
                      | nopar_class_func_header T_LBRACE { scope++; } decl_statements T_RBRACE { hashtbl_get(hashtbl, scope); scope--; }
                      | nopar_func_header T_LBRACE { scope++; } decl_statements T_RBRACE { hashtbl_get(hashtbl, scope); scope--; }
                      ;

full_par_func_header : class_func_header_start T_LPAREN parameter_list T_RPAREN
                     | func_header_start T_LPAREN parameter_list T_RPAREN
                     ;

class_func_header_start : typename listspec func_class T_ID                 { hashtbl_insert_debug($4, scope); }
                        ;

func_class : T_ID T_METH                                                { hashtbl_insert_debug($1, scope); }
           ;

parameter_list : parameter_list T_COMMA typename pass_variabledef
               | typename pass_variabledef
               ;

pass_variabledef : variabledef
                 | T_REFER T_ID                                         { hashtbl_insert_debug($2, scope); }
                 ;

nopar_class_func_header : class_func_header_start T_LPAREN T_RPAREN
                        ;

decl_statements : declarations statements
                | declarations
                | statements
                | { /*empty*/}  
                ;

declarations : declarations decltype typename variabledefs T_SEMI   {scope++; }
             | decltype typename variabledefs T_SEMI
             ;

decltype : T_STATIC 
         | { }  
         ;

statements : statements statement           
           | statement
           ;

statement : expression_statement            
          | if_statement                    
          | while_statement                 
          | for_statement                   
          | switch_statement               
          | return_statement                
          | io_statement                    
          | comp_statement                  
          | T_CONTINUE T_SEMI               
          | T_BREAK T_SEMI                  
          | T_SEMI
          ;

 /* --- Modified expression_statement with an error production --- */
expression_statement : general_expression T_SEMI
                     | error T_SEMI { yyerror("Invalid expression statement; recovering from error"); }
                     ;

if_statement : T_IF T_LPAREN general_expression T_RPAREN { scope++; } 
                statement if_tail { 
                                    /* Here you could add a predicate to check that all identifiers used in this scope are valid */
                                    /* For example: predicate_verify_scope(scope); */
                                    hashtbl_get(hashtbl, scope); scope--; 
                                }
                                ;
if_tail : T_ELSE statement
        | { } %prec LOWER_THAN_ELSE     //solves dangling else problem
        ;

while_statement : T_WHILE T_LPAREN general_expression T_RPAREN { scope++; } statement { hashtbl_get(hashtbl, scope); scope--; }
                ;

for_statement : T_FOR T_LPAREN optexpr T_SEMI optexpr T_SEMI optexpr T_RPAREN { scope++; } statement { hashtbl_get(hashtbl, scope); scope--; }
              ;

optexpr : general_expression
        | { }  
        ;

switch_statement : T_SWITCH T_LPAREN general_expression T_RPAREN { scope++; } switch_tail { hashtbl_get(hashtbl, scope); scope--; }
                 ;

switch_tail : T_LBRACE decl_cases T_RBRACE  {hashtbl_get(hashtbl, scope); scope--; }
            | single_casestatement
            ;

decl_cases : declarations casestatements
           | declarations
           | casestatements
           | { }  
           ;

casestatements : casestatements casestatement   {scope++; }
               | casestatement
               ;

casestatement : T_CASE constant T_COLON casestatement
              | T_CASE constant T_COLON statements
              | T_DEFAULT T_COLON statements
              ;

single_casestatement : T_CASE constant T_COLON single_casestatement
                     | T_CASE constant T_COLON statement
                     ;

return_statement : T_RETURN optexpr T_SEMI
                 ;

io_statement : T_CIN T_INP in_list T_SEMI
             | T_COUT T_OUT out_list T_SEMI
             ;

in_list : in_list T_INP in_item
        | in_item
        ;

in_item : variable
        ;

out_list : out_list T_OUT out_item
         | out_item
         ;

out_item : general_expression
         ;

comp_statement : T_LBRACE { scope++; } decl_statements T_RBRACE { hashtbl_get(hashtbl, scope); scope--; }
               ;

main_function : main_header T_LBRACE { scope++; } decl_statements T_RBRACE { hashtbl_get(hashtbl, scope); scope--; }
              ;

main_header : T_INT T_MAIN T_LPAREN T_RPAREN { scope++; }
            ;


%%

int main(int argc, char *argv[]) { // Main function
    int token;

    if (!(hashtbl = hashtbl_create(10, NULL))){ //initialize hashtable
    puts("Error, failed to initialize hashtable");
    exit(EXIT_FAILURE);
  }
  int scope =0;

    if (argc > 1) { // Check if an input file is provided
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            perror("Error opening file");
            return -1;
        }
    } else {
        fprintf(stderr, "No input file provided.\n");
        return -1;
    }

    yyparse();  // Call the parser

    fclose(yyin);  // Close the file after parsing
    hashtbl_get(hashtbl, scope); //get the hashtable
    hashtbl_destroy(hashtbl);
    return 0;
}

void yyerror(const char *s) {
    extern int yylineno;  // lexer input line number
    extern char current_line[];  // lexer input line
    error_count++;  // error counter

    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);  //print error message

    if (error_count >= 5) {
        fprintf(stderr, "Too many syntax errors. Aborting parsing.\n");
        exit(1);  // terminate program
    }
}


