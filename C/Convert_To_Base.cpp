/*
*                                                       SUBJECT
*
* Write down a program that converts an integer from it's current base to a given base. 
*
*
*/

#include <iostream>
using namespace std;

void convertToBase(int number, int base)
{
	const int MAX = 100;
  	int BASE = 0;
	int array[MAX];
	int rest[MAX];
	int i = 0, j;

	/* Calculating the result and showing the dividers */
	cout << "Dividers: ";
	while (number > 0)
	{
		array[i] = number % BASE;
		rest[i] = array[i]; 
		i++;
		number /= BASE;
		cout << number << " ";
	}
	
	/* Calculating the rest of previous devision */
	cout << "\nThe rest of the division: ";
	for (int j = 0; j < i; j++)
	{
		cout << rest[j] << " ";
	}

	cout << "\nThe result: ";
	
	/* Print the result */		
	for (c = c-1; c >= 0; c--)
	{
		cout << array[c];
	}
	
 	 /* Skipping the line to print clearly the total result */
	cout << "\n" << endl; 
}
