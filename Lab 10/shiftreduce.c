#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int z = 0, i = 0, j = 0, c = 0;

char a[16], ac[20], stk[15], act[10]; 

void check()
{
	strcpy(ac,"REDUCE TO B -> "); 
	for(z = 0; z < c; z++) 
	{
		if(stk[z] == 'd') 
		{
			printf("%sd", ac);
			stk[z] = 'B';
			stk[z + 1] = '\0';
			
			printf("\n$%s\t%s$\t", stk, a); 
		}
	}

    strcpy(ac,"REDUCE TO A -> "); 
		
	for(z = 0; z < c - 2; z++)
	{
		if(stk[z] == 'A' && stk[z + 1] == 'b' && 
								stk[z + 2] == 'c') 
		{
			printf("%sAbc", ac);
			stk[z] = 'A';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
		
	}

    strcpy(ac,"REDUCE TO S -> "); 
	
	for(z = 0; z < c; z++) 
	{
		if(stk[z] == 'b') 
		{
			printf("%sb", ac);
			stk[z] = 'A';
			stk[z + 1] = '\0';
			
			printf("\n$%s\t%s$\t", stk, a); 
		}
	}
		
	for(z=0; z<c-3; z++)
	{
		if(stk[z] == 'a' && stk[z + 1] == 'A' && 
								stk[z + 2] == 'B' && stk[z + 3] == 'e') 
		{
			printf("%saABe", ac);
			stk[z]='S';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			stk[z + 3]='\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 3;
		}
	}
	return ;
}

int main()
{
	printf("GRAMMAR is -\nS->aABe \nA->Abc|b \nB->d\n"); 
	
	strcpy(a,"abde"); 
	
	c=strlen(a); 
	
	strcpy(act,"SHIFT"); 
	
	printf("\nStack \t Input \t Action"); 
	
	printf("\n$\t%s$\t", a); 
	
	for(i = 0; j < c; i++, j++) 
	{
		printf("%s", act); 
		
		stk[i] = a[j];	 
		stk[i + 1] = '\0';
		
		a[j]=' ';
		
		printf("\n$%s\t%s$\t", stk, a); 
		
		check(); 
	}
	
	check(); 

	if(stk[0] == 'S' && stk[1] == '\0') 
		printf("Accept\n");
	else
		printf("Reject\n");
}