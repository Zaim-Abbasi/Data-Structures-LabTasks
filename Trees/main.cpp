#include<iostream>
using namespace std;

class Tree{
private:
    struct Node{
        int data;
        Node* left;
        Node* right;
    };
    Node* root;
public:
    void Inorder(Node* root)
    {
        // for inorder traversal in sort order
        if(root == NULL)
            return;
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    void Preorder(Node* root)
    {
        if(root == NULL)
            return;
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Postorder(Node* root)
    {
        if(root == NULL)
            return;
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }

    bool Insert(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        if(root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node* temp = root;
            while(temp != nullptr)
            {
                if(temp->data == value)
                {
                    cout << "Dublicates not allowed" << endl;
                    delete newNode;
                    return false;
                }
                else
                {
                    if(temp->data > value)
                    {
                        if(! temp->left)
                        {
                            temp->left = newNode;
                            temp = temp->left;
                        }
                    }
                    else if(temp->data < value)
                    {
                        if(! temp->right)
                        {
                            temp->right = newNode;
                        }
                        temp = temp->right;
                    }
                    return true;
                }

            }
        }
    }

    void Display()
    {
        //displaying tree after insert function
        cout<<"Inorder: ";
        Inorder(root);
        cout<<endl;
        cout<<"Preorder: ";
        Preorder(root);
        cout<<endl;
        cout<<"Postorder: ";
        Postorder(root);
        cout<<endl;

    }
};
int main()
{
    Tree tree;
    tree.Insert(10);
    tree.Insert(20);

    tree.Display();
}