#include <iostream>
using namespace std;

int main()
{
	int rows; 
	
	cout << "Enter the number of Pascal rows: "; 
	cin >> rows;
	
	for (int i = 0; i < rows; i++)
	{
		int val = 1;
		cout.width(rows - i);
		for (int j = 0; j <= i; j++)
		{
			cout << val << " ";
			val = val * (i - j) / (j + 1);
		}	
		cout << endl;
	}
}
