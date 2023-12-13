#include "Node-1.h"
class Queue{
public:
    Node *front;
    Node *rear;
    Employee *empObj;
    Queue()
    {
        front = rear = nullptr;
    }
    void Enqueue()
    {
        string name;
        int age;
        float salary;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter salary: ";
        cin>>salary;
        empObj = new Employee(name, age, salary);
        Node *newNode = new Node(empObj);
        if(front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Dequeue()
    {
        if(front == nullptr)
        {
            cout << "Queue is already empty" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;

        temp = nullptr;
        delete temp;
    }

    void ShowFront()
    {
        Node *temp = front;
        cout << "Showing Front:" << endl;
        cout << "Name: " << temp->empObj->name;
        cout << "Age: " << temp->empObj->age;
        cout << "Salary: " << temp->empObj->salary;
    }

    bool isEmpty()
    {
        if(front == nullptr)
            return true;
        else
            return false;
    }
    void Display()
    {
        Node *temp = front;
        while(temp != nullptr)
        {
            cout << "Name: " << temp->empObj->name << endl;
            cout << "Age: " << temp->empObj->age << endl;
            cout << "Salary: " << temp->empObj->salary << endl;
            temp = temp->next;
        }
    }

};