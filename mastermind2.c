#include <string.h>
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
	srand(time(NULL));
	//compGame();

	game();

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
{
	printf("%c %d %d %p %d %d %d %d",guess[0],red, white, (void*)count, onePlace[0], twoPlace[0], threePlace[0], fourPlace[0]);
	return;
}

int game()
{
	int target[MAX];
	char guess[MAX];
	int red = 0, count =0,white=0;

	printf("Target is: ");
	for (int i = 0; i < 4; i++)
	{
		target[i] = rand() % 10;
		//printf("%d",target[i]);
	}
	printf("\n");

	target[0] = 1;
	target[1] = 3;
	target[2] = 3;
	target[3] = 3;

	printf("%d",target[0]);
	printf("%d",target[1]);
	printf("%d",target[2]);
	printf("%d\n",target[3]);


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
		//printf("\n\np is: %d\n",p);
		if(skip[p])
		{
			//whiteSkip[p] = 1;
			continue;
		}

		for(int x = 0;x<4; x++)
		{
			if(whiteSkip[x])
			{
				continue;
			}
			else if(guess[p] == target[x])
			{
				//printf("White found\n");
				white +=1;
				whiteSkip[x] = 1;
				skip[p] = 1;
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
	int valid = 0, check = 0;
	char c;

	while(!valid)
	{
		check = 0;
		printf("Guess a number: ");
		fgets(user,MAX,stdin);
		
		if(user[4]!= '\n') // Checking for four characters.
		{
			printf("Please enter FOUR numbers.\n");
			if(strlen(user) < 5)
			{
				continue;
			}
			else
			{
				while ( (c=getchar()) != '\n' && c != EOF ) // Loop to clear out the stdin buffer.
    				/*Do nothing*/;
    			continue;
    		}
		}
		else // Entered four characters plus a \n.
		{
			for(int i = 0; i < 4; i++) // iterate through those four characters
			{
				if( (user[i] > '9') || (user[i] < '0') ) // Check for non number character
				{
					check = 1;
					break;
				}
			}
			if(check) //Non number character entered.
			{
				printf("letter encountered.\n");
				while ( (c=getchar()) != '\n' && c != EOF ) // Loop to clear out the stdin buffer.
		    		/*Do nothing*/;
				continue;
			}
			valid = 1; // Validation complete with only 4 numbers.
			for(int i = 0;i < 4; i++)
			{
				user[i] = user[i] - '0';
			}
		}
		
	}
}
