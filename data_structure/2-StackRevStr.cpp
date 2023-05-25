/**
 * This is an example of using stack to reverse a string.
 * You can also use stacks previously written in C language
 * to achieve inversion.
*/
#include <iostream>
#include<string>
#include <stack>
using namespace std;

void Reverse(string &C, int len);
int main()
{
    string C;
    cout << "Enter a string: " << endl;
    getline(cin, C);
    Reverse(C, C.length());
    cout << "After reverse: " << C << endl;
    return 0;
}

/*Reverse a string*/
void Reverse(string &C, int len)
{
    int i;
    stack<char> S;      // Initialize a stack.
    for (i = 0; i < len; i++)
    {
        S.push(C[i]);   // Data Pushing.
    }
    for (i = 0; i < len; i++)
    {
        C[i] = S.top(); // Obtain data from the stack top.
        S.pop();        // Stack poping.
    }
}