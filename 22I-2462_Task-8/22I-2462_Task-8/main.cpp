#include "Queue-1.h"
int main()
{
    Queue q;
    
    int choice;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Display Front" << endl;
        cout << "5. Check isEmpty()" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            q.Enqueue();
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.Display();
            break;
        case 4:
            q.ShowFront();
            break;
        case 5:
            if(q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queus is not Empty" << endl;
            break;
        case 6:
            cout << "Exiting...." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (true);
}

