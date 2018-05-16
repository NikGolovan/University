/* Le module file.h est un fichier de preuve pour le type FILE */
#ifndef FILE_H
#define FILE_H

/* declaration de la taille maximale du tableau */
#define TAILLE_MAX 50

/* declaration de la structure du type FILE */
typedef struct Cell {
  int tete; /* contient premiere élément de la file  */
  int queue; /* contient derniere élément de la file  */
  int tab[TAILLE_MAX];
} typeFile;

/* les operations qui permettent de manipuler la file  */
void initialiser(typeFile *file);
int estVide(typeFile file);
void enfiler(typeFile *file, int elt);
void defiler(typeFile *file);
int premier(typeFile file);

#endif
