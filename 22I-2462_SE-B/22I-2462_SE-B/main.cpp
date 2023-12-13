#include <iostream>
#include "Question-1.h"
#include "Question-3.h"
using namespace std;
int main()
{
	int columns, rows = 3;
	cout << "Enter number of columns: ";
	cin >> columns;
	Sorting s(columns);
	s.Input(rows, columns, s.ptr);

	s.BubbleSort(rows, columns, s.ptr);
	s.SelectionSort(rows, columns, s.ptr);
	s.InsertionSort(rows, columns, s.ptr);

	s.Display(rows, columns, s.ptr);
	return 0;

// double **arr;
// double row, col;

// cout << "Enter number of rows: ";
// cin >> row;
// cout << "Enter number of columns: ";
// cin >> col;
// if(row!=col)
// {
// 	arr = new double *[row];
// 	for(int i=0; i<row; i++)
// 	{
// 		arr[i] = new double[col];
// 	}
// 	for (int i = 0; i < row;i++)
// 	{
// 		for (int j = 0; j < col;j++)
// 		{
// 			cout << "Enter element: ";
// 			cin >> arr[i][j];
// 		}
// 	}
// 	bool result = Malkov(arr, col, row);
// 	cout<<"Result: "<<result<<endl;
// }
}

