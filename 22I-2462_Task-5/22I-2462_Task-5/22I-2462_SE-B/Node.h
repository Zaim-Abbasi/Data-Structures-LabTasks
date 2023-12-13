#pragma once
#include <iostream>
#include "Employee.h"
class Node
{
    // has record of an employee and a pointer to next node
public:
    Employee EmployeeData;
    Node *next;

public:
    Node(Employee emp)
    {
        EmployeeData = emp;
        next = nullptr;
    }
};