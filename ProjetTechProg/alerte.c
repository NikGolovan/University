#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alerte.h"

char * typeAlerte() {
  char *chaine;
  int choix = 0;

  chaine = malloc(21 * sizeof(char));

  if (chaine == NULL)
    printf("Chaine is NULL\n");

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
      chaine = "INCENDIE\n";
      break;
  }
  return(chaine);
  free(chaine);
  printf("DEBUG: chaine : %s\n", chaine);
}

void ajouterAlerte(Alerte **alerte, int *compteurAlerte) {
  char tmpChaine[LIEU_TAILLE];
  int tmpNombre = 0;
  char *tmp;
  int i;

  i = *compteurAlerte;

  printf("Code d'alerte :\n");
  scanf("%d%*c", &tmpNombre);
  (*alerte)[i].iCode = tmpNombre;

  printf("Type d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  tmp = typeAlerte();
  strcpy((*alerte)[i].cType, tmp);

  printf("Niveau d'alerte :\n");
  fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  strcpy((*alerte)[i].cNiveau, tmpChaine);

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
