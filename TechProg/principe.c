#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 30
#define INITIAL_SIZE 1

typedef struct {
  int age;
  char name[NAME_SIZE];
} Person;

int main() {
  Person *ptrPerson = NULL;
  int personCounter = 0;
  int i = 0;

  ptrPerson = malloc(INITIAL_SIZE * sizeof(Person));

  if (ptrPerson == NULL)
    exit(EXIT_FAILURE);

  printf("Give the age:\n");
  scanf("%d%*c", &(ptrPerson+personCounter)->age);
  printf("Give the name:\n");
  scanf("%s%*c", &(ptrPerson+personCounter)->name);
  personCounter++;

  if (personCounter >= 1) {
    realloc(ptrPerson, sizeof(Person));
    printf("Reallocated\n");
  }
  
  printf("Give the age:\n");
  scanf("%d%*c", &(ptrPerson+personCounter)->age);
  printf("Give the name:\n");
  scanf("%s%*c", &(ptrPerson+personCounter)->name);
  personCounter++;

  printf("Give the age:\n");
  scanf("%d%*c", &(ptrPerson+personCounter)->age);
  printf("Give the name:\n");
  scanf("%s%*c", &(ptrPerson+personCounter)->name);
  personCounter++;

  printf("\n");

  printf("Data is:\n");
  while (i < personCounter) {
    printf("%d\n", (ptrPerson+i)->age);
    printf("%s\n", (ptrPerson+i)->name);
    i++;
  }
  return 0;
}
