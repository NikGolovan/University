/*
*                                                       SUBJECT
*
* Write down a program that prints a multiplication table. 
*
*
*/

#include <iostream>
using namespace std;

int main() {
	const int MAX = 10;
	int i, j;

	for (i=1; i <= MAX; i++) {  //left number
		if (j >= MAX) //when right number is equal or higher than 10
		cout << "\nTable de " << i << endl; //creates a phrase with new number of multiplication table
			for (j=1; j <= MAX; j++) //right number
			cout << i << " x "<< j << " = " << i*j << endl; //shows the actual table with its result
	}	
}
