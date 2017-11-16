#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alerte.h"

char * niveauAlerte() {
  char *niveau;
  int choix = 0;

  niveau = malloc(21 * sizeof(char));

  if (niveau == NULL) {
    printf("Erreur d'allocation memoire pour le niveau d'alerte\n");
    return;
  }

  printf("1. NOMINAL\n");
  printf("2. URGENT\n");
  printf("3. URGENCE ABSOLUE\n");

  scanf("%d%*c", &choix);

  switch (choix) {
    case 1:
      niveau = "NOMINAL";
      break;
    case 2:
      niveau = "URGENT";
      break;
    case 3:
      niveau = "URGENCE ABSOLUE";
      break;
    default:
      printf("La saisie n'est pas correcte.\n");
  }
  return niveau;
  free(niveau);
  printf("DEBUG: niveau :%s\n", niveau);
}

char * typeAlerte() {
  char *type;
  int choix = 0;

  type = malloc(21 * sizeof(char));

  if (type == NULL) {
    printf("Erreur d'allocation memoire pour le type d'alerte\n");
    return;
  }

  printf("1. INCENDIE\n");
  printf("2. ACCIDENT ROUTE\n");
  printf("3. ACCIDENT MER\n");
  printf("4. ACCIDENT MONTAGNE\n");
  printf("5. MALAISE\n");
  printf("6. EXPLOSION\n");
  printf("7. ACCIDENT DE LA VIE\n");

  scanf("%d%*c", &choix);

  switch (choix) {
    case 1:
      type = "INCENDIE\n";
      break;
    case 2:
      type = "ACCIDENT ROUTE";
      break;
    case 3:
      type = "ACCIDENT MER";
      break;
    case 4:
      type = "ACCIDENT MONTAGNE";
      break;
    case 5:
      type = "MALAISE";
      break;
    case 6:
     type = "EXPLOSION";
     break;
    case 7:
      type = "ACCIDENT DE LA VIE";
      break;
    default:
      printf("La saisie n'est pas correcte.\n");
  }
  return(type);
  free(type);
  printf("DEBUG: chaine : %s\n", type);
}

void ajouterAlerte(Alerte **alerte, int *compteurAlerte) {
  char tmpChaine[LIEU_TAILLE];
  int tmpNombre = 0;
  char *ptrType;
  char *ptrNiveau;
  int i;

  i = *compteurAlerte;

  printf("Code d'alerte :\n");
  scanf("%d%*c", &tmpNombre);
  (*alerte)[i].iCode = tmpNombre;

  printf("Type d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  ptrType = typeAlerte();
  strcpy((*alerte)[i].cType, ptrType);

  printf("Niveau d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  ptrNiveau = niveauAlerte();
  strcpy((*alerte)[i].cNiveau, ptrNiveau);

  printf("Lieu :\n");
  fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  strcpy((*alerte)[i].cLieu, tmpChaine);

  printf("Nombre de victimes :\n");
  scanf("%d%*c", &tmpNombre);
  (*alerte)[i].iNombreVictimes = tmpNombre;

  printf("Description :\n");
  fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  strcpy((*alerte)[i].cDescription, tmpChaine);
}

void afficherToutesAlertes(Alerte **alerte, int *compteurAlerte) {
  int i = 0;

   if (*compteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

   for (i = 0; i < *compteurAlerte; i++) {
    printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
    printf("Type d'alerte : %s", (*alerte)[i].cType);
    printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
    printf("Lieu : %s", (*alerte)[i].cLieu);
    printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
    printf("Description :%s", (*alerte)[i].cDescription);
  }
}
