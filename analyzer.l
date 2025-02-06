/* Epilogi glwssas cpp, AEM:2118044, NAME:ISAIAS KONSTANTINOS, EMAIL:ikonstantinos@uth.gr, ikoctac@gmail.com
sum of my AEM: 2+1+1+8+0+4+4 = 20, 20 % 3 = 2 to opoio antistixi stin cpp*/
/* 1:Declarations{dilwseis}*/
%{ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// #include "tokens.h" /* include tokens.h to use the token ids, them before SA created the random numbers.*/
#include "syntax.tab.h" /* include syntax.tab.h to use the token ids */

// Function to print token details
void t_print(int t_id, int value);

// ICONST conversion functions
int integer_hexadecimal_to_decimal(const char *str);
int integer_octal_to_decimal(const char *str);
int integer_binary_to_decimal(const char *str);

// FCONST conversion functions
double convertExponentialPart(const char *str);
double convertFractionalPart(const char *fraction, int base);
double convertToFloat(const char *text);

// CCONST conversion function
int convertToChar(const char *text);

// SCONST conversion function
void convertToString(const char *text, char *result);

// YYSTYPE union for semantic values
/* Global Variables for Line Tracking */
char current_line[4096]; // Buffer to store the current line
int line_length = 0;     // Length of the current line

// typedef union {
//     int integer;         // For integer constants
//     double real;         // For floating-point constants
//     char str[4096];      // For string constants
//     char character;      // For character constants
// } YYSTYPE;

// YYSTYPE yylval; // Global variable for semantic values
%}

/* we are not handling multiple files so no need for yywrap to indicate end of input */
%option noyywrap

/* if we have something uppercase or lowercase it treats it the same way */
%option case-insensitive

/* tracks line of the current token, we will display it later to identify which line we are printing */
%option yylineno

/* 2:ID, created to match the {anagnwristika} detailed in the cpp.pdf file */
ID    [_]*[A-Za-z][A-Za-z0-9]*(_[A-Za-z0-9]+)*_?

/* 3:ICONST Rules */
ICONST  ("0"|[1-9][0-9]*|"0X"[1-9A-Fa-f][0-9A-Fa-f]*|"0O"[1-7][0-7]*|"0B"[1][0-1]*)

/* 4:FCONST,CCONST,SCONST created to match the iconsts detailed in the cpp.pdf file */
FCONST  ([1-9][0-9]*\.[0-9]+([Ee][+\-]?[0-9]+)?)|([0-9]+\.[0-9]+)|([0-9]+[Ee][+\-]?[0-9]+)|(0[Xx][0-9A-Fa-f]*\.[0-9A-Fa-f]+([Pp][+\-]?[0-9]+)?)|(0[Oo][0-7]*\.[0-7]+)|((0[Bb][0-1]*)?\.[0-1]+)

/* Character Constants (CCONST) */
CCONST  \'([^\\']|\\[nftbrv\\])\'

/* String Constants (SCONST) */
SCONST  \"([^"\\]|\\(.|\n))*\"

/* 5:listfunc */
LISTFUNC    C(AD*|D+)R

COMMENT   \/\*([^*]|\*+[^*/])*\*+\/

SINGLECOMMENT \/\/[^\n]*



%%

    /* 2:Rules{kanones}, rules are based on the cpp.pdf which is */
"TYPEDEF"    { t_print(T_TYPEDEF, 0); return T_TYPEDEF; }
"CHAR"       { t_print(T_CHAR, 0); return T_CHAR; }
"INT"        { t_print(T_INT, 0); return T_INT; }
"FLOAT"      { t_print(T_FLOAT, 0); return T_FLOAT; }
"STRING"     { t_print(T_STRING, 0); return T_STRING; }
"CLASS"      { t_print(T_CLASS, 0); return T_CLASS; }
"PRIVATE"    { t_print(T_PRIVATE, 0); return T_PRIVATE; }
"PROTECTED"  { t_print(T_PROTECTED, 0); return T_PROTECTED; }
"PUBLIC"     { t_print(T_PUBLIC, 0); return T_PUBLIC; }
"VOID"       { t_print(T_VOID, 0); return T_VOID; }
"STATIC"     { t_print(T_STATIC, 0); return T_STATIC; }
"UNION"      { t_print(T_UNION, 0); return T_UNION; }
"ENUM"       { t_print(T_ENUM, 0); return T_ENUM; }
"LIST"       { t_print(T_LIST, 0); return T_LIST; }
"CONTINUE"   { t_print(T_CONTINUE, 0); return T_CONTINUE; }
"BREAK"      { t_print(T_BREAK, 0); return T_BREAK; }
"IF"         { t_print(T_IF, 0); return T_IF; }
"ELSE"       { t_print(T_ELSE, 0); return T_ELSE; }
"WHILE"      { t_print(T_WHILE, 0); return T_WHILE; }
"FOR"        { t_print(T_FOR, 0); return T_FOR; }
"SWITCH"     { t_print(T_SWITCH, 0); return T_SWITCH; }
"CASE"       { t_print(T_CASE, 0); return T_CASE; }
"DEFAULT"    { t_print(T_DEFAULT, 0); return T_DEFAULT; }
"RETURN"     { t_print(T_RETURN, 0); return T_RETURN; }
"LENGTH"     { t_print(T_LENGTH, 0); return T_LENGTH; }
"NEW"        { t_print(T_NEW, 0); return T_NEW; }
"CIN"        { t_print(T_CIN, 0); return T_CIN; }
"COUT"       { t_print(T_COUT, 0); return T_COUT; }
"MAIN"       { t_print(T_MAIN, 0); return T_MAIN; }
"THIS"       { t_print(T_THIS, 0); return T_THIS; }
"SIZEOF"     { t_print(T_SIZEOP, 0); return T_SIZEOP; }

    /* 5:listfunc */
{LISTFUNC}    {
    strncpy(yylval.sval, yytext, sizeof(yylval.sval)); // Store the matched string
    t_print(T_LISTFUNC, 0);                          // Print the token details
    return T_LISTFUNC;                               // Return the token ID for LISTFUNC
}

    /* 3:aples statheres */
{ID}         { t_print(T_ID, 0); yylval.sval = strdup(yytext); return T_ID; }

{ICONST}    { 
    if (yytext[0] == '0' && yytext[1] == '\0') {
        yylval.ival = 0; // Special case for single '0'
    } else if (yytext[0] == '0' && (yytext[1] == 'X' || yytext[1] == 'x')) {
        yylval.ival = integer_hexadecimal_to_decimal(yytext); // Hexadecimal
    } else if (yytext[0] == '0' && (yytext[1] == 'O' || yytext[1] == 'o')) {
        yylval.ival = integer_octal_to_decimal(yytext); // Octal
    } else if (yytext[0] == '0' && (yytext[1] == 'B' || yytext[1] == 'b')) {
        yylval.ival = integer_binary_to_decimal(yytext); // Binary
    } else if (yytext[0] == '0' && yytext[1] >= '8') {
        printf("Invalid octal number: %s at line %d\n", yytext, yylineno);
        exit(1);
    } else {
        yylval.ival = atoi(yytext); // Decimal
    }
    t_print(T_ICONST, yylval.ival); // Pass the numeric value to t_print
    return T_ICONST; 
}

{FCONST}    { 
    yylval.fval = convertToFloat(yytext); // Convert the string to a floating-point number
    t_print(T_FCONST, 0);                // Pass 0 as a dummy value
    return T_FCONST; 
}

{CCONST}    { 
    yylval.cval = convertToChar(yytext); // Convert the character constant to its ASCII value
    t_print(T_CCONST, yylval.cval);      // Pass the ASCII value
    return T_CCONST; 
}

{SCONST}    { 
    convertToString(yytext, yylval.sval); // Process the string constant
    t_print(T_SCONST, 0);               // Pass 0 as a dummy value
    return T_SCONST; 
}

{COMMENT}   { /* MULTI-LINE comment */    }

{SINGLECOMMENT}   { /* Single-line comment */     }

    /* 4:operators{telestes} */
"||"         { t_print(T_OROP, 0); return T_OROP; }
"&&"         { t_print(T_ANDOP, 0); return T_ANDOP; }
"=="         { t_print(T_EQUOP, 0); return T_EQUOP; }
"!="         { t_print(T_EQUOP, 0); return T_EQUOP; }
">"          { t_print(T_RELOP, 0); return T_RELOP; }
">="         { t_print(T_RELOP, 0); return T_RELOP; }
"<"          { t_print(T_RELOP, 0); return T_RELOP; }
"<="         { t_print(T_RELOP, 0); return T_RELOP; }
"+"          { t_print(T_ADDOP, 0); return T_ADDOP; }
"-"          { t_print(T_ADDOP, 0); return T_ADDOP; }
"*"          { t_print(T_MULOP, 0); return T_MULOP; }
"/"          { t_print(T_MULOP, 0); return T_MULOP; }
"%"          { t_print(T_MULOP, 0); return T_MULOP; }
"!"          { t_print(T_NOTOP, 0); return T_NOTOP; }
"++"         { t_print(T_INCDEC, 0); return T_INCDEC; }
"--"         { t_print(T_INCDEC, 0); return T_INCDEC; }

    /* 6:alles lektikes monades */
"("          { t_print(T_LPAREN, 0); return T_LPAREN; }
")"          { t_print(T_RPAREN, 0); return T_RPAREN; }
";"          { t_print(T_SEMI, 0); return T_SEMI; }
"."          { t_print(T_DOT, 0); return T_DOT; }
","          { t_print(T_COMMA, 0); return T_COMMA; }
"="          { t_print(T_ASSIGN, 0); return T_ASSIGN; }
":"          { t_print(T_COLON, 0); return T_COLON; }
"["          { t_print(T_LBRACK, 0); return T_LBRACK; }
"]"          { t_print(T_RBRACK, 0); return T_RBRACK; }
"&"          { t_print(T_REFER, 0); return T_REFER; }
"{"          { t_print(T_LBRACE, 0); return T_LBRACE; }
"}"          { t_print(T_RBRACE, 0); return T_RBRACE; }
"::"         { t_print(T_METH, 0); return T_METH; }
">>"         { t_print(T_INP, 0); return T_INP; }
"<<"         { t_print(T_OUT, 0); return T_OUT; }




    /* Ignore whitespace */
[ \t] {
    if (line_length < sizeof(current_line) - 1) {
        current_line[line_length++] = yytext[0];
    }
}
    /* newline handles*/
[\n] {
    current_line[line_length] = '\0'; // Null-terminate the current line
    line_length = 0;                  // Reset line length for the next line
}

    /* Unknown tokens */
.|\n {
    // Print error message
    printf("Lexical Error: Invalid token '%s' at line %d\n", yytext, yylineno);

    // Attempt recovery by skipping the invalid character
    // Optionally, you can define a maximum number of errors before termination
    static int error_count = 0;
    if (++error_count > 10) { // Allow up to 10 errors
        printf("Too many lexical errors. Terminating lexer.\n");
        exit(1); // Terminate on excessive errors
    }

    // Continue lexing
}

    /* End of file */
<<EOF>>     { t_print(T_EOF, 0); return T_EOF; }

%%

/* 3:functions{sunartisis} */
/* Opening the file user provides */
/* int main(int argc, char *argv[]) {
    int token;
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            perror("Error opening file");
            return -1;
        }
    }
    do {
        token = yylex();
    } while (token != 0);
    fclose(yyin);
    yyterminate();
} */

/* Display where we found tokens what tokens we found and their number */
void t_print(int t_id, int value) {
    if (t_id == T_ICONST) {
        // Special case for ICONST: Print the numeric value
        printf("Found Token:%s, with t_id:{%d}, value:{%d}, at line:%d\n", yytext, t_id, yylval.ival, yylineno);
    } else if (t_id == T_FCONST) {
        // Special case for FCONST: Print the floating-point value
        printf("Found Token:%s, with t_id:{%d}, value:{%f}, at line:%d\n", yytext, t_id, yylval.fval, yylineno);
    } else if (t_id == T_CCONST) {
        // Special case for CCONST: Print the ASCII value
        printf("Found Token:%s, with t_id:{%d}, value:{%d}, at line:%d\n", yytext, t_id, yylval.cval, yylineno);
    } else if (t_id == T_SCONST) {
        // Special case for SCONST: Print the processed string
        printf("Found Token:%s, with t_id:{%d}, value:{%s}, at line:%d\n", yytext, t_id, yylval.sval, yylineno);
    } else if (t_id == T_LISTFUNC) {
        // Special case for LISTFUNC: Print the matched string
        printf("Found Token:%s, with t_id:{%d}, value:{%s}, at line:%d\n", yytext, t_id, yylval.sval, yylineno);
    } else {
        // Default case for other tokens
        printf("Found Token:%s, with t_id:{%d}, at line:%d\n", yytext, t_id, yylineno);
    }
}

/* Helper function to convert hexadecimal strings to decimal */
int integer_hexadecimal_to_decimal(const char *str) {
    return (int)strtol(str + 2, NULL, 16);
}

/* Helper function to convert octal strings to decimal */
int integer_octal_to_decimal(const char *str) {
    return (int)strtol(str + 2, NULL, 8);
}

/* Helper function to convert binary strings to decimal */
int integer_binary_to_decimal(const char *str) {
    return (int)strtol(str + 2, NULL, 2);
}

/* Helper function to convert exponential part */
double convertExponentialPart(const char *str) {
    return strtod(str, NULL); // Directly convert exponential notation
}

/* Helper function to convert fractional part */
double convertFractionalPart(const char *fraction, int base) {
    double result = 0.0;
    int len = strlen(fraction);
    for (int i = 0; i < len; i++) {
        if (fraction[i] >= '0' && fraction[i] <= '9') {
            result += (fraction[i] - '0') / pow(base, i + 1);
        } else if (fraction[i] >= 'A' && fraction[i] <= 'F') {
            result += (10 + fraction[i] - 'A') / pow(base, i + 1);
        } else if (fraction[i] >= 'a' && fraction[i] <= 'f') {
            result += (10 + fraction[i] - 'a') / pow(base, i + 1);
        }
    }
    return result;
}

/* Main function to convert a string to a floating-point number */
double convertToFloat(const char *text) {
    char *endPtr;
    double result = 0.0;

    // Check for hexadecimal floating-point numbers
    if (strncmp(text, "0x", 2) == 0 || strncmp(text, "0X", 2) == 0) {
        const char *dot = strchr(text, '.');
        if (dot) {
            // Integer part
            result = integer_hexadecimal_to_decimal(text);
            // Fractional part
            result += convertFractionalPart(dot + 1, 16);
        } else {
            result = integer_hexadecimal_to_decimal(text);
        }

        // Handle exponent part (hexadecimal uses P or p)
        const char *exp = strpbrk(text, "Pp");
        if (exp) {
            result *= pow(2, atoi(exp + 1)); // Hexadecimal exponents are base-2
        }
    }
    // Check for octal floating-point numbers
    else if (strncmp(text, "0o", 2) == 0 || strncmp(text, "0O", 2) == 0) {
        const char *dot = strchr(text, '.');
        if (dot) {
            // Integer part
            result = integer_octal_to_decimal(text);
            // Fractional part
            result += convertFractionalPart(dot + 1, 8);
        } else {
            result = integer_octal_to_decimal(text);
        }
    }
    // Check for binary floating-point numbers
    else if (strncmp(text, "0b", 2) == 0 || strncmp(text, "0B", 2) == 0) {
        const char *dot = strchr(text, '.');
        if (dot) {
            // Integer part
            result = integer_binary_to_decimal(text);
            // Fractional part
            result += convertFractionalPart(dot + 1, 2);
        } else {
            result = integer_binary_to_decimal(text);
        }
    }
    // Decimal floating-point numbers
    else {
        result = strtod(text, &endPtr);

        // Handle fractional part
        if (*endPtr == '.') {
            const char *fraction = endPtr + 1;
            if (strcmp(fraction, "0") != 0 && strspn(fraction, "0") == strlen(fraction)) {
                printf("Invalid fractional part: %s\n", text);
                exit(1); // Exit on invalid fractional part
            }
            result += convertFractionalPart(fraction, 10);
            endPtr = strchr(endPtr + 1, 'E'); // Move past the fractional part
        }

        // Handle exponential part
        if (endPtr && (*endPtr == 'E' || *endPtr == 'e')) {
            result *= pow(10, convertExponentialPart(endPtr + 1));
        }
    }

    return result;
}

/* Helper function to convert a character constant to its ASCII value */
int convertToChar(const char *text) {
    if (text[1] != '\\') {
        // Regular character (e.g., 'a', '1')
        return text[1];
    } else {
        // Escape sequence (e.g., '\n', '\t')
        switch (text[2]) {
            case 'n': return '\n'; // Line Feed
            case 'f': return '\f'; // Form Feed
            case 't': return '\t'; // Horizontal Tab
            case 'r': return '\r'; // Carriage Return
            case 'b': return '\b'; // Backspace
            case 'v': return '\v'; // Vertical Tab
            case '\\': return '\\'; // Backslash
            default: 
                printf("Invalid escape sequence: %s\n", text);
                exit(1); // Exit on invalid escape sequence
        }
    }
    return 0; // Should never reach here
}

/* Helper function to process a string constant */
void convertToString(const char *text, char *result) {
    int i = 0, j = 0;
    int len = strlen(text);

    // Skip the opening double quote
    i++;

    while (i < len - 1) { // Stop before the closing double quote
        if (text[i] == '\\') {
            i++; // Move past the backslash
            if (text[i] == '\n') {
                // Handle multi-line strings: skip the backslash and newline
                i++;
            } else {
                // Handle escape sequences
                switch (text[i]) {
                    case '"': result[j++] = '"'; break;  // Replace \" with "
                    case '\\': result[j++] = '\\'; break; // Replace \\ with \
                    case 'n': result[j++] = '\n'; break;  // Replace \n with newline
                    case 't': result[j++] = '\t'; break;  // Replace \t with tab
                    case 'r': result[j++] = '\r'; break;  // Replace \r with carriage return
                    case 'b': result[j++] = '\b'; break;  // Replace \b with backspace
                    case 'v': result[j++] = '\v'; break;  // Replace \v with vertical tab
                    default: 
                        // If it's an unknown escape sequence, keep the backslash and the character
                        result[j++] = '\\';
                        result[j++] = text[i];
                        break;
                }
                i++;
            }
        } else {
            // Regular character
            result[j++] = text[i++];
        }
    }

    // Null-terminate the result string
    result[j] = '\0';
}