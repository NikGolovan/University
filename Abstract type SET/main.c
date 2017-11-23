#include <stdio.h>
#include "set.c"

int main() {
  SET set;
  int setEstVide = 0;

  set = setVide();
  printf("Le set a été bien initialisé.\n");

  setEstVide = estVide(set);

  if (setEstVide)
    printf("Le set est vide.\n");

  ajouter(&set, 5);
  printf("L'élément a été bien ajouté dans le set.\n");
  ajouter(&set, 5);
  afficherElements(set);
  enlever(&set, 5);
  printf("L'élément a été bien supprimé du set.\n");

  return 0;
}
