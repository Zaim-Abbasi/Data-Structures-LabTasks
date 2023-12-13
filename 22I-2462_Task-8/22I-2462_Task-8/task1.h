#include<iostream>
using namespace std;
class Node{
public:
    string name;
    int EMpId;
    Node *head;
};
class Queue{
public:
    Node *front;
    Node *back;
    Queue()
    {
        front = back = nullptr;
    }
    void Enqueue(string name, int )
};