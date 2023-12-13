#include "node.h"
class AVLTree
{
public:
    Node *root;

public:
    AVLTree() : root(nullptr) {}
    int height(Node *node)
    {
        return (node == nullptr) ? 0 : node->height;
    }

    int balanceFactor(Node *node)
    {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *currentNode)
    {
        Node *leftChild = currentNode->left;
        Node *rightChildOfLeft = leftChild->right;

        leftChild->right = currentNode;
        currentNode->left = rightChildOfLeft;

        currentNode->height = max(height(currentNode->left), height(currentNode->right)) + 1;
        leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

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

        if (balance > 1)
        {
            if (balanceFactor(node->left) < 0)
                return LR(node);
            else
                return LL(node);
        }
        else if (balance < -1)
        {
            if (balanceFactor(node->right) > 0)
                return RL(node);
            else
                return RR(node);
        }

        return node;
    }

    Node *insert(Node *node, string word)
    {
        if (node == nullptr)
            return new Node(word);

        if (word < node->word)
            node->left = insert(node->left, word);
        else if (word > node->word)
            node->right = insert(node->right, word);
        else
            node->count++;

        node->height = 1 + max(height(node->left), height(node->right));

        return balance(node);
    }

    Node *findMinValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }


    Node *searchWord(Node *node, string word)
    {
        if (node == nullptr || node->word == word)
            return node;

        if (word < node->word)
            return searchWord(node->left, word);

        return searchWord(node->right, word);
    }

    void LoadDictionary()
    {
        string filename = "dictionary.txt";
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error: Could not open the file " << filename << endl;
            return;
        }

        string word;
        while (file >> word)
        {
            root = insert(root, word); // Update AVL tree with the modified insert function
        }

        file.close();
    }

    void autocompleteHelper(Node *node, const string &prefix)
    {
        if (node == nullptr)
        {
            return;
        }

        // If the current node's word starts with the prefix, print it
        if (node->word.compare(0, prefix.length(), prefix) == 0)
        {
            cout << node->word << " (Count: " << node->count << ")" << endl;
        }

        // Traverse the left subtree if the prefix is less than the current word
        if (prefix < node->word)
        {
            autocompleteHelper(node->left, prefix);
        }
        // Traverse the right subtree if the prefix is greater than the current word
        else if (prefix > node->word)
        {
            autocompleteHelper(node->right, prefix);
        }
        // If the prefix is equal to the current word, traverse both subtrees
        else
        {
            autocompleteHelper(node->left, prefix);
            autocompleteHelper(node->right, prefix);
        }
    }
    void autocomplete()
    {
        string prefix;
        cout << "Enter a prefix: ";
        cin >> prefix;
        cout << "Autocomplete suggestions for prefix \"" << prefix << "\":" << endl;
        autocompleteHelper(root, prefix);
    }

    void insert(string word)
    {
        root = insert(root, word);
    }

    Node *deleteWord(Node *root, const std::string &word)
    {
        if (root == nullptr)
        {
            return root;
        }

        // Standard BST delete
        if (word < root->word)
        {
            root->left = deleteWord(root->left, word);
        }
        else if (word > root->word)
        {
            root->right = deleteWord(root->right, word);
        }
        else
        {
            // Node with the word to be deleted is found

            if (root->count > 1)
            {
                // Decrease occurrence count if there are multiple instances of the word
                root->count--;
            }
            else
            {
                // Actual deletion of the node

                if (root->left == nullptr || root->right == nullptr)
                {
                    Node *temp = (root->left) ? root->left : root->right;

                    if (temp == nullptr)
                    {
                        temp = root;
                        root = nullptr;
                    }
                    else
                    {
                        *root = *temp;
                    }

                    delete temp;
                }
                else
                {
                    // Node with two children, find the inorder successor (smallest
                    // node in the right subtree)
                    Node *temp = findMinValueNode(root->right);

                    // Copy the inorder successor's data to this node
                    root->word = temp->word;
                    root->count = temp->count;

                    // Delete the inorder successor
                    root->right = deleteWord(root->right, temp->word);
                }
            }
        }

        if (root == nullptr)
        {
            return root;
        }

        // Update height of the current node
        root->height = 1 + std::max(height(root->left), height(root->right));

        // Rebalance the tree
        return balance(root);
    }

    Node *search(string word)
    {
        return searchWord(root, word);
    }

};
