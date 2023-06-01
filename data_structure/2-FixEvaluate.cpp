/**
 * Evaluation Of "postfix expression" or "postfix expression" in C++ 
 * Input Postfix or Prefix expression must be in a desired format. 
 * Operands must be integers and there should be space in between two operands.
 * Only '+'  ,  '-'  , '*' and '/'  operators are expected. 
 *
 * Example: 
 *  Postfix:
 *      input: 2 3 * 4 6 *+ 2-  
 *      output: 28
 * 
 *  Prefix:
 *      input: * + 2 4 - 5 3
 *      output: 12
*/

#include <iostream>
#include<string>
#include <stack>

using namespace std;

char IsOperator(char c);
char IsNumber(char c);
int PerformOperator(char c, int a, int b);
int EvaluatePostfix(string expression);
int EvaluatePrefix(string expression);

int main()
{
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);
    int result = EvaluatePostfix(expression);   // Taking Postfix Expressions as an Example
    cout << "result = " << result << endl;
    return 0;
}

/*Calculate the value of a Postfix expression*/
int EvaluatePostfix(string expression)
{
    stack<int> S;

    for (int i = 0; i < expression.length(); i++)
    {
        // Space or comma as separator
        if (expression[i] == ' ' || expression[i] == ',')   
            continue;

        // Ensure at least there are two numbers that can be manipulated
        else if (IsOperator(expression[i]) && S.size()>1)
        {
            int op2 = S.top(); S.pop();     // Top is second number
            int op1 = S.top(); S.pop();     // Then is first number
            int temp = PerformOperator(expression[i], op1, op2);
            S.push(temp);
        }
        else if (IsNumber(expression[i]))
        {
            int temp = 0;

            // obtain a multi digit number
            while (i < expression.length() && IsNumber(expression[i]))
            {
                temp = temp * 10 + expression[i] - '0';
                i++;
            }
            i--;    // Fallback redundant addition
            S.push(temp);
        }
    }
    return S.top();
}

/*verify a character is operator symbol or not.*/
char IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

/*perform an operation and return output.*/
int PerformOperator(char c, int a, int b)
{
    if (c == '+')      return a + b;
    else if (c == '-') return a - b;
    else if (c == '*') return a * b;
    else if (c == '/') return a / b;
    else cout << "Unexpected Error. \n";
    return -1;
}

char IsNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}


/*Calculate the value of a Prefix expression*/
int EvaluatePrefix(string expression)
{
    stack<int> S;

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;

        else if (IsOperator(expression[i]))
        {
            int op1 = S.top(); S.pop();
            int op2 = S.top(); S.pop();
            int temp = PerformOperator(expression[i], op1, op2);
            S.push(temp);
        }
        else if (IsNumber(expression[i]))
        {
            int temp = 0;
            while (i >= 0 && IsNumber(expression[i]))
            {
                temp = temp * 10 + expression[i] - '0';
                i--;
            }
            i++;    // Fallback redundant addition
            S.push(temp);
        }
    }
    return S.top();
}
