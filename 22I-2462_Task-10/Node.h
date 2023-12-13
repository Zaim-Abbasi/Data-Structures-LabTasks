#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        left = right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};