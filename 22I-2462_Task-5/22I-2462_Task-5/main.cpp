#include <iostream>
using namespace std;
class Employee
{
public:
    int EmpId;
    string NIC;
    double salary;
    double bonus;

public:
    Employee()
    {
        EmpId = 0;
        NIC = "";
        salary = 0.0;
        bonus = 0.0;
    }
    Employee(int id, string nic, double sal, double bon)
    {
        EmpId = id;
        NIC = nic;
        salary = sal;
        bonus = bon;
    }
    void Display()
    {
        cout << "Employee ID: " << EmpId << endl;
        cout << "NIC: " << NIC << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << endl;
    }
};

class Node
{
    // has record of an employee and a pointer to next node
public:
    Employee EmployeeData;
    Node *next;

public:
    Node()
    {
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList()
    {
        clear();
    }

    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp->EmployeeData.Display();
            temp = temp->next;
        }
    }

    void insert(Employee &emp)
    {
        Node *temp = new Node();
        temp->EmployeeData = emp;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }
    void Remove(int id)
    {
        Node *current = head;
        Node *previous = nullptr;
        bool found = false;
        while (current != nullptr)
        {

            if (current->EmployeeData.EmpId == id)
            {
                found = true;
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                break;
            }
            previous = current;
            current = current->next;
        }
        if (found == false)
        {
            cout << "Record Not Found" << endl;
        }
    }

    void UpdateSalary(const int &salary, int id)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->next != NULL)
            {
                if (current->EmployeeData.EmpId == id)
                {
                    // update salary
                    current->EmployeeData.salary = salary;
                }
            }
            current = current->next;
        }
    }
    void UpdateBonus(const int &bonus, int id)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->next != NULL)
            {
                if (current->EmployeeData.EmpId == id)
                {
                    // update bonus
                    current->EmployeeData.salary = bonus;
                }
            }
            current = current->next;
        }
    }

    void clear()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    bool IsEmpty()
    {
        Node *temp = head;
        if (temp->next == nullptr)
        {
            return true;
        }
        else
            return false;
    }

    void Sort()
    {
        Node *current = head;
        Node *index = nullptr;

        while (current != nullptr)
        {
            index = current->next;
            while (index != nullptr)
            {
                if (current->EmployeeData.salary > index->EmployeeData.salary)
                {
                    // swap Node
                    Employee temp = current->EmployeeData;
                    current->EmployeeData = index->EmployeeData;
                    index->EmployeeData = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
};

int main()
{
    LinkedList l1;

    Employee E1(1, "123", 10000, 10);
    Employee E2(2, "456", 200000, 20);
    Employee E3(3, "789", 3000, 30);

    l1.insert(E1);
    l1.insert(E2);
    l1.insert(E3);
    l1.Display();

    l1.Remove(2);
    l1.Display();

    l1.UpdateSalary(200, 2);
    l1.UpdateBonus(150, 1);

    l1.Display();
    cout << l1.IsEmpty();
    cout << endl;
    
    l1.Sort();
    l1.Display();
    return 0;
}
