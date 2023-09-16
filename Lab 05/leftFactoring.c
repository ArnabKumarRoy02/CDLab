#include<stdio.h>
#include<string.h>

int main() {
    char gram[20],part1[20],part2[20],part4[20],part3[20],modifiedGram[20],newGram[20],tempGram[20];
    int ip=0,i,j=0,k=0,l=0,pos;
    
    printf("Enter Production : S->");
    gets(gram);
    
    for(i=0;gram[i]!='|';i++,j++)
        part1[j]=gram[i];
    part1[j]='\0';
    ip+=i;
    
    for(j=++ip,i=0;gram[j]!='|';j++,i++)
        part2[i]=gram[j];
    part2[i]='\0';
    ip+=i;
    
    for(j=++ip,i=0;gram[j]!='|';j++,i++)
        part3[i]=gram[j];
    part3[i]='\0';
    ip+=i;
    
    for(j=++ip,i=0;gram[j]!='\0';j++,i++)
        part4[i]=gram[j];
    part4[i]='\0';
    puts(part1);
    puts(part2);
    
    for(i=0;i<strlen(part1)||i<strlen(part2)||i<strlen(part3)||i<strlen(part4);i++){
        if(part1[i]==part2[i]){
            modifiedGram[k]=part2[i];
            k++;
            pos=i+1;
        }
        else{
            break;
        }
    }
    puts(part3);
    puts(part4);
    puts(modifiedGram);
    
    for(i=pos,j=0;part1[i]!='\0';i++,j++){
        newGram[j]=part1[i];
    }
    newGram[j++]='|';
    
    for(i=pos;part2[i]!='\0';i++,j++){
        newGram[j]=part2[i];
    }
    newGram[j++]='|';
    
    for(i=pos;part3[i]!='\0';i++,j++){
        newGram[j]=part3[i];
    }
    
    newGram[j++]='|';
    for(i=pos;part4[i]!='\0';i++,j++){
        newGram[j]=part4[i];
    }
    
    modifiedGram[k]='X';
    modifiedGram[++k]='|';
    modifiedGram[++k]='z';
    modifiedGram[++k]='\0';
    newGram[j]='\0';
    printf("\nGrammar Without Left Factoring : : \n");
    printf(" S->%s",modifiedGram);
    printf("\n X->%s\n",newGram);
}
//AabbC|AabCC|AabcC|z
