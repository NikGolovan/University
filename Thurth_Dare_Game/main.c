#include <stdio.h>
#include "callMethods.h"

#define MAX_PLAYERS 10
#define MAX_NAME_SIZE 15

int main() {
  char players[MAX_PLAYERS][MAX_NAME_SIZE] = {{0}}; /* char array contains players */
  char playerName = 0; /* assigns a name to a player */
  int numberOfPlayers = 0; /* total number of players playing the game */
  char input = 0; /* user input for t (truth) and d (dare) */
  int incrementer = 0; /* allows to pass to the next player during game */
  int i = 0; /* serve for the "for" loop */
  int isDigit = 1; /* boolean checking user input, 0 = false, 1 = true */
  char numberofPlayersChar[1] = {0}; /* serves to verify users input for amount of players. It is an array type to avoid certains bugs */

  /* BEGIN OF MENU LOOP "DO WHILE" */
  do {
 /* asking for user input */
  printf("Truth or Dare game\n");
  printf("------------------\n");
  printf("Enter amount of players: ");

  gets(numberofPlayersChar);
    
  /* reading and checking if the user input was digital
     if it wasn't, setting boolean isDigit to false */
  if (!isdigit(numberofPlayersChar[0]) || !isdigit(numberofPlayersChar[1]))
      isDigit = 0;

  /* calling this method only if isDigit is equals to false = 0 */
  if (isDigit == 0)
    changeUserInput(&numberOfPlayers, isDigit);

  /* adding new players to the game */
  if (numberOfPlayers > 10) {
    printf("The amount of players should be <= 10\n\n");
  } else {
      for (i = 0; i < numberOfPlayers; i++) {
        printf("Give the %d player name: ", i+1);
        gets(players[i]);
      }
  }
} while (numberOfPlayers > 10);
/* END OF MENU LOOP "DO WHILE" */

/* BEGIN OF GAME LOOP "DO WHILE" */
do {
      printf("It's %s move. Type t (truth) or d (dare): ", players[incrementer]);
      scanf("%c%*c", &input);

      switch (input) {
        case 't':
          printf("You have choosed the truth.\n");
          randomThruth(); /* calling this method to get a random truth question */
          incrementer++; /* increments which allows to pass to the next player */
          printf("\n");
          break;
        case 'T':
          printf("You have choosed the truth.\n");
          randomThruth();
          incrementer++;
          printf("\n");
          break;
        case 'D':
          printf("You have choosed a dare.\n");
          randomDare();
          incrementer++;
          printf("\n");
          break;
        case 'd':
          printf("You have choosed a dare.\n");
          randomDare();
          incrementer++;
          printf("\n");
          break;
        case 'q':
          printf("Thanks for playing.\n");
          break;
        default:
          printf("Wrong input\n");
          break;
      }

      /* when incrementer is equal to the number of players
         it sets itself to 0 to return to the first player */
      if (incrementer == numberOfPlayers)
        incrementer = 0;

    } while (input != 'q');
    /* END OF GAME LOOP "DO WHILE" */
  return 0;
}
