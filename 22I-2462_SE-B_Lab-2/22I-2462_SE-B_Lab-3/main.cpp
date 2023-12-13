#include<iostream>
// #include "i222462_Question-1.h"
// #include "i222462_Question-2.h"
#include "i222462_Question-3.1.h"
using namespace std;
int main() {
	////For Question-1
	//cout << "\nOutput for Question-1" << endl;
	//cout << "Smaller of 'a' and 'B' is: " << smaller('a', 'B') << endl;
	//cout << "Smaller of 12 and 15 is: " << smaller(12, 15) << endl;
	//cout << "Smaller of 44.2 and 33.1 is: " << smaller(44.2, 33.1) << endl;
	//
	////For Question-2
	//cout << "\nOutput for Question-2" << endl;
	//cout << "Smaller of 'a', 'B' and 'D' is: " << smaller('a', 'B','D') << endl;
	//cout << "Smaller of 12, 15 and 2 is: " << smaller(12, 15,2) << endl;
	//cout << "Smaller of 44.2, 33.1 and 12.2 is: " << smaller(44.2, 33.1, 12.2) << endl;

	//For Question-3
	//Declaring and initialising arrays
	int size1, size2;
	cout << "Enter size of Array-A:";
	cin >> size1;
	cout << "Enter size of Array-B:";
	cin >> size2;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	//Entering elements in array
	cout << "\nEnter elements in Array-A" << endl;
	for (int i = 0,a=1; i < size1; i++,a++)
	{
		cout << "Array-A Element " << a << ":";
		cin >> arr1[i];
	}
	cout << "\nEnter elements in Array-B" << endl;
	for (int i = 0, a = 1; i < size2; i++, a++)
	{
		cout << "Array-B Element " << a << ":";
		cin >> arr2[i];
	}
	Common(arr1, arr2, size1, size2);
	
}