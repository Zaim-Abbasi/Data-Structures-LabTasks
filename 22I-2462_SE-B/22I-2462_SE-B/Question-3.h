#pragma once
#include <iostream>
#include <string>
using namespace std;
bool Malkov(double **arr, int col, int row)
{
    double var1, var2, var3;
    var1 = var2 = var3 = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            var1 += arr[0][j];
        }
    }
    for (int i = 1; i <= 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            var2 += arr[1][j];
        }
    }
    for (int i = 2; i <= 2; i++)
    {
        for (int j = 0; j < col; j++)
        {
            var3 += arr[2][j];
        }
    }
    if (var1 == 1 && var2 == 1 && var3 == 1)
        return true;
    else
        return false;
}