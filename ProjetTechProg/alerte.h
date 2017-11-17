#ifndef ALERTE_H
#define ALERTE_H
#include <stdio.h>

#define LIEU_TAILLE 150
#define DESCRIPTION_TAILLE 150
#define TAILLE_TYPE 21
#define TAILLE_NIVEAU 21
#define TAILLE_INITIALE_DE_MALLOC 2
#define TAILLE_BUFFER 21


typedef struct {
  int iCode;
  char cType[TAILLE_TYPE];
  char cNiveau[TAILLE_NIVEAU];
  char cLieu[LIEU_TAILLE];
  int iNombreVictimes;
  char cDescription[DESCRIPTION_TAILLE];
} Alerte;

void ajouterAlerte(Alerte **alerte, int *compteurAlerte);
void afficherUneAlerte(Alerte **alerte, int *compteurAlerte);
void afficherToutesAlertes(Alerte **alerte, int *compteurAlerte);
void modifierAlerte(Alerte **alerte, int *compteurAlerte);
void supprimerAlerte(Alerte **alerte, int *compteurAlerte);
//void typeAlerte(Alerte alerte, int *compteurAlerte);
//void niveauAlerte(Alerte alerte, int *compteurAlerte);
char * typeAlerte();
char * niveauAlerte();
int genererCodeAlerte();

#endif
