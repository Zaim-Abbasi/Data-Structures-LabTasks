#include "AVL.h"
int main()
{
    AVLTree avlTree;

    int choice, data;
    while (1)
    {
        cout << "\n1. Insertion in AVL Tree" << endl;
        cout << "2. Print AVL Tree" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> data;
            avlTree.Insert(data);
            break;
        case 2:
            cout << "AVL Tree:" << endl;
            avlTree.display();
            cout << endl;
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}