#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6
#define FOUR 4

void userInput(char* input);
int game();
int compare(int red, int white,int target[], char guess[]);

int main(void)
{
	srand(time(NULL));

	game();
	//compGame();
}


int game()
{
	int target[MAX];
	char guess[MAX];
	int red = 0, count =0,white=0;

	printf("Target is: ");
	for (int i = 0; i < FOUR; i++)
	{
		target[i] = rand() % 10;
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


	while(red != FOUR)
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
	int skip[FOUR] = {0};
	int whiteSkip[FOUR] = {0};

	// Red Loop, sets indexes to skip
	for(int i = 0; i < FOUR;i++)
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
	for(int p = 0; p <FOUR; p++)
	{
		if(skip[p])
		{
			continue;
		}

		for(int x = 0;x<FOUR; x++)
		{
			if(whiteSkip[x])
			{
				continue;
			}
			else if(guess[p] == target[x])
			{
				//White found
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

	while(!valid) // Loop until valid input is entered
	{
		check = 0;
		printf("Guess a number: ");
		fgets(user,MAX,stdin);
		
		if(user[FOUR]!= '\n') // Checking for four characters.
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
			for(int i = 0; i < FOUR; i++) // iterate through those four characters
			{
				if( (user[i] > '9') || (user[i] < '0') ) // Check for non number character
				{
					check = 1; // Found a non-number character
					break;
				}
			}
			if(check) //Non number character entered.
			{
				printf("Please enter four NUMBERS.\n");
				continue;
			}
			valid = 1; // Validation complete with only 4 numbers.
			for(int i = 0;i < FOUR; i++)
			{
				user[i] = user[i] - '0';
			}
		}
		
	}
}
