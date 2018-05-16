/* Le module main.c est un fichier de preuve pour le type PILE */
#include <stdio.h>
#include "pile.c"

int main() {
  PILE pile; /* declaration de la pile */

  /* initialisation la pile  */
  initialiser(&pile);

  printf("La pile a été initialisée avec le succès et ");

  /* vérification si la pile est vide */
  if (estVide(pile))
    printf("elle est vide par instant.\n");
  else
     printf("La pile n'est pas vide par instant.\n");

  /* ajout d'un élément dans la pile */
  empiler(&pile, 8);

  printf("Un élément a été ajouté dans la pile.\n");
  printf("Le sommet de la pile est : %d\n", sommet(pile));

 /* vérification si la pile est vide */
  if (estVide(pile))
    printf("La pile avant la suppression est vide.\n");
  else
     printf("La pile avant la suppression n'est pas vide.\n");

 /* la suppression d'un élément de la pile. Il faut aussi prendre en compte
    que nous ne pouvons pas depiler une pile si elle est vide */
  if (!estVide(pile)) {
    depiler(&pile);
    printf("La suppression d'un élément dans la pile a été effectuée.\n");
  }

 /* vérification si la pile est vide après la suppression d'un élément */
  if (estVide(pile))
    printf("La pile après la suppression est vide.\n");
  else
     printf("La pile après la suppression n'est pas vide.\n\n");

  if (!estVide(pile)) {
    depiler(&pile);
    printf("La suppression d'un élément dans la pile a été effectuée.\n");
} else {
    printf("La suppression ne peut pas être effectuée car la pile est vide.\n");
}

  /* Le cas où nous ajoutons plusieurs éléments dans la pile */
  empiler(&pile, 5);
  printf("Un nouveau éléments ont été ajouté dans la pile.\n");
  printf("Nouveau sommet de la pile est : %d\n", sommet(pile));

  if (!estVide(pile)) {
    depiler(&pile);
    printf("La suppression d'un élément dans la pile a été effectuée.\n");
  } else {
    printf("La suppression n'est pas possible car la pile est vide.\n");
  }

  if (estVide(pile))
    printf("Le sommet de la pile ne contient aucun élément.\n");
  else
    printf("Le sommet de la pile est : %d\n", sommet(pile));

  return 0;
}
