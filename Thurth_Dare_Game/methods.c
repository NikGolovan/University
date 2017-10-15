#include <stdio.h>
#include <stdlib.h>

/* method that verifies user's input */
void verifyUserInput(int *numberOfPlayers, int isDigit) {
  if (isDigit == 0) {
    do {
      getchar(); // clearing the buffer
      printf("Enter a number: ");
      if (scanf("%d%*c", &*numberOfPlayers) == 1)
        isDigit = 1;
    } while (isDigit != 1);
  }
}

/* method that gets random truth question */
void randomThruth(void) {
  int randomnumber;
  char arrayTruth[5][150] = {{"Truth 1"}, {"Truth 2"},
                            {"Truth 3"}, {"Truth 4"}, {"Truth 5"}};

  srand(time(NULL));

  randomnumber = rand() % 5;

  printf("Question: %s ", arrayTruth[randomnumber]);
  printf("\n");
}

/* method that gets random dare */
void randomDare(void) {
  int randomnumber;
  char arrayTruth[5][150] = {{"Dare 1"}, {"Dare 2"},
                            {"Dare 3"}, {"Dare 4"}, {"Dare 5"}};

  srand(time(NULL));

  randomnumber = rand() % 5;

  printf("Question: %s ", arrayTruth[randomnumber]);
  printf("\n");
}
