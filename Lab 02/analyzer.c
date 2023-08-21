#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Token types
typedef enum {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    SPECIAL_SYMBOL
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

// Function to classify tokens
TokenType classifyToken(char *lexeme) {
    // List of keywords
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    // List of operators
    char *operators[] = {"+", "-", "*", "/", "=", "==", "<", ">", "<=", ">=", "!="};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    // List of special symbols
    char *specialSymbols[] = {";", "{", "}", "(", ")", "\""};
    int numSpecialSymbols = sizeof(specialSymbols) / sizeof(specialSymbols[0]);

    // Check if lexeme is a keyword
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(lexeme, keywords[i]) == 0) {
            return KEYWORD;
        }
    }

    // Check if lexeme is an operator
    for (int i = 0; i < numOperators; i++) {
        if (strcmp(lexeme, operators[i]) == 0) {
            return OPERATOR;
        }
    }

    // Check if lexeme is a special symbol
    for (int i = 0; i < numSpecialSymbols; i++) {
        if (strcmp(lexeme, specialSymbols[i]) == 0) {
            return SPECIAL_SYMBOL;
        }
    }

    // Assume it's an identifier if none of the above
    return IDENTIFIER;
}

int main() {
    FILE *fp = fopen("sample.c", "r"); // Replace with your file name

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[1000];
    char *token;

    printf("Lexeme\t\tToken\t\tToken class\n");

    while (fgets(buffer, sizeof(buffer), fp)) {
        token = strtok(buffer, " \t\n(){}\";");
        
        while (token != NULL) {
            TokenType type = classifyToken(token);
            printf("%s\t\t<%d, \"%s\">\t", token, type, token);

            switch (type) {
                case IDENTIFIER:
                    printf("Identifier\n");
                    break;
                case KEYWORD:
                    printf("Keyword\n");
                    break;
                case OPERATOR:
                    printf("Operator\n");
                    break;
                case SPECIAL_SYMBOL:
                    printf("Special Symbol\n");
                    break;
                default:
                    printf("Unknown\n");
            }

            token = strtok(NULL, " \t\n(){}\";");
        }
    }

    fclose(fp);
    return 0;
}
