#include <stdio.h>
#include <stdlib.h>
#include "alerte.h"

void ajouterAlerte(Alerte alerte, int *compteurAlerte) {
  printf("Type d'alerte :\n");
  typeAlerte(alerte, &compteurAlerte);
  printf("Niveau d'alerte :\n");
  niveauAlerte(&alerte, &compteurAlerte);
  printf("Lieu :\n");
  scanf("%s%*c\n", &(alerte+*compteurAlerte)->cLieu);
  printf("Nombre de victimes :\n");
  scanf("%d%*c", &(alerte+*compteurAlerte)->iNombreVictimes);
  printf("Description :\n");
  scanf("%s%*c", &(alerte+*compteurAlerte)->cDescription);
  (*compteurAlerte)++;  
}

void typeAlerte(Alerte alerte, int *compteurAlerte) {
  int choix;
  
  printf("1 - INCENDIE\n");
  printf("2 - ACCIDENT ROUTE\n");
  printf("3 - ACCIDENT MER\n");
  printf("4 - ACCIDENT MONTAGNE\n");
  printf("5 - MALAISE\n");
  printf("6 - EXPLOSION\n");
  printf("7 - ACCIDENT DE LA VIE\n");
  scanf("%d%*c", &choix);

  switch (choix) {
    case 1:
        (alerte+*compteurAlerte)->cType = "INCENDIE";
        break;
    case 2:
        (alerte+*compteurAlerte)->cType = "ACCIDENT ROUTE";
        break;
    case 3:
        (alerte+*compteurAlerte)->cType = "ACCIDENT MER";
        break;
    case 4:
        (alerte+*compteurAlerte)->cType = "ACCIDENT MONTAGNE";
        break;
    case 5:
        (alerte+*compteurAlerte)->cType = "MALAISE";
        break;    
    case 6:
        (alerte+*compteurAlerte)->cType = "EXPLOSION";
        break;
    case 7:
        (alerte+*compteurAlerte)->cType = "ACCIDENT DE LA VIE";
        break;
    default:
        printf("La saisie n'est pas correcte. Veuillez choisir de nouveau.\n");
        break;
  }
}

void niveauAlerte(Alerte alerte, int *compteurAlerte) {
  int choix;
  
  printf("1 - NOMINAL\n");
  printf("2 - URGENT\n");
  printf("3 - URGENCE ABSOLUE\n");
  scanf("%d%*c", &choix);

  switch (choix) {
    case 1:
        (alerte+*compteurAlerte)->cNiveau = "NOMINAL";
        break;
    case 2:
        (alerte+*compteurAlerte)->cNiveau = "URGENT";
        break;
    case 3:
        (alerte+*compteurAlerte)->cNiveau = "URGENCE ABSOLUE";
        break;
    default:
        printf("La saisie n'est pas correcte. Veuillez choisir de nouveau.\n");
        break;
  }
}

void afficherToutesAlertes(Alerte alerte, int *compteurAlerte) {
  int i = 0;
  
  printf("Les alertes sont :\n");
  while (i < *compteurAlerte) {
    printf("%s\n", (alerte+i)->cType);
    printf("%s\n", (alerte+i)->cNiveau);
    printf("%s\n", (alerte+i)->cLieu);
    printf("%d\n", (alerte+i)->iNombreVictimes);
    printf("%s\n", (alerte+i)->cDescription);
    i++;
  }
}
