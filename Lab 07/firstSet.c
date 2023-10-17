#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char productions[MAX][MAX];
int n;
char non_terminals[MAX];
int num_non_terminals;
char first_sets[MAX][MAX];
int num_first_sets;
char follow_sets[MAX][MAX];
int num_follow_sets;

void remove_left_recursion(char non_terminal) {
    int i, j, k, l, m;
    char new_non_terminal[MAX], temp[MAX], tempprod[MAX];
    int flag = 0, consumed = 0;
    for (i = 0; i < n; i++) {
        if (productions[i][0] == non_terminal) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        strcpy(new_non_terminal, "A'");
        printf("%s->", new_non_terminal);
        for (j = 1; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == '|') {
                printf("|%s%s'", temp, new_non_terminal);
                strcpy(productions[n++], strcat(temp, new_non_terminal));
                memset(temp, 0, sizeof(temp));
                consumed = 0;
            } else {
                temp[consumed++] = productions[i][j];
            }
        }
        printf("|%s%s'\n", temp, new_non_terminal);
        strcpy(productions[n++], strcat(temp, new_non_terminal));
        for (i = 0; i < n - 1; i++) {
            if (productions[i][0] == non_terminal && productions[i][1] != '\'') {
                strcpy(temp, productions[i] + 1);
                printf("%s'->", new_non_terminal);
                for (j = 0; productions[i][j] != '\0'; j++) {
                    if (productions[i][j] == '|') {
                        printf("|%s%s'", temp, new_non_terminal);
                        strcpy(productions[n++], strcat(temp, new_non_terminal));
                        memset(temp, 0, sizeof(temp));
                        consumed = 0;
                    } else {
                        temp[consumed++] = productions[i][j];
                    }
                }
                printf("|%s%s'\n", temp, new_non_terminal);
                strcpy(productions[n++], strcat(temp, new_non_terminal));
            }
        }
    }
}

void remove_ambiguity() {
    int i, j, k, l, m;
    char temp[MAX];
    int num_new_non_terminals = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (productions[i][0] == productions[j][0]) {
                char new_non_terminal[MAX];
                sprintf(new_non_terminal, "%c%d", productions[i][0], ++num_new_non_terminals);
                printf("%s->%s%s'\n", new_non_terminal, productions[i] + 1, new_non_terminal);
                strcpy(productions[i], new_non_terminal);
                strcpy(productions[j], new_non_terminal);
            }
        }
    }
}

void compute_first_set(char non_terminal) {
    int i, j, k, l, m;
    char temp[MAX];
    for (i = 0; i < n; i++) {
        if (productions[i][0] == non_terminal) {
            if (!isupper(productions[i][2])) {
                strcpy(temp, productions[i] + 2);
                if (temp[0] == '#') {
                    strcpy(first_sets[num_first_sets++], "#");
                } else {
                    for (j = 0; temp[j] != '\0'; j++) {
                        if (!isupper(temp[j])) {
                            char str[2];
                            str[0] = temp[j];
                            str[1] = '\0';
                            strcpy(first_sets[num_first_sets++], str);
                            break;
                        } else {
                            compute_first_set(temp[j]);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int i, j, k, l, m;
    char temp[MAX];
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }
    for (i = 0; i < n; i++) {
        remove_left_recursion(productions[i][0]);
    }
    remove_ambiguity();
    for (i = 0; i < n; i++) {
        compute_first_set(productions[i][0]);
    }
    printf("First sets:\n");
    for (i = 0; i < num_first_sets; i++) {
        printf("First(%c) = { %s }\n", non_terminals[i], first_sets[i]);
    }
    return 0;
}
