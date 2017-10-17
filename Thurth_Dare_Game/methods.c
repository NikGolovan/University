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
  char arrayTruth[5][150] = {{"Random Truth 1"}, {"Random Truth 2"},
                            {"Random Truth 3"}, {"Random Truth 4"}, {"Random Truth 5"}};

  srand(time(NULL));

  randomnumber = rand() % 5;

  printf("Question: %s ", arrayTruth[randomnumber]);
  printf("\n");
}

/* method that gets random dare */
void randomDare(void) {
  int randomnumber;
  char arrayTruth[5][150] = {{"Random Dare 1"}, {"Random Dare 2"},
                            {"Random Dare 3"}, {"Random Dare 4"}, {"Random Dare 5"}};

  srand(time(NULL));

  randomnumber = rand() % 5;

  printf("Question: %s ", arrayTruth[randomnumber]);
  printf("\n");
}
