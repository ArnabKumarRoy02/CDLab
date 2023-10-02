#include <stdio.h>
#include <ctype.h>
#include <string.h>

void findfirst(char, int, int);

int count = 13;
int n = 0;
char first[13];
char production[13][13];
char calc_first[13][100];
int done[13]; // Added declaration for 'done' array

int main() {
    char c;
    int ptr = -1;

    strcpy(production[0], "S=aAbCD");
    strcpy(production[1], "S=#");
    strcpy(production[2], "A=A'");
    strcpy(production[3], "A'=SDA'");
    strcpy(production[4], "A'=#");
    strcpy(production[5], "B=SaC");
    strcpy(production[6], "B=hC");
    strcpy(production[7], "B=#");
    strcpy(production[8], "C=SfC'");
    strcpy(production[9], "C'=gC'");
    strcpy(production[10], "C'=#");
    strcpy(production[11], "D=aBD");
    strcpy(production[12], "D=#");

    for (int k = 0; k < count; k++) {
        for (int kay = 0; kay < 100; kay++) {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0, point2;

    for (int k = 0; k < count; k++) {
        c = production[k][0];
        point2 = 0;
        int xxx = 0;

        for (int kay = 0; kay <= ptr; kay++) {
            if (c == production[done[kay]][0]) {
                xxx = 1;
                break;
            }
        }

        if (xxx == 1) {
            continue;
        }

        findfirst(c, k, 2);
        ptr += 1;
        done[ptr] = k;
        printf("\n First(%c) = { ", c);

        calc_first[point1][point2++] = c;

        for (int i = 0; i < n; i++) {
            int lark = 0, chk = 0;

            for (lark = 0; lark < point2; lark++) {
                if (first[i] == calc_first[point1][lark]) {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0) {
                printf("%c, ", first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }
        printf("}\n");
        point1++;
    }
    printf("\n");
    printf("-----------------------------------------------\n\n");
}

void findfirst(char c, int q1, int q2) {
    int j;

    if (!(isupper(c))) {
        first[n++] = c;
    }
    for (j = 0; j < count; j++) {
        if (production[j][0] == c) {
            if (production[j][q2] == '\0') {
                if (production[q1][q2] == '\0') {
                    first[n++] = '#';
                } else {
                    findfirst(production[q1][q2], q1, q2 + 1);
                }
            } else if (!isupper(production[j][q2])) {
                first[n++] = production[j][q2];
            } else {
                findfirst(production[j][q2], j, 2);
            }
        }
    }
}

