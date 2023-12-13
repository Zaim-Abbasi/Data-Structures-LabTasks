#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node()
    {
        left = right = NULL;
        height = 1;
    }
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};