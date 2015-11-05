#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6

void userInput(char* input);
void compInput(char guess[],int red, int white, int* count,int* onePlace,int* twoPlace,int* threePlace,int* fourPlace);
int compGame();
int game();
int compare(int red, int white,int target[], char guess[]);

int main(void)
{
	//compGame();

	game();

	return(0);
}



int compGame()
{
	int target[MAX];
	char guess[MAX];
	int red = 0, count =0,white=0;

	int onePlace[10]   = {0,1,2,3,4,5,6,7,8,9};
	int twoPlace[10]   = {0,1,2,3,4,5,6,7,8,9};
	int threePlace[10] = {0,1,2,3,4,5,6,7,8,9};
	int fourPlace[10]  = {0,1,2,3,4,5,6,7,8,9};

	printf("Target is: ");
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		target[i] = rand() % 10;
		printf("%d",target[i]);
	}
	printf("\n");

	while(red != 4)
	{
		compInput(guess,red,white,&count,onePlace,twoPlace,threePlace,fourPlace);
		red = compare(red, white,target,guess);
		count +=1;
	}
	printf("You've won in %d guesses.\n",count);

	return(0);
}


void compInput(char* guess,int red, int white, int* count,int* onePlace,int* twoPlace,int* threePlace,int* fourPlace)
{/*
	if (count ==0)
	{
		guess[0] = 1;
		guess[1] = 1;
		guess[2] = 2;
		guess[3] = 2;
		printf("Guessing 1122\n");
		exit(0);
	}
	else
	{
		red = 4;








	}
*/
	printf("%c %d %d %p %d %d %d %d",guess[0],red, white, (void*)count, onePlace[0], twoPlace[0], threePlace[0], fourPlace[0]);
	return;
}









int game()
{
	int target[MAX];
	char guess[MAX];
	int red = 0, count =0,white=0;

	printf("Target is: ");
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		target[i] = rand() % 10;
		printf("%d",target[i]);
	}
	printf("\n");

	while(red != 4)
	{
		userInput(guess);
		red = compare(red, white,target,guess);
		count +=1;
	}
	printf("You've won in %d guesses.\n",count);

	return(0);
}

int compare(int red, int white,int target[], char guess[])
{
	red = 0;
	white = 0;
	int skip[4] = {0};
	int whiteSkip[4] = {0};

	

	// Red Loop, sets indexes to skip
	for(int i = 0; i < 4;i++)
	{
		if(target[i] == guess[i])
		{
			red +=1;
			skip[i] = 1;
			whiteSkip[i] = 1;
		}
	}
	printf("%d",skip[0]);
	printf("%d",skip[1]);
	printf("%d",skip[2]);
	printf("%d\n",skip[3]);
	for(int p = 0; p <4; p++)
	{
		if(skip[p])
		{
			whiteSkip[p] = 1;
			continue;
		}

		for(int x = 0;x<4; x++)
		{
			if((whiteSkip[x]) || (skip[p]))
			{
				continue;
			}
			else if(guess[p] == target[x])
			{
				white +=1;
				whiteSkip[x] = 1;
				break;
			}
		}
	}

	printf("%d red, %d white\n",red,white);
	printf("=======================================\n");
	return(red);
}


void userInput(char* user)
{
	printf("Guess a number: ");
	fgets(user,MAX,stdin);

	for(int i = 0; i < 4; i++)
	{
		user[i] = user[i] - 48;
	}
}




/*
	target[0] = 7;
	target[1] = 3;
	target[2] = 4;
	target[3] = 3;

	printf("%d",target[0]);
	printf("%d",target[1]);
	printf("%d",target[2]);
	printf("%d\n",target[3]);
*/