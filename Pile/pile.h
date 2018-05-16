/* Le module pile.c décrit toutes les fonctions nécessaires pour le traitement
du type PILE */ 
#ifndef PILE_H
#define PILE_H

/* declaration de la structure de données d'une liste chaînée */
typedef struct Cell {
  int elt;
  struct Cell *suivant;
} Cellule;

/* declaration du pointeur sur la Cellule */
typedef Cellule *PILE;

/* declaration des opérations utilisées pour la gestion d'une pile  */
void initialiser(PILE *pile); /* initialisation de la pile */
int estVide(PILE pile);  /* nous testons si la pile est vide */
int sommet(PILE pile); /* retourne le sommet de la pile */
void empiler(PILE *pile, int elt); /* ajout d'un nouveau élément dans la pile */
void depiler(PILE *pile); /* suppression d'un élément qui se trouve au sommet de la pile */

#endif
