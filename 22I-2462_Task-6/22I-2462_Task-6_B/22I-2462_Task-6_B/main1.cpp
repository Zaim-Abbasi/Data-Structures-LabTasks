#include<iostream>
#include "Circular.h"
using namespace std;
int main()
{
    Circular c1;
    int choice;
    int data;
    int before;
    while (true)
    {
        cout << "1. Insert Last" << endl;
        cout << "2. Insert Beginning" << endl;
        cout << "3. Insert Before Node" << endl;
        cout << "4. Delete First Node" << endl;
        cout << "5. Delete Last Node" << endl;
        cout << "6. Display" << endl;
        cout << "7. Sort" << endl;
        cout << "8. Dublicate" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            c1.InsertLast(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            c1.InsertBeginning(data);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter before: ";
            cin >> before;
            c1.InsertBeforeNode(data, before);
            break;
        case 4:
            c1.DeleteFirstNode();
            break;
        case 5:
            c1.DeleteLastNode();
            break;
        case 6:
            c1.Display();
            break;
        case 7:
            c1.Sort();
            break;
        case 8:
            c1.Dublicate();
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;

}