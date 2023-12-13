#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool chkOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


string decryptPassword(string encryptedPassword)
{
    queue<char> alphabetQueue;
    queue<char> numberQueue;
    queue<char> arithmeticQueue;

    for (char c : encryptedPassword)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  // yani alphabet ha
        {
            alphabetQueue.push(c);
        }
        else if (c >= '0' && c <= '9') // chk for number
        {
            numberQueue.push(c);
        }
        else if (chkOperator(c))
        {
            arithmeticQueue.push(c);
        }
    }

    while (!arithmeticQueue.empty())
    {
        numberQueue.push(arithmeticQueue.front());
        arithmeticQueue.pop();
    }

    string decryptedPassword;

    while (!alphabetQueue.empty())
    {
        decryptedPassword += alphabetQueue.front();
        alphabetQueue.pop();
    }

    while (!numberQueue.empty())
    {
        decryptedPassword += numberQueue.front();
        numberQueue.pop();
    }

    while (!arithmeticQueue.empty())
    {
        decryptedPassword += arithmeticQueue.front();
        arithmeticQueue.pop();
    }

    return decryptedPassword;
}

int main()
{
    string encryptedPassword;
    cout << "Enter the encrypted password: ";
    cin >> encryptedPassword;

    string decryptedPassword = decryptPassword(encryptedPassword);

    cout << "Decrypted Password: " << decryptedPassword << endl;

    return 0;
}
