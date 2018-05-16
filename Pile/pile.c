/* Dans le module pile.c nous développons chaque fonction qui a été décrite par
le fichier d'interface pile.h */
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/* initialisation de la pile */
void initialiser(PILE *pile) {
  *pile = NULL;
}

/* vérification si la pile est vide. Retourne 1 si VRAI et 0 sinon */
int estVide(PILE pile) {
  return(pile == NULL);
}

/* retorune le sommet de la pile */
int sommet(PILE pile) {
  return(pile->elt);
}

/* ajout un nouvequ élément dans la pile */
void empiler(PILE *pile, int elt) {
  PILE tmp;

  tmp = malloc(sizeof(Cellule)); /* allocation de mémoire dynimaquement */
  tmp->elt = elt;
  tmp->suivant = *pile;
  *pile = tmp;
}

/* suppression d'un élément dans la pile */
void depiler(PILE *pile) {
  PILE tmp;

  tmp = *pile;
  *pile = tmp->suivant;
  free(tmp); /* liberation de la mémoire occupée par un élément */
}
