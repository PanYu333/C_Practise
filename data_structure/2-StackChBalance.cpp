/**
 * C++ Program to check for balanced parentheses in an expression using stack.
 * Given an expression as string comprising of opening and closing characters
 * of parentheses - (), curly braces - {} and square brackets - [], we need to 
 * check whether symbols are balanced or not. 
*/
#include <iostream>
#include<string>
#include <stack>
using namespace std;

bool ArePair(char left, char right);
bool CheckBalancedParentheses(const string str);

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if (CheckBalancedParentheses(str))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}

/*check whether two charactes are a pair*/
bool ArePair(char left, char right)
{
    if (left == '(' && right == ')')
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}

bool CheckBalancedParentheses(const string str)
{
    stack<char> S;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            S.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (S.empty() || !ArePair(S.top(), str[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}
