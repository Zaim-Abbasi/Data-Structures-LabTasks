#include "Node.h"
#include <algorithm> // for max function
#include <queue>
class AVLTree
{
public:
    Node *root;

    AVLTree()
    {
        root = NULL;
    }

    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *currentNode)
    {
        Node *leftChild = currentNode->left;
        Node *rightChildOfLeft = leftChild->right;

        leftChild->right = currentNode;
        currentNode->left = rightChildOfLeft;

        currentNode->height = max(height(currentNode->left), height(currentNode->right)) + 1;
        leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

        // Return the new parent node
        return leftChild;
    }

    Node *leftRotate(Node *currentNode)
    {
        Node *rightChild = currentNode->right;
        Node *leftChildOfRight = rightChild->left;

        rightChild->left = currentNode;
        currentNode->right = leftChildOfRight;

        currentNode->height = max(height(currentNode->left), height(currentNode->right)) + 1;
        rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

        // Return the new parent node
        return rightChild;
    }

    
    Node *LR(Node *currentNode)
    {
        currentNode->left = leftRotate(currentNode->left);
        return rightRotate(currentNode);
    }


    Node *RL(Node *currentNode)
    {
    
        currentNode->right = rightRotate(currentNode->right);
        return leftRotate(currentNode);
    }

    Node *RR(Node *currentNode)
    {
        return leftRotate(currentNode);
    }

    Node *LL(Node *currentNode)
    {
        return rightRotate(currentNode);
    }

    Node *balance(Node *node)
    {
        int balance = balanceFactor(node);

        // Left Heavy ha
        if (balance > 1)
        {
            if (balanceFactor(node->left) < 0)
                return LR(node);
            else
                return LL(node);
        }
        // Right Heavy ha
        else if (balance < -1)
        {
            if (balanceFactor(node->right) > 0)
                return RL(node);
            else
                return RR(node);
        }

        return node;
    }


    void Insert(int data)
    {
        root = insert(root, data);
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
            return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        return balance(node);
    }

    // display level order
    void display()
    {
        if (root == NULL)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            cout << node->data << " ";

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }
    }
};
