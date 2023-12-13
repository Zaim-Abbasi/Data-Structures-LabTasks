#pragma once
#include<iostream>
using namespace std;
int minumum(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int maximum(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}