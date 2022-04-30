//* This is a program to convert a given infix expression to postfix

/*
Here's the rules for the following conversion:

1) Operands directly go to the postfix expression
2) First operator will move to the stack directly
3) If the precedence of next operator is less, then pop out an element from the stack, and push the new incoming operator
4) If the precedence of the incoming operator is greater, then directly push it into the stack
5) If we find an opening parenthesis [ ( ], then push it into the stack temporarily
6) Now keep processing the further characters until we find the closing parenthesis [ ) ]
7) Now keep popping the operators from the stack until we find the opening parenthesis.
8) Don't include the parenthesis in the postfix expression.
9) If the incoming operator has the same precedence to the last element of the stack, then process operators on the basis of their associativity
10) Left to right associativity: Pop out from the stack
11) Right to left associativity: Push into the stack

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string operators = "+-*/^%()";

// List of left to right (LR) associative operators
vector<vector<char>> LR = {{'*', '/', '%'}, {'+', '-'}};

// Making vectors of precedence order of operators
// Getting the precedence order from here: https://doc.bccnsoft.com/docs/cppreference_en/operator_precedence.html
// Remember that the operator with higher precedence is given less precedence value
vector<char> operatorPrecedenceOrder = {'*', '/', '+', '-', '%', '^', '(', ')'};
vector<int> operatorPrecedenceValue = {5, 5, 6, 6, 5, 3, 7, 7};
// Function to get the precedence order of the operator
int getPrecedenceValue(char operators)
{
    for (int i = 0; i < operatorPrecedenceOrder.size(); i++)
    {
        if (operatorPrecedenceOrder[i] == operators)
        {
            return operatorPrecedenceValue[i];
        }
    }
    return -1;
}

class Stack
{
private:
    vector<char> stack;

public:
    // To push an element into the stack
    void push(char pushCharacter)
    {
        cout << "\nPushing into the stack";
        stack.push_back(pushCharacter);
    }
    // To pop out an element from the stack
    // I've disabled the popping out of brackets for some reasons, forcePop() is an alternative function to pop out the brackets too
    char pop()
    {
        cout << "Popping out of stack";
        char rearElement = stack[stack.size() - 1];
        if (rearElement == '(' || rearElement == ')')
        {
            cout << "Refused to pop out the element because of bracket.";
            return ' ';
        }
        stack.pop_back();
        return rearElement;
    }
    // Enables the popping out of brackets too
    void forcePop()
    {
        stack.pop_back();
    }
    // To get the last element of the stack
    char lastElement()
    {
        return stack[stack.size() - 1];
    }
    // To check whether the stack is empty or not
    bool isEmpty()
    {
        if (stack.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // To print the stack
    void printStack()
    {
        if (isEmpty())
        {
            cout << "= ) STACK EMPTY";
        }
        else
        {
            for (int i = 0; i < stack.size(); i++)
            {
                cout << "\n= ) The " << i << "th element of the stack is " << stack[i];
            }
            cout << endl;
        }
    }
    // To append the stack elements into the postfix expression to generate the final postfix answer
    string generateFinalPostfix(string postfixExpression)
    {
        for (int i = stack.size() - 1; i >= 0; i--)
        {
            postfixExpression.push_back(stack[i]);
        }
        return postfixExpression;
    }
};

class Postfix
{
private:
    string privateInfixExpression;
    string postfixExpression;
    Stack stack;

public:
    // Constructor function to get the postfix expression
    Postfix(string infixExpression)
    {
        privateInfixExpression = infixExpression;
        cout << "Expression got is " << privateInfixExpression << " of length " << privateInfixExpression.size() << endl;
        // Igniting the recursive analyzeCharacters function
        analyzeCharacters(privateInfixExpression[0], 0);
    }
    // A utility function to check the presence of a character in a string
    // Returns true if the element exists in the string, else false
    bool elementExists(string sampleString, char searchCharacter)
    {
        for (int i = 0; i < sampleString.size(); i++)
        {
            if (sampleString[i] == searchCharacter)
            {
                return true;
            }
        }
        return false;
    }
    // Recursive function to analyze the characters of infix expression
    bool analyzeCharacters(char analyzeCharacter, int analyzeCharacterIndex)
    {
        // Terminating condition for this recursive function
        if (analyzeCharacterIndex == privateInfixExpression.size())
        {
            cout << "\nTerminating the recursive function\n";
            cout << "Postfix expression generated is: " << stack.generateFinalPostfix(postfixExpression);
            return true;
        }
        cout << "\nAnalyzing the character " << analyzeCharacter << endl;
        cout << "Current postfix exp: " << postfixExpression << endl;
        stack.printStack();
        // Ignoring certain characters like space in the infix expression
        if (analyzeCharacter == ' ')
        {
            cout << "\nIgnoring this character";
            cout << "\n-----------------------------------------------------";
            return analyzeCharacters(privateInfixExpression[analyzeCharacterIndex + 1], analyzeCharacterIndex + 1);
        }
        // If the character is not an operator, then directly push it to postfix expression
        if (!elementExists(operators, analyzeCharacter))
        {
            cout << "This character is not an operator";
            postfixExpression.push_back(analyzeCharacter);
        }
        else
        {
            // If the stack is empty, the directly push the incoming operator into the stack, no need to see the precedence or associativity
            if (stack.isEmpty())
            {
                stack.push(analyzeCharacter);
            }
            // Else if the incoming operator is of higher operator, then push the operator to the stack
            else if (checkPrecedence(analyzeCharacter) == "High")
            {
                cout << "This element has status "
                     << "High";
                stack.push(analyzeCharacter);
            }
            // Else if the precedence of the incoming operator is less, then pop out an element from the stack, push it into the postfix expression, and push the incoming operator into the stack
            else if (checkPrecedence(analyzeCharacter) == "Low")
            {
                cout << "\nThis element has status Low";
                char rearElement = stack.pop();
                postfixExpression.push_back(rearElement);
                stack.push(analyzeCharacter);
            }
            else if (checkPrecedence(analyzeCharacter) == "Same")
            {
                cout << "This element has status same";
                if (getAssociativity(analyzeCharacter) == "LR")
                {
                    char rearElement = stack.pop();
                    cout << "Working: " << analyzeCharacter;
                    postfixExpression.push_back(rearElement);
                    stack.push(analyzeCharacter);
                }
                else
                {
                    stack.push(analyzeCharacter);
                }
            }
            /*
            Here are the steps that should be taken in order to process the contents inside the bracket:

            - If "(" is found, directly push it to the stack
            - Very less precedence value is given to "(" and ")", so the next operator will obviously get pushed into the stack, without any pop outs.
            - Until we don't find ")", keep analyzing the characters
            - If we find ")", then starting popping the elements of the stack until we don't find "("
            - The rear element in the stack now will be "(", so pop out an element from this stack so we can get rid of "("

            */
            else if (analyzeCharacter == '(')
            {
                stack.push('(');
            }
            else if (analyzeCharacter == ')')
            {
                // Pop from the stack until you dont find "("
                while (stack.lastElement() != '(')
                {
                    postfixExpression.push_back(stack.pop());
                }
                // Pop the "(" also...
                stack.forcePop();
            }
        }
        cout << "\n------------------------------------------------------------";
        // Continuing recursion if the next character exists in the privateInfixExpression
        return analyzeCharacters(privateInfixExpression[analyzeCharacterIndex + 1], analyzeCharacterIndex + 1);
    }
    /*

    Utility function to check precedence of the incoming character with the last character of the stack

    Return values:

    "High": If precedence of the incoming operator is higher
    "Low": If the precedence of the incoming operator is lower
    "Same": If the precedence of the incoming operator is same
    "Bracket": If the incoming operator is actually a bracket

    */
    string checkPrecedence(char incomingOperator)
    {
        if (incomingOperator == '(' || incomingOperator == ')')
        {
            return "Bracket";
        }
        if (getPrecedenceValue(stack.lastElement()) < getPrecedenceValue(incomingOperator))
        {
            return "Low";
        }
        else if (getPrecedenceValue(stack.lastElement()) > getPrecedenceValue(incomingOperator))
        {
            return "High";
        }
        else if (getPrecedenceValue(stack.lastElement()) == getPrecedenceValue(incomingOperator))
        {
            return "Same";
        }
        else
        {
            cout << "\nCritical case detected sir...";
        }
    }
    // Utility function to get the associativity order
    /*
    Return values:

    "LR": Left to right
    "RL": Right to left

    */
    string getAssociativity(char operators)
    {
        for (int i = 0; i < LR.size(); i++)
        {
            for (int j = 0; j < LR[i].size(); j++)
            {
                if (operators == LR[i][j])
                {
                    return "LR";
                }
            }
        }
        return "RL";
    }
};

int main(void)
{
    string inputInfix;
    cout << "Enter the infix string: ";
    getline(cin, inputInfix);
    Postfix problem1(inputInfix);

    return 0;
}