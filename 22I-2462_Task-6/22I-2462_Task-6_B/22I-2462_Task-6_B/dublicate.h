#pragma once
#include<iostream>
#include "Node.h"

void sort(Node *head)
{
    // bubble sort
    Node *i, *j;
    for (i = head; i->next != head; i = i->next)
    {
        for (j = head; j->next != head; j = j->next)
        {
            if (j->data > j->next->data)
            {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void dublicate(Node *head)
{
    sort(head);
    Node *t = head;
    while(t->next != head)
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