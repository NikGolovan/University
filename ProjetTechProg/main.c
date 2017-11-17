#include <stdio.h>
#include <stdlib.h>

#include "alerte.c"

int main(int argc, char const *argv[]) {
  int choix = 0;
  int compteurAlerte = 0;
  Alerte *alerte = NULL;

  srand(time(NULL));

  alerte = malloc(TAILLE_INITIALE_DE_MALLOC * sizeof(Alerte));

  if (alerte == NULL) {
    printf("Erreur d'allocation mémoire\n");
    return(-1);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║            MENU ALERTE            ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ Créer une alerte             ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ Afficher une alerte          ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ Afficher toutes les alertes  ║\n");
    printf("║    ║                              ║\n");
    printf("║ 4  ║ Modifier une alerte          ║\n");
    printf("║    ║                              ║\n");
    printf("║ 5  ║ Supprimer une alerte         ║\n");
    printf("║    ║                              ║\n");
    printf("╠════╬══════════════════════════════╣\n");
    printf("║ -1 ║ Quitter                      ║\n");
    printf("╚════╩══════════════════════════════╝\n");

    scanf("%d%*c", &choix);

    switch (choix) {
      case 1:
        ajouterAlerte(&alerte, &compteurAlerte);
        compteurAlerte++;

        if (compteurAlerte >= TAILLE_INITIALE_DE_MALLOC) {
          alerte = realloc(alerte, (compteurAlerte * sizeof(Alerte)));
          printf("DEBUG: La mémoire a été realouée\n");
        }
        printf("DEBUG: compteurAlerte après l'ajout : %d\n", compteurAlerte);
        break;
      case 2:
        afficherUneAlerte(&alerte, &compteurAlerte);
        break;
      case 3:
        afficherToutesAlertes(&alerte, &compteurAlerte);
        break;
      case 4:
        modifierAlerte(&alerte, &compteurAlerte);
        break;
      case 5:
        supprimerAlerte(&alerte, &compteurAlerte);
        printf("DEBUG: compteurAlerte après la suppression : %d\n", compteurAlerte);
        break;
      case -1:
        break;
      default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }

  } while(choix != -1);

  return 0;
}
