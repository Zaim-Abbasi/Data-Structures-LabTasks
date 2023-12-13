#include<iostream>
#include "Task-1.h"
#include "Task-2.h"
using namespace std;
int main()
{
    cout << "Select Task:"<<endl;
    cout << "1. Task-1" << endl;
    cout << "2. Task-2" << endl;
    int task;
    cin >> task;
    switch (task)
    {
    case 1:
        {
            Stack s;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Peek" << endl;
            cout << "4. isEmpty" << endl;
            cout << "5. Display" << endl;
            cout << "6. Exit" << endl;

            int choice;
            int data;
            while (true)
            {
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "Enter data: ";
                    cin >> data;
                    s.Push(data);
                    break;
                case 2:
                    s.Pop();
                    break;
                case 3:
                    cout << "Peek: " << s.Peek() << endl;
                    break;
                case 4:
                    if (s.isEmpty())
                        cout << "Stack Empty" << endl;
                    else
                        cout << "Stack not Empty" << endl;
                    break;
                case 5:
                    s.Display();
                    break;
                case 6:
                    exit(0);
                default:
                    cout << "Invalid choice" << endl;
                }
            }
            break;
        }
    case 2:
    {
        string s;
        cout<<"Enter string: ";
        cin>>s;
        if(IsBalanced(s))
            cout<<"Balanced"<<endl;
        else
            cout<<"Not Balanced"<<endl;
        // case 2
        break;
    }

    case 3:
    {


    }
    }
}