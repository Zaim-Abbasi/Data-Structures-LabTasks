#pragma once
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
public:
    Node()
    {
        this->data = 0;
        this->next = nullptr;

    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Stack{
public:
    Node* head;
    int size;

public:
    Stack()
    {
        head = nullptr;
        size = 0;
    }
    void Push(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    void Pop()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int Peek()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty()
    {
        if(size == 0 || size < 1)
            return true;
        else
            return false;
    }
    void Display()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};