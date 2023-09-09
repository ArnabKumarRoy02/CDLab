#include <stdio.h>
#include <string.h>

// Function to check if a character is present in a string
int isCharinString(char c, char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (c == str[i])
			return 1;
	}
	return 0;
}

// Function to split the strings into tokens
int splitString(char *input, char tokens[][100], char delimiter) {
    	int tokenIndex = 0;
	int tokenCount = 0;

    	for (int i = 0; input[i] != '\0'; i++) {
        	if (input[i] == delimiter) {
            		tokens[tokenCount][tokenIndex] = '\0';
            		tokenCount++;
            		tokenIndex = 0;
        	} 
		else {
            		tokens[tokenCount][tokenIndex++] = input[i];
        	}
    	}

    	if (tokenIndex > 0) {
        	tokens[tokenCount][tokenIndex] = '\0';
        	tokenCount++;
    	}

    	return tokenCount;
}

// Function to detect and remove left recursion
void eliminateLeftRecursion(char *grammar) {
    	char productions[100][100];
    	int pCount = 0;

    	char tempGrammar[200];
    	strcpy(tempGrammar, grammar);

    	int tokenCount = splitString(tempGrammar, productions, '|');

    	for (int i = 0; i < tokenCount; i++) {
        	for (int j = 0; j < i; j++) {
            		if (productions[i][0] == productions[j][0]) {
                		printf("Grammar is left recursive.\n");

                		printf("\nOriginal Grammar:\n");
                		printf("%s\n\n", grammar);
                		printf("New Grammar after eliminating left recursion:\n");
                		
				for (int k = 0; k < tokenCount; k++) {
                    			if (productions[k][0] != productions[i][0]) {
                        			printf("S -> %s\n", productions[k]);
                    			}
                		}

                		printf("S -> ");
                		for (int k = 0; k < tokenCount; k++) {
                    			if (productions[k][0] == productions[i][0]) {
                        			printf("%sS' | ", productions[k] + 1);
                    			}
                		}
                		printf("ε\n");

                		return;
            		}
        	}
    	}

    	printf("Grammar is not left recursive.\n");
}

int main() {

	char grammer[200] = "S -> AB,A -> a|Abc,B -> Bc|d";

    	printf("Given Grammer:\n%s\n\n", grammer);

    	printf("Step 1:\n");
    	printf("Detecting and Eliminating Left Recursion:\n");
    	eliminateLeftRecursion(grammer);

	return 0;
}
