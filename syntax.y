%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <string.h>
    #include "hashtbl.h"


    HASHTBL *hashtbl; /* Define hashtable */
     int scope = 0;
    int error_count = 0;
    extern FILE *yyin;
    extern int yylex();
    extern void yyterminate();
    void yyerror(const char *s);

    
%}


%union {
    int ival;
    float fval;
    char cval;
    char* sval;
}

%token  T_TYPEDEF    "typedef"
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
%token  <sval>     T_ID         "id"
%token  <ival>     T_ICONST     "iconst"
%token  <fval>     T_FCONST     "fconst"
%token  <cval>     T_CCONST     "cconst"
%token  <sval>     T_SCONST     "sconst"
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

%left T_COMMA //https://en.cppreference.com/w/c/language/operator_precedence
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

typedef_declaration : T_TYPEDEF typename listspec T_ID dims T_SEMI  { hashtbl_insert(hashtbl, $4, NULL, scope); }    
                    ;

typename : standard_type
         | T_ID         { hashtbl_insert(hashtbl, $1, NULL, scope); }
         ;

standard_type : T_CHAR | T_INT | T_FLOAT | T_STRING | T_VOID        {scope++; }
              ;

listspec : T_LIST | { }  
         ;

dims : dims dim
     | { }  
     ;

dim : T_LBRACK T_ICONST T_RBRACK 
    | T_LBRACK T_RBRACK
    ;

enum_declaration : T_ENUM T_ID enum_body T_SEMI                 { hashtbl_insert(hashtbl, $2, NULL, scope); }
                ;

enum_body : T_LBRACE id_list T_RBRACE
         ;

id_list : id_list T_COMMA T_ID initializer                      { hashtbl_insert(hashtbl, $3, NULL, scope); }
        | T_ID initializer                                      { hashtbl_insert(hashtbl, $1, NULL, scope); }
        ;

initializer : T_ASSIGN init_value
            | { }  
            ;

init_value : expression
           | T_LBRACE init_values T_RBRACE
           ;

expression : expression T_OROP expression
           | expression T_ANDOP expression
           | expression T_EQUOP expression
           | expression T_RELOP expression
           | expression T_ADDOP expression
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
         | variable T_DOT T_ID                                  { hashtbl_insert(hashtbl, $3, NULL, scope); }
         | T_LISTFUNC T_LPAREN general_expression T_RPAREN
         | decltype T_ID                                        { hashtbl_insert(hashtbl, $2, NULL, scope); }
         | T_THIS
         ;

general_expression : general_expression T_COMMA general_expression
                   | assignment
                   ;

assignment : variable T_ASSIGN assignment
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

class_declaration : T_CLASS T_ID class_body T_SEMI                  { hashtbl_insert(hashtbl, $2, NULL, scope); }       
                 ;

class_body : parent T_LBRACE members_methods T_RBRACE
           ;

parent : T_COLON T_ID                                               { hashtbl_insert(hashtbl, $2, NULL, scope); }
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
                                                                
variabledef : listspec T_ID dims                                { hashtbl_insert(hashtbl, $2, NULL, scope); }            
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

func_header_start : typename listspec T_ID                              { hashtbl_insert(hashtbl, $3, NULL, scope); }
                  ;

parameter_types : parameter_types T_COMMA typename pass_list_dims
                | typename pass_list_dims
                ;

pass_list_dims : T_REFER
               | listspec dims
               ;

nopar_func_header : func_header_start T_LPAREN T_RPAREN
                  ;

union_declaration : T_UNION T_ID union_body T_SEMI                  { hashtbl_insert(hashtbl, $2, NULL, scope); }
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

full_func_declaration : full_par_func_header T_LBRACE decl_statements T_RBRACE
                      | nopar_class_func_header T_LBRACE decl_statements T_RBRACE
                      | nopar_func_header T_LBRACE decl_statements T_RBRACE         {hashtbl_get(hashtbl, scope); scope--; }
                      ;

full_par_func_header : class_func_header_start T_LPAREN parameter_list T_RPAREN
                     | func_header_start T_LPAREN parameter_list T_RPAREN
                     ;

class_func_header_start : typename listspec func_class T_ID                 { hashtbl_insert(hashtbl, $4, NULL, scope); }
                        ;

func_class : T_ID T_METH                                                { hashtbl_insert(hashtbl, $1, NULL, scope); }
           ;

parameter_list : parameter_list T_COMMA typename pass_variabledef
               | typename pass_variabledef
               ;

pass_variabledef : variabledef
                 | T_REFER T_ID                                         { hashtbl_insert(hashtbl, $2, NULL, scope); }
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

if_statement : T_IF T_LPAREN general_expression T_RPAREN statement if_tail       { scope++; }
            ;

if_tail : T_ELSE statement
        | { } %prec LOWER_THAN_ELSE
        ;

while_statement : T_WHILE T_LPAREN general_expression T_RPAREN statement    { scope++; }
                ;

for_statement : T_FOR T_LPAREN optexpr T_SEMI optexpr T_SEMI optexpr T_RPAREN statement   { scope++; }
              ;

optexpr : general_expression
        | { }  
        ;

switch_statement : T_SWITCH T_LPAREN general_expression T_RPAREN switch_tail    { scope++; }
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

comp_statement : T_LBRACE decl_statements T_RBRACE      {hashtbl_get(hashtbl, scope); scope--; }
               ;

main_function : main_header T_LBRACE decl_statements T_RBRACE { hashtbl_get(hashtbl, scope); scope--; }
              ;

main_header : T_INT T_MAIN T_LPAREN T_RPAREN    {scope++; }
            ;


%%

int main(int argc, char *argv[]) {
    int token;

    if (!(hashtbl = hashtbl_create(10, NULL))){
    puts("Error, failed to initialize hashtable");
    exit(EXIT_FAILURE);
  }

    if (argc > 1) {
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
    hashtbl_destroy(hashtbl);
    return 0;
}

void yyerror(const char *s) {
    extern int yylineno;  // Provided by your lexer
    extern char current_line[];  // Provided by your lexer
    error_count++;  // Increment the error counter

    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Line: %s\n", current_line);

    if (error_count >= 5) {
        fprintf(stderr, "Too many syntax errors. Aborting parsing.\n");
        exit(1);  // Terminate the program after 5 errors
    }
}


