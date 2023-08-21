#include <stdio.h>
#include <string.h>

// Transition table for all three conditions
int transition_table[][2] = {
    {1, 2}, // For a)
    {1, 3}, // For b)
    {1, 2}, // For c)
    {3, 3}
};

int check_accepted(char *str, int condition) {
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0; // Reject if character not in {0,1}
        }
        state = transition_table[state][str[i] - '0'];
    }
    
    // Check condition based on the provided parameter
    if (condition == 1) {
        return state == 1;
    } else if (condition == 2) {
        return state != 2;
    } else if (condition == 3) {
        return state == 1 || state == 2;
    } else {
        return 0;
    }
}

void display_transitions(char *str) {
    int state = 0;
    printf("State\tCharacter\tNext State\n");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%d\t%c\t\t%d\n", state, str[i], transition_table[state][str[i] - '0']);
        state = transition_table[state][str[i] - '0'];
    }
}

int main() {
    char str[100];
    int condition;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Select the condition:\n");
    printf("1. Odd number of 0's and even number of 1's\n");
    printf("2. No substring '001'\n");
    printf("3. 0's and 1's separated by 0 or 1\n");
    scanf("%d", &condition);

    if (check_accepted(str, condition)) {
        printf("Accepted\n");
        display_transitions(str);
    } else {
        printf("Rejected\n");
    }

    return 0;
}
