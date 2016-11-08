#include <iostream>
using namespace std;

int main () {
	int tab[5]; 
	int min, max;
	
	for (int i = 0; i < 5; i++) {  // loop to get values from user      
		cout << "Donnez le valeur " << i + 1 << ": " << endl; 
		cin >> tab[i];	// saving values in the table
	}
	min = max = tab[0]; // considering min and max values the element in first[0] position of the table
	
	for (int j = 1; j < 5; j++) { // loop to search values in the table 
		if (tab[j] > max) // looking for bigger value than in position [0] 
		max = tab[j]; // if found assigning this value to bigger
		if (tab[j] < min) // looking for lower value than in position [0] 
		min = tab[j]; // if found assigning this value to lower
	}
	cout << "Max valeur: " << max << endl; 
	cout << "Min valeur : " << min << endl;	
}
