#include <iostream>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
struct Node
{
    string word;
    int count;
    int height;
    Node *left;
    Node *right;

    Node(string w)
    {
        word = w;
        count = 1;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};
