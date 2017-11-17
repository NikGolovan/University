#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "alerte.h"

int genererCodeAlerte() {
  int nombreGenere = rand() % 50001;

  return nombreGenere;
}

char * niveauAlerte() {
  char *niveau;  srand(time(NULL));
  int choix = 0;

  niveau = malloc(21 * sizeof(char));

  if (niveau == NULL) {
    printf("Erreur d'allocation memoire pour le niveau d'alerte\n");
    exit(EXIT_FAILURE);
  }

  printf("1. NOMINAL\n");
  printf("2. URGENT\n");
  printf("3. URGENCE ABSOLUE\n");

  scanf("%d%*c", &choix);

  switch (choix) {
    case 1:
      niveau = "NOMINAL\n";
      break;
    case 2:
      niveau = "URGENT\n";
      break;
    case 3:
      niveau = "URGENCE ABSOLUE\n";
      break;
    default:
      printf("La saisie n'est pas correcte.\n");
  }
  return niveau;
}

char * typeAlerte() {
  char *type = NULL;
  int choix = 0;

  type = malloc(21 * sizeof(char));

  if (type == NULL) {
    printf("Erreur d'allocation memoire pour le type d'alerte\n");
    exit(EXIT_FAILURE);
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
      type = "ACCIDENT ROUTE\n";
      break;
    case 3:
      type = "ACCIDENT MER\n";
      break;
    case 4:
      type = "ACCIDENT MONTAGNE\n";
      break;
    case 5:
      type = "MALAISE\n";
      break;
    case 6:
     type = "EXPLOSION\n";
     break;
    case 7:
      type = "ACCIDENT DE LA VIE\n";
      break;
    default:
      printf("La saisie n'est pas correcte.\n");
  }
  return(type);
}

void ajouterAlerte(Alerte **alerte, int *compteurAlerte) {
  char tmpChaine[LIEU_TAILLE];
  char sBuffer[TAILLE_BUFFER];
  int tmpNombre = 0;
  char *ptrType = NULL;
  char *ptrNiveau = NULL;
  int i;

  i = *compteurAlerte;

  printf("Code d'alerte :\n");
  //scanf("%d%*c", &tmpNombre);
  tmpNombre = genererCodeAlerte();
  (*alerte)[i].iCode = tmpNombre;

  printf("Type d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  //ptrType = typeAlerte();
  strcpy((*alerte)[i].cType, "Hello\n");

  printf("Niveau d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  //ptrNiveau = niveauAlerte();
  strcpy((*alerte)[i].cNiveau, "Hello\n");

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
    printf("Description : %s", (*alerte)[i].cDescription);
    printf("DEBUG: i = %d\n", i);
  }
}

/* TODO: la recherche affiche que le prèmier élément */
void afficherUneAlerte(Alerte **alerte, int *compteurAlerte) {
  int i = 0;
  int iCodeDonne = 0;

  if (*compteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'alerete :\n");
  scanf("%d%*c", &iCodeDonne);

  for (i = 0; i < (*compteurAlerte); i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
      printf("Type d'alerte : %s", (*alerte)[i].cType);
      printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
      printf("Lieu : %s", (*alerte)[i].cLieu);
      printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
      printf("Description : %s", (*alerte)[i].cDescription);
    }
  }
  /* TODO: Afficher message si alerte n'a pas été trouvée */
}

void modifierAlerte(Alerte **alerte, int *compteurAlerte) {
  int i = 0;

  int iCodeDonne = 0;
  char tmpChaine[LIEU_TAILLE];
  int tmpNombre = 0;

   if (*compteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'alerete :\n");
  scanf("%d%*c", &iCodeDonne);

   for (i = 0; i < *compteurAlerte; i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      printf("Code d'alerte à modifier: %d\n", (*alerte)[i].iCode);

      printf("Type d'alerte :\n");
      strcpy((*alerte)[i].cType, "Hello\n");

      printf("Niveau d'alerte :\n");
      strcpy((*alerte)[i].cNiveau, "Hello\n");

      printf("Lieu :\n");
      fgets(tmpChaine, LIEU_TAILLE, stdin);
      strcpy((*alerte)[i].cLieu, tmpChaine);

      printf("Nombre de victimes :\n");
      scanf("%d%*c", &tmpNombre);
      (*alerte)[i].iNombreVictimes = tmpNombre;

      printf("Description :\n");
      fgets(tmpChaine, LIEU_TAILLE, stdin);
      strcpy((*alerte)[i].cDescription, tmpChaine);
    }
  }
  printf("Alerte avec le code %d a été bien modifié.\n", iCodeDonne);
}

void supprimerAlerte(Alerte **alerte, int *compteurAlerte) {
  int iCodeDonne = 0;
  int i = 0;

  if (*compteurAlerte == 0) {
   printf("Aucune alerte n'a été enregistrée\n");
   return;
  }

  printf("Donnez le code d'alerte pour la suppression :\n");
  scanf("%d%*c", &iCodeDonne);

  for (i = 0; i < (*compteurAlerte); i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      (*alerte)[i].iCode = (*alerte)[i+1].iCode;
      strcpy((*alerte)[i].cType, (*alerte)[i+1].cType);
      strcpy((*alerte)[i].cNiveau, (*alerte)[i+1].cNiveau);
      strcpy((*alerte)[i].cLieu, (*alerte)[i+1].cLieu);
      (*alerte)[i].iNombreVictimes = (*alerte)[i+1].iNombreVictimes;
      strcpy((*alerte)[i].cDescription, (*alerte)[i+1].cDescription);
    }
  }
  /* TODO: Afficher message si alerte n'a pas été trouvée */

  (*compteurAlerte)--;

   *alerte = realloc(*alerte, (*compteurAlerte * sizeof(Alerte)));

  if (*alerte == NULL) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }

  printf("DEBUG: La mémoire a été realouée après la suppression\n");

  printf("Alerte avec le code %d a été bien supprimé\n", iCodeDonne);
}
