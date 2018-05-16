/* Le module main.c est un fichier de preuve pour le type FILE */
#include <stdio.h>
#include "file.c"

int main() {
  typeFile file;

  /* initialisation de la file */
  initialiser(&file);

  /* vérification si la file est vide après initialisation */
  if (estVide(file))
    printf("La file a été bien initialisé et elle vide.\n");
  else
    printf("La file a été bien initialisé et elle n'est pas vide.\n");

  /* insertion des élément dans la file */
  enfiler(&file, 1);

  /* affichage du premier élément */
  printf("Premier élément de la file est : %d\n", premier(file));

  /* vérification avant la supprisson si la file contient les éléments */
  if (!estVide(file)) {
    defiler(&file);
    printf("L'élément a été bien supprimé de la file.\n");
  } else {
    printf("La suppression ne peut pas être effectuée car la file est vide.\n");
  }

  /* vérification de la deuxieme suppression quand la file est vide */
  if (!estVide(file)) {
    defiler(&file);
    printf("L'élément a été bien supprimé de la file.\n");
  } else {
    printf("La suppression ne peut pas être effectuée car la file est vide.\n");
  }

  /* insertion des plusieurs éléments dans la file */
  enfiler(&file, 1);
  enfiler(&file, 2);
  enfiler(&file, 3);

  printf("Plusieurs éléments ont été bien inseré dans la file.\n");
  printf("Premier élément de la file est : %d\n", premier(file));

  if (!estVide(file)) {
    defiler(&file);
    printf("L'élément a été bien supprimé de la file.\n");
  } else {
    printf("La suppression ne peut pas être effectuée car la file est vide.\n");
  }

  printf("Nouveau premiere élément est : %d\n", premier(file));

  return 0;
}
