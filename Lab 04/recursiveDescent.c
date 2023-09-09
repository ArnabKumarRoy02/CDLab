#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
int currentIndex = 0;
int backtrackingcount = 0;

void match(char c) {
    if (input[currentIndex] == c) {
        currentIndex++;
    }
    else {
        exit(1);
    }
}

void A() {
    int backtrackIndex = currentIndex;
    printf("Attempting A at Index = %d\n", currentIndex);
    if (input[currentIndex] == 'a') {
        match('a');
        if (input[currentIndex] == 'b') {
            match('b');
            printf("A -> ab\n");
        } 
        else if (input[currentIndex] == 'd') {
            match('d');
            printf("A -> ad\n");
        }
        else {
            printf("\nThe second character in the input string cannot be parsed with the given productions.\n");
        }
    } 
    else if (input[currentIndex] != 'a') {
        printf("\nThe production cannot derive the input string.\n");
    }
    else {
        currentIndex = backtrackIndex;
    }
}

void S() {
    int backtrackingindex = currentIndex;
    printf("\nBacktrack %d (S): Index = %d\n", backtrackingindex++, currentIndex);
    A();
    if (input[currentIndex] == 'h') {
        match('h');
        if (input[currentIndex] == 'd')  {
            match('d');
            printf("S -> Ahd\n");
        }
        else {
            printf("\nThe last character in the input string cannot be parsed with the given productions.\n");
        }
    }
    else if (input[2] != 'h') {
        printf("\nThe third character in the input string cannot be parsed with the given productions.\n");
    }
    else {
        currentIndex = backtrackingindex;
        printf("\nBacktrack from S to Index = %d\n", currentIndex);
    }
}

int main() {

    printf("Enter the input string: ");
    scanf("%s", input);
    input[strcspn(input, "\n")] = '\0';

    S();

    if (input[currentIndex] == '\0') {
        printf("\nString is accepted\n");
    }
    else {
        printf("\nString in not accepted\n");
    }

    return 0;
}