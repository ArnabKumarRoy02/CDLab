#include <stdio.h>
#include <ctype.h>
#include <string.h>

void findfirst(char, int, int);

int count = 8;
int n = 0;
char first[10];
char production[10][10];
char calc_first[10][100];
int k;

int main(int argc, char **argv) {
    int jm = 0;
    int i;
    char c;
    count = 8;

    strcpy(production[0], "E=TY");
    strcpy(production[1], "Y=+TY");
    strcpy(production[2], "Y=#");
    strcpy(production[3], "T=FX");
    strcpy(production[4], "X=*FX");
    strcpy(production[5], "X=#");
    strcpy(production[6], "F=i");
    strcpy(production[7], "F=(E)");

    int kay;
    char done[count];
    int ptr = -1;

    for (int k = 0; k < count; k++) {
        for (int kay = 0; kay < 100; kay++) {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0, point2, xxx;

    for (int k = 0; k < count; k++) {
        c = production[k][0];
        point2 = 0;
        xxx = 0;

        for (int kay = 0; kay <= ptr; kay++) {
            if (c == done[kay]) {
                xxx = 1;
            }
        }

        if (xxx == 1) {
            continue;
        }

        findfirst(c, 0, 0);
        ptr += 1;
        done[ptr] = c;
        printf("\n First(%c) = { ", c);
        calc_first[point1][point2++] = c;

        for (i = 0 + jm; i < n; i++) {
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
        jm = n;
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
            if (production[j][2] == '#') {
                if (production[q1][q2] == '\0') {
                    first[n++] = '#';
                } else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                    findfirst(production[q1][q2], q1, (q2 + 1));
                } else {
                    first[n++] = '#';
                }
            } else if (!isupper(production[j][2])) {
                first[n++] = production[j][2];
            } else {
                findfirst(production[j][2], j, 3);
            }
        }
    }
}

