#pragma once
#include<iostream>
#include "Node.h"

void sort(Node *node)
{
    // bubble sort
    Node *i, *j;
    for (i = node; i->next != node; i = i->next)
    {
        for (j = i->next; j != node; j = j->next)
        {
            if (i->data > j->data)
            {
                // swap nodes instead of data
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void dublicate(Node *node)
{
    sort(node);
    Node *t = node;
    while(t->next != node)
    {
        if(t->data == t->next->data)
        {
            Node *temp = t->next;
            t->next = temp->next;
            temp->next->prev = t;
            delete temp;
        }
        else
        {
            t = t->next;
        }
    }

}