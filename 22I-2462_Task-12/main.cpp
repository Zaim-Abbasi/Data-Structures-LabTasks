#include <iostream>
#include "avl.h"

int main()
{
    AVLTree avlTree;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Load dictionary file\n";
        cout << "2. Autocomplete suggestions\n";
        cout << "3. Delete word\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            avlTree.LoadDictionary();
            cout << "Dictionary loaded successfully.\n";
            break;
        }
        case 2:
        {
            avlTree.autocomplete();
            break;
        }
        case 3:
        {
            string word;
            cout << "Enter the word to delete: ";
            cin >> word;
            avlTree.deleteWord(avlTree.root, word);
            cout << "Word deleted successfully.\n";
            break;
        }
        case 4:
        {
            cout << "Exiting program.\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}