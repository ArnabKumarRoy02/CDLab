#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char productions[MAX][MAX] = {"S->aAbCD", "S->#", "A->ASD", "A->#", "B->SaC", "B->hC", "B->#", "C->Sf", "C->g", "D->aBD", "D->#"};
char nonTerminals[MAX] = "SABCD";
char terminals[MAX] = "abcdefgh";
char firstSets[MAX][MAX];
char followSets[MAX][MAX];
int numProductions = 11, numNonTerminals = 5, numTerminals = 8;

void findFirst(char);
void findFollow(char);
void printFirstSets();
void printFollowSets();

int main() {
    // Find the FIRST sets for each non-terminal
    for (int i = 0; i < numNonTerminals; i++) {
        findFirst(nonTerminals[i]);
    }

    // Find the FOLLOW sets for each non-terminal
    for (int i = 0; i < numNonTerminals; i++) {
        findFollow(nonTerminals[i]);
    }

    // Print the FIRST and FOLLOW sets
    printf("FIRST sets:\n");
    printFirstSets();
    printf("\nFOLLOW sets:\n");
    printFollowSets();

    return 0;
}

void findFirst(char nonTerminal) {
    int index = 0;
    for (int i = 0; i < numProductions; i++) {
        if (productions[i][0] == nonTerminal) {
            if (productions[i][2] == '#') {
                firstSets[index][0] = '#';
                index++;
            } else if (!isupper(productions[i][2])) {
                firstSets[index][0] = productions[i][2];
                index++;
            } else {
                for (int j = 2; j < strlen(productions[i]); j++) {
                    if (!isupper(productions[i][j])) {
                        firstSets[index][0] = productions[i][j];
                        index++;
                        break;
                    } else {
                        findFirst(productions[i][j]);
                        for (int k = 0; k < numNonTerminals; k++) {
                            if (nonTerminals[k] == productions[i][j]) {
                                for (int l = 0; l < strlen(firstSets[k]); l++) {
                                    if (firstSets[k][l] != '#') {
                                        firstSets[index][0] = firstSets[k][l];
                                        index++;
                                    }
                                }
                                if (!strchr(firstSets[k], '#')) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    firstSets[index][0] = '\0';
}

void findFollow(char nonTerminal) {
    int index = 0;
    if (nonTerminal == productions[0][0]) {
        followSets[index][0] = '$';
        index++;
    }
    for (int i = 0; i < numProductions; i++) {
        for (int j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == nonTerminal) {
                if (j == strlen(productions[i]) - 1) {
                    for (int k = 0; k < numNonTerminals; k++) {
                        if (productions[i][0] == nonTerminals[k]) {
                            findFollow(nonTerminals[k]);
                            for (int l = 0; l < numTerminals; l++) {
                                if (!strchr(followSets[k], terminals[l])) {
                                    followSets[k][index] = terminals[l];
                                    index++;
                                }
                            }
                        }
                    }
                } else {
                    for (int k = 0; k < numNonTerminals; k++) {
                        if (productions[i][j+1] == nonTerminals[k]) {
                            findFirst(productions[i][j+1]);
                            for (int l = 0; l < strlen(firstSets[k]); l++) {
                                if (firstSets[k][l] != '#') {
                                    if (!strchr(followSets[index], firstSets[k][l])) {
                                        followSets[index][index] = firstSets[k][l];
                                        index++;
                                    }
                                } else {
                                    if (j+1 == strlen(productions[i])-1) {
                                        for (int m = 0; m < numNonTerminals; m++) {
                                            if (productions[i][0] == nonTerminals[m]) {
                                                findFollow(nonTerminals[m]);
                                                for (int n = 0; n < numTerminals; n++) {
                                                    if (!strchr(followSets[m], terminals[n])) {
                                                        followSets[m][index] = terminals[n];
                                                        index++;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        findFollow(nonTerminal);
                                        for (int m = 0; m < strlen(followSets[index]); m++) {
                                            if (!strchr(followSets[index], followSets[index][m])) {
                                                followSets[index][index] = followSets[index][m];
                                                index++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    followSets[index][0] = '\0';
}

void printFirstSets() {
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FIRST(%c) = { ", nonTerminals[i]);
        for (int j = 0; j < strlen(firstSets[i]); j++) {
            printf("%c ", firstSets[i][j]);
        }
        printf("}\n");
    }
}

void printFollowSets() {
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FOLLOW(%c) = { ", nonTerminals[i]);
        for (int j = 0; j < strlen(followSets[i]); j++) {
            printf("%c ", followSets[i][j]);
        }
        printf("}\n");
    }
}