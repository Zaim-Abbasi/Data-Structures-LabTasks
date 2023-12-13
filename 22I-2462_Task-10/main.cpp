#include <iostream>
#include "height.h"
using namespace std;

int main()
{
    BST obj;
    int choice;

    while(true)
    {
    cout << "Enter your choice: " << endl;
    cout << "1. Insert Value in BST " << endl;
    cout << "2. Find Height of BST " << endl;
    cout << "3. Display BST" << endl;
    cout << "4. Depth" << endl;
    cout << "5. Range: " << endl;
    cout << "6. Kth smallest" << endl;
    cout << "7. Exit" << endl;

    cin >> choice;
    switch (choice)
    {
    case 1:
        obj.Insert();
        break;
    case 2:
        Height(obj);
        break;
    case 3:
        cout << "\nDisplaying Tree: ";
        obj.Display(obj.root);
        cout << endl;
        break;
    case 4:
        obj.Depth();
        break;
    case 5:
        obj.Range();
        break;
    case 6:
        obj.Kth();
        break;
    case 7:
        cout << "Exiting..." << endl;
        exit(0);
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    }
    return 0;

}