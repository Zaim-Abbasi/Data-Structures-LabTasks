#pragma once
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
