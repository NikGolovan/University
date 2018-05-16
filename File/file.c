/* Le module file.c est un fichier de preuve pour le type FILE */
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/* initialisation de la file, la tete et queue sont mises à 0 */
void initialiser(typeFile *file) {
  file->tete = 0;
  file->queue = 0;
}

/* la file est vide si la tete == queue */
int estVide(typeFile file) {
  return((file.tete == file.queue));
}

/* insertion d'un élément dans la file */
void enfiler(typeFile *file, int elt) {
  file->tab[file->queue] = elt;
  file->queue = (file->queue+1) % TAILLE_MAX;
}

/* suppression d'un élément de la file */
void defiler(typeFile *file) {
  file->tete = (file->tete+1);
}

/* returne le premier élément de la file */
int premier(typeFile file) {
  return(file.tab[file.tete]);
}
