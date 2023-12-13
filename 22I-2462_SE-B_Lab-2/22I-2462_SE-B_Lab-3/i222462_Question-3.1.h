#pragma once
#include <iostream>
using namespace std;
int Common(int *arr1, int *arr2, int size1, int size2)
{
    int counter = 0;
    int *originalArr = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        originalArr[i] = arr1[i];
    }

    for (int i = 0; i < size1; i++)
    { // finding common elements
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr1[counter] = arr2[j];
                counter++;
            }
        }
    }
    int *newArr = new int[counter];
    for (int i = 0; i < counter; i++)
    {
        newArr[i] = arr1[i];
    }
    // Displaying
    cout << "Displaying same elements in both Arrays:";
    for (int i = 0; i < counter; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;

    // Concatenating
    int size = size1 - counter, count = 0;
    int *concatArr = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        if (originalArr[i] != newArr[i])
        {
            concatArr[count] = originalArr[count];
            count++;
        }
    }
    cout << "Displaying concat Array:";
    for (int i = 0; i < size1; i++)
    {
        cout << concatArr[i] << " ";
    }
}