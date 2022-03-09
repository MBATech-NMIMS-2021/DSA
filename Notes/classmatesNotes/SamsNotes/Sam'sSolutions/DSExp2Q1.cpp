// Showing the implementation of stack in array

#include <iostream>
using namespace std;
class Stack
{
public:
    int rear = -1;
    int front = 0;
    int *stack;
    int stackMaxSize;

    void push()
    {
        int pushElement;
        cout << "Enter the element ";
        cin >> pushElement;
        if (checkStackOverflow())
        {
            cout << "Stackoverflow case detected. Aborting the push";
        }
        else
        {
            stack[++rear] = pushElement;
        }
    }
    void printReverseStack()
    {
        for (int i = rear; i >= 0; i--)
        {
            cout << "The " << i << "th element is " << stack[i] << "\n";
        }
    }
    void deleteElement()
    {
        if (checkStackUnderflow())
        {
            cout << "Stack underflow case detected. Aborting the deletion";
        }
        else
        {
            rear--;
        }
    }
    Stack(int stackSize)
    {
        stack = new int[stackSize];
        cout << "Created a stack\n";
        stackMaxSize = stackSize;
    }
    bool checkStackUnderflow()
    {
        if (rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkStackOverflow()
    {
        if (rear == stackMaxSize - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool printStack()
    {
        if (checkStackUnderflow())
        {
            cout << "The stack is empty";
            return false;
        }
        for (int i = 0; i < rear + 1; i++)
        {
            cout << "The " << i << "th element is " << stack[i] << "\n";
        }
        return true;
    }
    void shiftElementbackwards(int index)
    {
        *(stack + index) = *(stack + index + 1);
    }
    bool deleteFromSpecificIndex(int index)
    {
        // Breaking condition
        if (index == rear - 1)
        {
            return true;
        }
        else
        {
            shiftElementbackwards(index);
            deleteFromSpecificIndex(index + 1);
        }
    }
};

int main(void)
{
    Stack Stack1(6);
    Stack1.push();
    Stack1.push();
    Stack1.push();
    Stack1.push();
    Stack1.push();
    Stack1.deleteFromSpecificIndex(2);
    Stack1.printStack();
    // Stack1.printStack();
    // Stack1.deleteElement();
    // Stack1.printStack();
}