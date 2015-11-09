
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 6
#define FOUR 4

void userInput(char* input);
int game();
int compare(int red, int white,int target[], char guess[]);
size_t strnlen(const char *str, size_t maxlen);


int main(void)
{
	srand(time(NULL));

	printf("\nHello user, I would like to play a game. (Mastermind)\nWould you like to play?\n");
	int loop = 1;
	char choice;
	char input[3];
	while(loop)
	{
		printf(" [Y]es\n [N]o\nMake your choice: ");
		fgets(input,MAX,stdin);
		choice = input[0];
		switch(choice)
		{
			case 'y':
			case 'Y':
			{
				printf("=======================================\n");
				printf("Let the game begin...\n");
				game();
				break;
			}
			case 'n':
			case 'N':
			{
				loop = 0;
				break;
			}
			default:
			{
				printf("Please enter a Y or an N.\n");
				printf("=======================================\n");
				if(input[1] != '\n')
				{
					while(!strchr(input, '\n'))
					{
						fgets(input, sizeof(input), stdin);
					}
					input[2] = '\0';
				}
				else
				{
					input[2] = '\0';
				}
				break;
			}
		}
		//compGame();
	}
}


int game()
{
	int target[MAX];
	char guess[MAX];
	int red = 0, count =0,white=0;

	for (int i = 0; i < FOUR; i++)
	{
		target[i] = rand() % 10;
	}
	printf("\n");

	while(red != FOUR)
	{
		userInput(guess);
		red = compare(red, white,target,guess);
		count +=1;
	}
	printf("You've won in %d guesses.\n",count);
	printf("Would you like to play again?\n");

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

	for(int p = 0; p <FOUR; p++)
	{
		if(skip[p]) // Skipping those marked as red
		{
			continue;
		}

		for(int x = 0;x<FOUR; x++)
		{
			if(whiteSkip[x]) // Skiping those marked as white
			{
				continue;
			}
			else if(guess[p] == target[x]) // Finds whites
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


size_t strnlen(const char *str, size_t maxlen)
{
     size_t i;
     for(i = 0; i < maxlen && str[i]; i++)
     	/*Do nothing.*/;
     return i;
}