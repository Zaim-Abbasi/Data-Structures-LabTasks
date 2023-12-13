#include "BST.h"
void Height(BST bst)
{
    // code to find height of BST
    int height = 0;
    Node *tempNode = bst.root;
    while (tempNode)
    {
        if (tempNode->left != nullptr)
        {
            tempNode = tempNode->left;
            height++;
        }
        else if (tempNode->right != nullptr)
        {
            tempNode = tempNode->right;
            height++;
        }
        else
        {
            break;
        }
    }
    cout << "Height of BST is: " << height << endl;
    cout << endl;
}