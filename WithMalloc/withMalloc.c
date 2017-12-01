//simple betting game. 
// "Jack Queen King" - computer shuffles there 3 cards.
// Player need to find the position of the Queen.
// If the player guesses correcly, He takes Three Times the bet he placed. 
// If player looses then the bet ammout will be reduced from his balance.
// Player Starting Balance = $100.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // This library is for the call to randomize the cards play().

// First we give the user a starting balance of 100.
int cash = 100;

//This function is used for
void Play(int bet)
{
	 char *C = malloc(3*sizeof(char));
	 C[0] == 'J'; C[1] == 'K'; C[2] == 'Q';
	 printf("Shuffling...");
	 srand(time(NULL)); //seeding random number generator.
	 int i;
	 for(i = 0; i < 5; i++)
	 {
	 	int x = rand() % 3;
	 	int y = rand() % 3;
	 	int temp = C[x];
	 	C[x] = C[y];
	 	C[y] = temp; //Swaps the positions of x and y.
	 }
	 int playersGuess = '\0';
	 printf("What's the position of the Queen ? 1, 2, or 3?");
	 scanf("%d", &playersGuess);
	 if (C[playersGuess - 1] == 'Q')
	 {
	 	cash += 3*bet;
	 	printf("YOU WIN! Result = %c%c%c Total Cash = %d ", C[0], C[1], C[2], cash);
	 }
	 else 
	 {
	 	cash -= bet;
	 	printf("YOU LOSE! Result = %c%c%c Total Cash = %d ", C[0], C[1], C[2], cash);
	 	printf("You will be returned to console!\n");
	 }
	 free(C);
}

int main()
{
	int bet;
	printf("Welcome to the virtual casino\n");
	printf("Total cash =$%d\n", cash);

	while (cash > 0)
	{
		printf("Whats you're bet?! ");
		scanf("%d", &bet);
		if (bet == 0 || bet > cash) break;
		Play(bet);
	}
}
