/*
*                                                       SUBJECT
*
* Write down a program that calculate dynamically amount of apples and it's percentage. User enters as an input the type of apples
* to count. The codes for types of apples are:
* g for Green Apples
* r for Red Apples
* Program will run until user won't type a 'q' as an input. Afterwards, it's going to print the total of apples and the percentage of 
* each entered type. 
*
*/


#include <iostream>
using namespace std;

int main() {
	int green, red, percentageGreen, percentageRed, total;
	int g = 0, r = 0;
	char apple;
	
	do {
		cout << "Type g for green apples" << endl;
		cout << "Type r for red apples" << endl;
		cout << "Type q to finish" << endl;	
		cin >> apple;
		
	if (apple == 'g')
		g += 1;
	if (apple == 'r')
		r += 1;	

	} while (apple != 'q');
	
	total = g + r;
	percentageGreen = g * 100 / total;
	percentageRed = r * 100 / total;
	
	cout << "In a total of " << total << " apples, there are: " << endl; 
	cout << percentageGreen << "% of green apples" << endl;
	cout << percentageRed << "% of red apples" << endl;
}
