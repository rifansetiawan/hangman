#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h> 
using namespace std;



int main(){
    char a;
    char word[100];
    char sol[256]={};
    int i,j,attempts=0;
	char category[3][100]={"fruit","animal","country"};
	char fruit[6][100]={"apple","banana","watermelon","guava","orange"};
	char animal[5][100]={"dog", "cat","elephant","tiger","bird"};
	char country[6][100]={"indonesia","france","usa","china","japan","korea"};
	
	int random;
	int subRandom;

	srand(time(0));
	random = rand()%3;

	
	printf("%s\n", category[random]);

	if(strcmp(category[random],"animal")==0){
		subRandom = rand() % 5;
		strcpy(word, animal[subRandom]);
	}
	else if(strcmp(category[random],"fruit")==0){
		subRandom = rand() % 5;
		strcpy(word, fruit[subRandom]);
		
	}
	else if(strcmp(category[random],"country")==0){
		subRandom = rand() % 5;
		strcpy(word, country[subRandom]);
		
	}



    
	attempts=strlen(word);
    
	for(i=0;i<25;i++)
        printf("\n");

	
    i=0;
    while(word[i]!='\0')
        i++;

	for(j=0;j<i;j++)
    {
        sol[j]='-';
    }
	
	
	do{
		printf("You have %d attempts\n", attempts);
		printf("You have %d letters\n",  strlen(word));
		sol[j]='\0';


		printf("guess a letter: ");
		scanf("%c", &a);
		strlwr(&a);
		fflush(stdin);

		
		
		for(j=0;j<i;j++)
			if(word[j]==a)
			{
				sol[j]=a;
				attempts++;
			}



		printf("\n");
		for(j=0;j<i;j++){
			strupr(&sol[j]);
			printf("%c", sol[j]);
		}
		printf("\n");

		attempts--;

		
		for(int x=0;x<25;x++)
		printf("\n");

		strlwr(sol);
	} while(attempts >= 0 && strcmp(sol, word)!=0);
	
	
	if(strcmp(sol, word)==0)
		printf("\n\nYay, you did it, Congrats!!");


	else
		printf("\n\nThe word is : %s \n\n Aww, better luck next time :(", word);
	
	
	getchar();
}