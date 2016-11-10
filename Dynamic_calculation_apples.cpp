#include <iostream>
using namespace std;

int main() {
	int green, red, percentageGreen, percentageRed, total;
	int g = 0, r = 0;
	char apple;
	
	do {
		cout << "Tapez 'g' pour une pomme verte" << endl;
		cout << "Tapez 'r' pour une pomme rouge" << endl;
		cout << "Tapez 'q' pour terminer" << endl;	
		cin >> apple;
		
	if (apple == 'g')
		g += 1;
	if (apple == 'r')
		r += 1;	

	} while (apple != 'q');
	
	total = g + r;
	percentageGreen = g * 100 / total;
	percentageRed = r * 100 / total;
	
	cout << "Sur " << total << " pommes, il y a: " << endl; 
	cout << percentageGreen << "% vertes" << endl;
	cout << percentageRed << "% rouges" << endl;
}
