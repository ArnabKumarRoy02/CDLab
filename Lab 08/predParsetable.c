/*
Write a program to construct the predictive parsing table for a grammar (assuming a grammar).

Input: 
• Grammar without left recursion
• First set () and Follow set () of the grammar

Output:
• Generate the parsing table

Consider the grammar:
A->aBa
B->bB | @

Input string: abba
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY ""

char prod[3][10] = {"A->aBa", "B->bB", "B->@"};
char first[3][10] = {"a", "b", "@"};
char follow[3][10] = {"$", "a", "a"};
char table[3][4][10];

char input[10], stack[25], curp[20];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

void pop() {
    top--;
}

void display() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%c", stack[i]);
    }
}

int numr(char c) {
    switch(c) {
        case 'A': return 1;
        case 'B': return 2;
        case 'a': return 1;
        case 'b': return 2;
        case '@': return 3;
    }
    return 1;
}

int main() {

    char c;
    int i, j, k, n;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            strcpy(table[i][j], EMPTY);
        }
    }

    printf("\nGrammar without left recursion\n");

    for (i = 0; i < 3; i++) {
        printf("%s\n", prod[i]);
    }

    printf("\nFirst Set\n");

    for (i = 0; i < 3; i++) {
        printf("First(%c) = %s\n", prod[i][0], first[i]);
    }

    printf("\nFollow Set\n");

    for (i = 0; i < 3; i++) {
        printf("Follow(%c) = %s\n", prod[i][0], follow[i]);
    }

    printf("\nPredictive Parsing Table for the given grammar\n");

    strcpy(table[0][0], "");
    strcpy(table[0][1], "a");
    strcpy(table[0][2], "b");
    strcpy(table[0][3], "$");
    strcpy(table[1][0], "A");
    strcpy(table[2][0], "B");

    for (i = 0; i < 3; i++) {
        if (first[i][0] != '@') {
            strcpy(table[numr(prod[i][0])][numr(first[i][0])], prod[i]);
        }
        else {
            strcpy(table[numr(prod[i][0])][numr(follow[i][0])], prod[i]);
        }
    }

    printf("\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%s\t", table[i][j]);
            if (j == 3) printf("\n");
        }
        printf("--------------------------\n");
    }

    printf("\nEnter the input string terminated with $ to parse: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++) {
        if ((input[i] != 'a') && (input[i] != 'b') && (input[i] != '$'))  {
            printf("\nInvalid string\n");
            exit(0);
        }
    }

    if (input[i - 1] != '$') {
        printf("\nInput String entered without $ termination.\n");
        exit(0);
    }

    push('$');
    push('A');
    i = 0;

    printf("\n");
    printf("Stack\t\tInput\t\tAction\n");
    printf("--------------------------------------------------------\n");
    
    while (input[i] != '$' && stack[top] != '$') {
        display();
        printf("\t\t%s\t", (input + i));

        if (stack[top] == input[i]) {
            printf("\tMatched %c\n", input[i]);
            pop();
            i++;
        }

        else {
            if (stack[top] >= 65 && stack[top] < 92) {
                strcpy(curp, table[numr(stack[top])][numr(input[i])]);
                if (!(strcmp(curp, "e"))) {
                    printf("\nInvalid String - Rejected\n");
                    exit(0);
                }
                else {
                    printf("\tApply Production %s\n", curp);
                    if (curp[3] == '@') 
                    pop();
                    else {
                        pop();
                        n = strlen(curp);
                        for (j = n - 1; j >= 3; j--) {
                            push(curp[j]);
                        }
                    }
                }
            }
        }

        display();
        
        printf("\t\t%s\n", (input + i));

        
    }
    if (stack[top] == '$' && input[i] == '$') {
        printf("\nValid String - Accepted\n");
    }
    else {
        printf("\nInvalid String - Rejected\n");
    }

    return 0;
}