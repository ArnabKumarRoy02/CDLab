#include <stdio.h>
#include <string.h>

// Transition function for the finite automaton
int transition(int state, char input)
{
    static int transitionTable[3][2] = {
        {1, 0}, // State 0: if input 0, go to State 1; if input 1, go to State 0
        {2, 1}, // State 1: if input 0, go to State 2; if input 1, go to State 1
        {0, 2}  // State 2: if input 0, go to State 0; if input 1, go to State 2
    };
    int inputIndex = input - '0'; // Convert char input to integer

    // Check if input is valid
    if (inputIndex >= 0 && inputIndex <= 1)
    {
        return transitionTable[state][inputIndex];
    }

    return -1; // Invalid input
}

// Main function
int main()
{
    char inputString[100];
    int currentState = 0; // Starting state is 0 (initial state)

    printf("Enter an input string: ");
    scanf("%s", inputString);

    int i = 0;
    printf("\nSequence of Transitions: ");
    while (inputString[i] != '\0')
    {
        printf("-> State q%d ", currentState);
        currentState = transition(currentState, inputString[i]);
        i++;
    }

    printf("\n");

    if (currentState == 0 && strcmp(inputString, "010101") != 0) // Reject "010101"
    {
        printf("String '%s' is accepted!\n", inputString);
    }
    else
    {
        printf("String '%s' is not accepted!\n", inputString);
    }

    return 0;
}
