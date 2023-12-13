#pragma once
#include<iostream>
#include "Node.h"
#include "dublicate.h"
using namespace std;
class Circular
{
    Node *node;
public:
    Circular()
    {
        node = nullptr;
    }
    
    void InsertLast(int data)
    {
        Node* temp = new Node(data);
        if(node == nullptr)
        {
            node = temp;
            node->next = node;
            node->prev = node;
        }
        else
        {
            Node* last = node->prev;
            last->next = temp;
           
            temp->next = node;
            node->prev = temp;
            temp->prev = last;
           
        }
    }

    void InsertBeginning(int data)
    {
        // beginning
        Node *temp = new Node(data);
        temp->next = node;
        temp->prev = node->prev;
        node->prev = temp;
        node = temp;
    }

    void InsertBeforeNode(int data, int before)
    {
        Node *temp = new Node(data);
        Node *t = node;
        while(t->data != before)
        {
            t = t->next;
        }
        temp->next = t;
        temp->prev = t->prev;
        t->prev->next = temp;
        t->prev = temp;
    }


    void DeleteFirstNode()
    {
        Node *temp = node;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node = node->next;
        delete temp;

    }

    void DeleteLastNode()
    {
        Node *temp = node->prev;
        node->prev = temp->prev;
        temp->prev->next = node;
        delete temp;
    }

    void DeleteMiddle(int data)
    {
        Node *temp = node;
        while(temp->data != data)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void DeleteSpecificNode(int data, int position)
    {
        if(position == 1)
        {
            DeleteFirstNode();
        }
        else if(position == 2)
        {
            DeleteLastNode();
        }
        else
        {
            DeleteMiddle(data);
        }
    }

    void Display()
    {
        Node *temp= node;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        }
            while (temp != node);
            cout << endl;
    }
    void Sort()
    {
        sort(node);
    }
    void Dublicate()
    {
        dublicate(node);
    }
};
