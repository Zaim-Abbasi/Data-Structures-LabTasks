#pragma once
#include<iostream>
#include <stack>
using namespace std;
bool IsBalanced(string s)
{
    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        if(ch == ')' || ch == '}' || ch == ']')
        {
            if(st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
}