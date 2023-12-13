#include<iostream>
#include "Header.h"
using namespace std;
int main() {
	int size;
	cout << "Enter size of your array:";
	cin >> size;
	int* arr = new int[size];
	cout << "Now Enter elements in the array:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Element " << i << ":";
		cin >> arr[i];
	}
	cout << minumum(arr, size) << endl;;
	cout << maximum(arr, size);

}