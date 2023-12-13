#pragma once
#include<iostream>
using namespace std;
class Sorting
{
private:
	int rows, columns;

public:
	int **ptr;
	Sorting() {}
	Sorting(int columns)
	{
		this->rows = 3;
		this->columns = columns;
		ptr = new int *[rows];
		for (int i = 0; i < rows; i++)
		{
			ptr[i] = new int[columns];
		}
	}

	void Input(int rows, int columns, int **ptr)
	{
		cout << "Enter elements: " << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cin >> ptr[i][j];
			}
		}
	}

	void InsertionSort(int rows, int columns, int **ptr)
	{
		int *arr = new int[columns];
		int arrCounter = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[arrCounter] = ptr[i][j];
				arrCounter++;
			}
		}

		int i, key, j;
		for (i = 1; i < columns; i++)
		{
			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}

		arrCounter = 0;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ptr[i][j] = arr[arrCounter];
				arrCounter++;
			}
		}
	}

	void BubbleSort(int rows, int columns, int **ptr)
	{
		cout << "Entered Bubble Sort" << endl;
		int *arr = new int[columns];
		int arrCounter = 0;
		for (int i = 2; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[arrCounter] = ptr[i][j];
				arrCounter++;
			}
		}

		for (int i = 0; i < rows - 1; i++)
		{
			for (int j = 0; j < columns - 1 - i; j++)
			{
				if (arr[j + 1] < arr[j])
				{
					// swap
					int temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		arrCounter = 0;

		for (int i = 2; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ptr[i][j] = arr[arrCounter];
				arrCounter++;
			}
		}
	}

	void SelectionSort(int rows, int columns, int **ptr)
	{
		int *arr = new int[columns];
		int arrCounter = 0;
		for (int i = 1; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[arrCounter] = ptr[i][j];
				arrCounter++;
			}
		}

		// actual selection sort
		for (int i = 0; i < rows; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < columns; j++)
			{
				if (arr[j] < arr[minIndex])
					minIndex = j;
			}
			// swap
			int temp = arr[minIndex];
			arr[minIndex] = arr[i];
			arr[i] = temp;
		}

		arrCounter = 0;

		for (int i = 1; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ptr[i][j] = arr[arrCounter];
				arrCounter++;
			}
		}
	}

	void Display(int rows, int columns, int **ptr)
	{
		cout << "Displaying elements: " << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << "Row " << i + 1 << ": ";
			for (int j = 0; j < columns; j++)
			{
				cout << ptr[i][j] << " ";
			}
			cout << endl;
		}
	}
};