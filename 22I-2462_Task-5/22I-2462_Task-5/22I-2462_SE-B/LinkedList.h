#pragma once
#include <iostream>
#include "Employee.h"
#include "Node.h"
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

    void insert(Node* head, Employee &emp)
    {
        Node *temp = new Node(emp);
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
        cout << "Clear Function" << endl;
        // deallocates memory to store a list
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
        // Required that list is not empty. Sort the node on basis of salary. Don't copy the data of nodes to each other
        Node *current = head;
        Node *index = nullptr;
        int temp;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            while (current != nullptr)
            {
                index = current->next;
                while (index != nullptr)
                {
                    if (current->EmployeeData.salary > index->EmployeeData.salary)
                    {
                        // swap kar do
                        swap(current->EmployeeData.salary, index->EmployeeData.salary);
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};
