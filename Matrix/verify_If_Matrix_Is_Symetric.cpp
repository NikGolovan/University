#include <iostream>
using namespace std;

#define LIGNE 3
#define COLONNE 3

int verifierSymetrique(int matrice[][COLONNE]) {
	bool estSymetrique = false;
	
	    for (int i = 0; i < LIGNE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            if (matrice[i][j] == matrice[j][i]) {
                estSymetrique = true;
       	 	}
   		}
    }
   	if (estSymetrique) {
   		return 1;
	   } else {
	   	return 0;
	   }
}

int main() {
    int matrice[LIGNE][COLONNE] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    bool estSymetrique;

	  estSymetrique = verifierSymetrique(matrice);

    if (estSymetrique) {
        cout << "Matrice est symetrique";
    } else {
        cout << "Matrice n'est pas symetrique";
    }
}

