#include "Employee.h"
class Node{
public:
    Employee *empObj;
    Node *next;
    Node(){
        next = nullptr;
        empObj = nullptr;
    }
    Node(Employee* empObj)
    {
        this->empObj = empObj;
        this->next = nullptr;
    }
};