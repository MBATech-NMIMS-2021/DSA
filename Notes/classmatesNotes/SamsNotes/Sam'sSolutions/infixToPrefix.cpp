#include<iostream>
#include<vector>
#include<string>

using namespace std;

const string operators = "+-/%^";

bool detectPresence(char character, string expression){
    for (int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == character){
            return true;
        }
        return false;
    }
}

class Stack{
    
};

class infixToPrefix{
    string prefix;
    string stack;

    infixToPrefix(string expression){
        // Iterating through all the characters
        for (int i = 0; i < expression.size(); i++)
        {
            if(!detectPresence(expression[i], expression)){
                prefix.push_back(expression[i]);
            }
        }
        
    }
};

int main(void){

    string expression;

    cout << "Enter the expression: ";
    cin >> expression;



    return 0;
}