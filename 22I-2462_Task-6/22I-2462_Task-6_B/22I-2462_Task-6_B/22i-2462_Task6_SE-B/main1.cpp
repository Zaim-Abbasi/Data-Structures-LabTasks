#include<iostream>
#include "Circular.h"
using namespace std;
int main()
{
    Circular c1;

    c1.InsertLast(10);
    c1.InsertLast(20);
    c1.InsertLast(30);
    c1.InsertLast(10);
    c1.InsertLast(5);

    // c1.InsertBeginning(5);



    c1.Sort();
    c1.Display();
    c1.DeleteFirstNode();

    c1.DeleteLastNode();
    c1.Display();
}