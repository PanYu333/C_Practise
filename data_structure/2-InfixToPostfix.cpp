/**
 * Infix to postfix conversion in C++ 
 * Input Postfix expression must be in a desired format. 
 * Only '+'  ,  '-'  , '*', '/' and '^' (for exponentiation)  operators are expected.
 * 
 * Example:
 *      input1: 3 + 5 * 12
 *      output: 3 5 12 * +
 * 
 *      input2: 3 * 5 -(12 ^3^2 * 3 + 2)-3
 *      output: 3 5 * 12 3 2 ^ ^ 3 * 2 + - 3 -
*/

# include <iostream>
# include <string>
# include <stack>

using namespace std;

char IsOperator(char c);
char IsNumber(char c);
char HasHigherPrecedence(char op1, char op2);
string InfixToPostfix(string expression);

int main()
{
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    string result = InfixToPostfix(expression);
    cout << "Result : " << result << endl;
    return 0;
}

/*Function to evaluate infix expression and return postfix expression.*/
string InfixToPostfix(string expression)
{
    stack<char> S;

    string postfix = "";    // Initialize postfix as empty string.
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;

        else if (IsOperator(expression[i]))
        {
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
            {
                postfix += S.top();
                postfix += ' ';
                S.pop();
            }
            S.push(expression[i]);
        }

        else if (IsNumber(expression[i]))
        {
            // Continuous numbers need to be continuously recorded
            while (i < expression.length() && IsNumber(expression[i]))
            {
                postfix += expression[i];
                i++;
            }
            i--;
            postfix += ' ';
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while (S.top() != '(')
            {
                postfix += S.top();
                postfix += ' ';
                S.pop();
            }
            S.pop();
        }
    }

    // At the end of expression, attain residual operators from the stack
    while (!S.empty())
    {
        postfix += S.top();
        postfix += ' ';
        S.pop();
    }
    return postfix;
}

char IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

char IsNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

char IsRightAssociative(char c)
{
    if (c == '^')
        return true;
    return false;
}

int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
        case '+':
        case '-': weight = 1; break;
        case '*':
        case '/': weight = 2; break;
        case '^': weight = 3; break;
        default:
            printf("operator error!");
            break;
    }
    return weight;
}

/*op1 is the top of stack, op2 is currect op.*/
char HasHigherPrecedence(char op1, char op2)
{
    int op1weight = GetOperatorWeight(op1);
    int op2weight = GetOperatorWeight(op2);

    if (op1weight == op2weight)
    {
        // if operators have equal precedence, return true if they are left associative.
        // return false if they are right associate.
        // if operator is left-associative, left one should be given priority.
        if (IsRightAssociative(op1))
            return false;
        else
            return true;
    }

    return op1weight > op2weight ? true : false;
}