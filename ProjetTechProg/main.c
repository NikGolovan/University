#include <stdio.h>
#include <stdlib.h>

#include "alerte.c"

int main(int argc, char const *argv[]) {
  int choix = 0;
  int compteurAlerte = 0;
  Alerte *alerte = NULL;

  alerte = malloc(2 * sizeof(Alerte));

  if (alerte == NULL) {
    printf("Erreur d'allocation mémoire\n");
    return(-1);
  }

  do {
    printf("1. Nouvelle alerte\n");
    printf("2. Afficher une alerte\n");
    printf("3. Afficher toutes les alertes\n");
    printf("4. Modifier une alerte\n");
    printf("5. Supprimer une alerte\n");
    printf("------------------------------\n");
    printf("-1 pour quitter\n");

    scanf("%d%*c", &choix);

    switch (choix) {
      case 1:
        ajouterAlerte(&alerte, &compteurAlerte);
        compteurAlerte++;

        if (compteurAlerte >= 2) {
          alerte = realloc(alerte, (sizeof(Alerte)));
          printf("DEBUG: La mémoire a été realouée\n");
        }
        break;
      case 3:
        afficherToutesAlertes(&alerte, &compteurAlerte);
        break;
      case -1:
        break;
      default:
        printf("La saisie n'est pas correcte\n");
        break;
    }

  } while(choix != -1);


  return 0;
}
