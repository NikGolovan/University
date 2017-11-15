#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 255

typedef struct {
  char name[NAME_SIZE];
  int amount;
} Person;

int growArray(Person **user_array, int counter, int numNewElems)
{
    const int totalSize = counter + numNewElems;
    Person *temp = (Person*)realloc(*user_array, (totalSize * sizeof(Person)));

    if (temp == NULL)
    {
        printf("Cannot allocate more memory.\n");
        return 0;
    }
    else
    {
        *user_array = temp;
    }

    printf("The memory has been reallocated\n");
    return totalSize;
}

int main(int argc, char const *argv[]) {
  Person *data = NULL;
  int counter = 0;
  int i = 0;

  data = malloc(3 * sizeof(Person));

  if (data == NULL) {
    printf("Erreur d'allocation de la mémoire\n");
    return(-1);
  }

  strcpy(data[0].name, "Hello");
  data[0].amount = 5;
  counter++;

  strcpy(data[1].name, "There");
  data[1].amount = 6;
  counter++;

  strcpy(data[2].name, "Everybody");
  data[2].amount = 7;
  counter++;

  printf("Counter value before: %d\n", counter);

  if (counter >= 3) {
    data = realloc(data, (counter * sizeof(Person)));
    //counter = growArray(&data, counter, 0);
    printf("Executed\n");
  }

  strcpy(data[3].name, "Yo");
  data[3].amount = 8;
  counter++;

  strcpy(data[4].name, "Wasup");
  data[4].amount = 9;
  counter++;

  strcpy(data[5].name, "R");
  data[5].amount = 10;
  counter++;

  printf("Counter value after: %d\n", counter);

  for (i = 0; i < counter; i++) {
    printf("%s\n", data[i].name);
    printf("%d\n", data[i].amount);
  }

  /* printf("%s\n", data[0].name);

  printf("%d\n", data[1].amount);
  printf("%s\n", data[2].name);
  printf("%d\n", data[2].amount);
  printf("%s\n", data[3].name);
  printf("%d\n", data[3].amount); */

  return 0;
}
