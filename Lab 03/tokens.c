#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isDelimiter(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n');
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

int isSpecialSymbol(char ch) {
    return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == ',');
}

int isKeyword(char *str) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"
    };

    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char filename[100];
    printf("Enter the name of the input file (including file extension, e.g., program.c):\n");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Token\t\tToken class\n");

    char ch;
    int numTokens = 0;
    while ((ch = fgetc(file)) != EOF) {
        char token[100];
        int tokenIdx = 0;

        // Skip delimiters
        while (isDelimiter(ch)) {
            ch = fgetc(file);
        }

        // Check for operators
        if (isOperator(ch)) {
            token[tokenIdx++] = ch;
            token[tokenIdx] = '\0';
            printf("%s\t\t%s\n", token, "Operator");
            numTokens++;
        }
        // Check for special symbols
        else if (isSpecialSymbol(ch)) {
            token[tokenIdx++] = ch;
            token[tokenIdx] = '\0';
            printf("%s\t\t%s\n", token, "Special Symbol");
            numTokens++;
        }
        // Check for identifiers or keywords
        else if (isalpha(ch) || ch == '_') {
            while (isalnum(ch) || ch == '_') {
                token[tokenIdx++] = ch;
                ch = fgetc(file);
            }
            token[tokenIdx] = '\0';

            if (isKeyword(token)) {
                printf("%s\t\t%s\n", token, "Keyword");
            } else {
                printf("%s\t\t%s\n", token, "Identifier");
            }
            numTokens++;
        }
        // Skip other characters
        else {
            ch = fgetc(file);
        }
    }

    printf("\nTotal number of tokens: %d\n", numTokens);

    fclose(file);

    return 0;
}

