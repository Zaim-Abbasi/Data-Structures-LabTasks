#include<iostream>
using namespace std;
class Employee{
public:
    string name;
    int age;
    float salary;
    Employee(){}
    Employee(string name, int age, float salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
};