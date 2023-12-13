#include "Node.h"
class BST{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void Insert()
    {
        int data;
        cout << "Enter element to enter in BST: ";
        cin >> data;
        Node *newNode = new Node(data);

        // code to insert node in BST
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *tempNode = root;
            while (tempNode)
            {
                if (data < tempNode->data)
                {
                    if (tempNode->left)
                    {
                        tempNode = tempNode->left;
                    }
                    else
                    {
                        tempNode->left = newNode;
                        break;
                    }
                }
                else if (data > tempNode->data)
                {
                    if (tempNode->right)
                    {
                        tempNode = tempNode->right;
                    }
                    else
                    {
                        tempNode->right = newNode;
                        break;
                    }
                }
                else
                {
                    cout << "duplicate value found in tree\n";
                    break;
                }
            }
        }
    }

    void Depth()
    {
        Node *temp = root;
        int depth = 0;
        int key;
        bool flag = false;
        cout << "Enter a number to find depth: ";
        cin >> key;
        while(temp != NULL)
        {
            if(key == temp->data)
            {
                cout << "Depth of "<<key<<" is " << depth << endl;
                flag = true;
                break;
            }
            // travserse to search a node
            if(key < temp->data)
            {
                // left jana ha
                temp = temp->left;
            }
            if(key > temp->data)
            {
                //right jana ha
                temp = temp->right;
            }
            depth++;
        }
        if(flag == false)
            cout << key << "Not Found in BST" << endl;
        cout << endl;
    }

    int RangeCounter(Node* root, int min, int max, int counter)
    {
        // inorder
        if(root == NULL)
            return counter;
        RangeCounter(root->left, min, max, counter);
        if(root->data >= min && root->data <=max)
            counter++;
        RangeCounter(root->right, min, max, counter);
    }
    void Range()
    {
        int minRange, maxRange, counter = 0;
        // travserse karna ha
        cout << "Enter minRange: ";
        cin >> minRange;
        cout << "Enter maxRange: ";
        cin >> maxRange;

        int range = RangeCounter(root, minRange, maxRange, counter);

        cout << "Range is " << range << endl;
        cout << endl;
    }

    void KthCounter(Node* root, int num, int counter)
    {
        if(root == NULL)
            return;
        KthCounter(root->left, num, counter);
        counter++;
        if(counter == num)
            cout << counter << " smallest element is " << root->data << endl;
        KthCounter(root->right, num, counter);
    }

    void Kth()
    {
        int num, counter = 0;
        cout << "Enter a number to find it's kth smallest element: ";
        cin >> num;

        KthCounter(root, num, counter);
    }

    void Display(Node* root)
    {
        // displaying node using inorder
        if(root == NULL)
            return;
        Display(root->left);
        cout << root->data << " ";
        Display(root->right);
    }
};