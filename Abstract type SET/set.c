#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/* initialisation du set */
SET setVide() {
  SET set;
  set = NULL;
  return(set);
}

/* vérification si le set est vide. Retourne 1 si VRAI et 0 sinon */
int estVide(SET set) {
  return(set == NULL);
}

/* vérification si un élément est appartient à set */
int appartient(SET **set, int element) {
  Cellule *iter = **set;

  while (iter != NULL) {
    if (iter->element == element)
      return 1;
    iter = iter->suivant;
  }
  return 0;
}

/* ajout d'un élémenet dans le set */
void ajouter(SET *set, int element) {
  SET tmp;
  int elementExiste = 0;

  /* vérification avant ajout que cet élément n'existe pas dans le set */
  /* si élément existe, nous ne pouvons pas ajouter cet élément */
  elementExiste = appartient(&set, element);

  if (elementExiste) {
    printf("Element %d déjà existe dans le set. Veuillez insérer un autre.\n", element);
    return;
  }

  tmp = malloc(sizeof(Cellule)); /* qllocation de la mémoire dynamiquement pour le set */
  tmp->element = element;
  tmp->suivant = *set;
  *set = tmp;
}

/* affiche les tous éléments du set */
void afficherElements(SET set) {
  Cellule *iter = set;

  while (iter != NULL) {
    printf("%d\n", iter->element);
    iter = iter->suivant;
  }
}

/* suppression d'un élément du set */
void enlever(SET *set, int valeur) {
  Cellule *iter = *set;

  while (iter != NULL) {
    if (iter->element == valeur)
      printf("L'élément pour la suppression a été trouvé\n");
    iter = iter->suivant;
  }
}
