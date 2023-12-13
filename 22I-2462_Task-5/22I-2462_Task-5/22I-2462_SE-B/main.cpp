#include <iostream>
#include "Employee.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList l1;
    

    Employee E1(1, "123", 10000, 10);
    Employee E2(2, "456", 200000, 20);
    Employee E3(3, "789", 3000, 30);

    Node N1(E1);

    l1.insert(&N1,E1);

    // l1.insert(E2);
    // l1.insert(E3);

    l1.Display();
}
