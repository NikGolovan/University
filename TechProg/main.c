#include<stdio.h>
#include "alerte.c"

int main() {
  Alerte *alerte = NULL;
  int compteurAlerte = 0;
  int choix = 0;

  alerte = malloc(INITIAL_TAILLE_DE_MALLOC * sizeof(Alerte))

  if (alerte == NULL) {
    printf("Erreur d'allocation memoire\n");
    exit(EXIT_FAILURE);
  }
  
  printf("1. Ajouter une alerte\n");
  printf("3. Afficher toutes les alertes\n", );
  scanf("%d%*c", &choix);

  switch (choix) {
    case 1:
      ajouterAlerte(alerte, &compteurAlerte);
      break;
    case 3:
      afficherToutesAlertes(alerte, &compteurAlerte);
      break;
    default:
      printf("La saisie n'est pas correcte. Veuillez choisir de nouveau\n");
      break;
  }
  return 0;
}
