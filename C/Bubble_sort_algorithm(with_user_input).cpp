#include <iostream>
using namespace std;

void treebull(int[], int);

int main() {
	const int nbE = 5;
	int tab[nbE];
	
	for (int i = 0; i < nbE; i++) 
	{
		cout << "Give the element " << i + 1 << " : ";
		cin >> tab[i];
	}

	cout << endl;
	cout << "Before: " << endl;
	for (int i = 0; i < nbE; i++) {
		cout << tab[i] << endl;
	}

	treebull(tab, nbE);

	cout << endl;

	cout << "After: " << endl;
	for (int i = 0; i < nbE; i++) {
		cout << tab[i] << endl;
	}
}

void treebull(int tab[], int nbE) {
	bool trouve; 
	int aux;
	
	do {
		trouve = false;
		for (int i = 1; i < nbE; i++) {
			if (tab[i] < tab[i-1]) {
				aux = tab[i-1];
				tab[i-1] = tab[i];
				tab[i] = aux;
				trouve = true;
			}
		}			
	} while (trouve);	
}
