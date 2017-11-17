#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "alerte.h"

int genererCodeAlerte(/* Alerte **alerte, int *compteurAlerte */) {
  int nombreGenere = 0;
  int existeAlerte = 0;
  // int i = 0;

  nombreGenere = rand() % 50001;

  /* do {
    nombreGenere = rand() % 3;
    for (i = 0; i < (*compteurAlerte); i++) {
      if (nombreGenere == (*alerte)[i].iCode) {
        existeAlerte = 1;
      }
    }
  }while (existeAlerte); */

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

  printf("╔═══════════════════════════════════╗\n");
  printf("║                                   ║\n");
  printf("║           NIVEAU ALERTE           ║\n");
  printf("║                                   ║\n");
  printf("╠════╦══════════════════════════════╣\n");
  printf("║    ║                              ║\n");
  printf("║ 1  ║ NOMINAL                      ║\n");
  printf("║    ║                              ║\n");
  printf("║ 2  ║ URGENT                       ║\n");
  printf("║    ║                              ║\n");
  printf("║ 3  ║ URGENCE ABSOLUE              ║\n");
  printf("║    ║                              ║\n");
  printf("╚════╩══════════════════════════════╝\n");

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

  printf("╔═══════════════════════════════════╗\n");
  printf("║                                   ║\n");
  printf("║            TYPE ALERTE            ║\n");
  printf("║                                   ║\n");
  printf("╠════╦══════════════════════════════╣\n");
  printf("║    ║                              ║\n");
  printf("║ 1  ║ INCENDIE                     ║\n");
  printf("║    ║                              ║\n");
  printf("║ 2  ║ ACCIDENT DE LA ROUTE         ║\n");
  printf("║    ║                              ║\n");
  printf("║ 3  ║ ACCIDENT EN MER              ║\n");
  printf("║    ║                              ║\n");
  printf("║ 4  ║ ACCIDENT EN MONTAGNE         ║\n");
  printf("║    ║                              ║\n");
  printf("║ 5  ║ MALAISE                      ║\n");
  printf("║    ║                              ║\n");
  printf("║ 6  ║ EXPLOSION                    ║\n");
  printf("║    ║                              ║\n");
  printf("║ 7  ║ ACCIDENT DE LA VIE           ║\n");
  printf("║    ║                              ║\n");
  printf("╚════╩══════════════════════════════╝\n");


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

  printf("Description :\n");      //scanf("%s%*c", tmpChaine);
  fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  strcpy((*alerte)[i].cDescription, tmpChaine);

  printf("Alerte a été bien crée avec le code suivant : %d\n", (*alerte)[i].iCode);
}

void afficherToutesAlertes(Alerte **alerte, int *compteurAlerte) {
  int i = 0;

   if (*compteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

   for (i = 0; i < *compteurAlerte; i++) {
    printf("\n");
    printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
    printf("Type d'alerte : %s", (*alerte)[i].cType);
    printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
    printf("Lieu : %s", (*alerte)[i].cLieu);
    printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
    printf("Description : %s", (*alerte)[i].cDescription);
    printf("DEBUG: i = %d\n", i);
    //scanf("%*c");
  }
}

void afficherUneAlerte(Alerte **alerte, int *compteurAlerte) {
  int i = 0;
  int iCodeDonne = 0;
  int existeAlerte = 0;

  if (*compteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'alerte :\n");
  scanf("%d%*c", &iCodeDonne);

  for (i = 0; i < (*compteurAlerte); i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      printf("\n");
      printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
      printf("Type d'alerte : %s", (*alerte)[i].cType);
      printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
      printf("Lieu : %s", (*alerte)[i].cLieu);
      printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
      printf("Description : %s", (*alerte)[i].cDescription);
      existeAlerte = 1;
    }
  }
  if (!existeAlerte)
    printf("Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
}

void modifierAlerte(Alerte **alerte, int *compteurAlerte) {
  int i = 0;
  int existeAlerte = 0;
  char *ptrType = NULL;
  char *ptrNiveau = NULL;

  int iCodeDonne = 0;
  char tmpChaine[LIEU_TAILLE];
  int tmpNombre = 0;

   if (*compteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }
//void typeAlerte(Alerte alerte, int *compteurAlerte);
//void niveauAlerte(Alerte alerte, int *compteurAlerte);
  printf("Donnez le code d'alerte :\n");
  scanf("%d%*c", &iCodeDonne);

   for (i = 0; i < *compteurAlerte; i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      printf("Code d'alerte à modifier: %d\n", (*alerte)[i].iCode);

      printf("Type d'alerte :\n");
      ptrType = typeAlerte();
      strcpy((*alerte)[i].cType, ptrType);

      printf("Niveau d'alerte :\n");
      ptrNiveau = niveauAlerte();
      strcpy((*alerte)[i].cNiveau, ptrNiveau);

      printf("Lieu :\n");
      fgets(tmpChaine, LIEU_TAILLE, stdin);
      strcpy((*alerte)[i].cLieu, tmpChaine);

      printf("Nombre de victimes :\n");
      scanf("%d%*c", &tmpNombre);
      (*alerte)[i].iNombreVictimes = tmpNombre;

      printf("Description :\n");
      fgets(tmpChaine, LIEU_TAILLE, stdin);
      strcpy((*alerte)[i].cDescription, tmpChaine);

      existeAlerte = 1;
    }
  }
  if (!existeAlerte) {
    printf("Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
  } else {
    printf("Alerte avec le code %d a été bien modifiée.\n", iCodeDonne);
  }
}

void supprimerAlerte(Alerte **alerte, int *compteurAlerte) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;

  if (*compteurAlerte == 0) {
   printf("Aucune alerte n'a été enregistrée\n");
   return;
  }

  printf("Donnez le code d'alerte pour la suppression :\n");
  scanf("%d%*c", &iCodeDonne);

  while (i < *compteurAlerte && iCodeDonne != (*alerte)[i].iCode) {
    i++;
  }

  if (i == *compteurAlerte) {
    printf("alerte n'a pas été trouvée.\n");
    return;
  } else {
    for (j = i; j < (*compteurAlerte); j++) {
        (*alerte)[j].iCode = (*alerte)[j+1].iCode;
        strcpy((*alerte)[j].cType, (*alerte)[j+1].cType);
        strcpy((*alerte)[j].cNiveau, (*alerte)[j+1].cNiveau);
        strcpy((*alerte)[j].cLieu, (*alerte)[j+1].cLieu);
        (*alerte)[j].iNombreVictimes = (*alerte)[j+1].iNombreVictimes;
        strcpy((*alerte)[j].cDescription, (*alerte)[j+1].cDescription);
    }
  }

  (*compteurAlerte)--;

  *alerte = realloc(*alerte, (*compteurAlerte * sizeof(Alerte)));

  if (*alerte == NULL && *compteurAlerte > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }

  printf("DEBUG: La mémoire a été realouée après la suppression\n");

  printf("Alerte avec le code %d a été bien supprimé\n", iCodeDonne);
}
