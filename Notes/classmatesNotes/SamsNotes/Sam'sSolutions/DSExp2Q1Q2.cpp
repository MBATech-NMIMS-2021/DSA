// Showing the implementation of stack in array

#include <iostream>
using namespace std;

// Creating a stack class to put all stack operations into it
class Stack
{
public:
    int rear = -1;
    // Pointer function to stack, in order to apply dynamic allocation
    int *stack;
    int stackMaxSize;

    // Function to push an element into the stack
    void push()
    {
        int pushElement;
        cout << "Enter the element ";
        cin >> pushElement;
        // Checking for stackoverflow case
        if (checkStackOverflow())
        {
            cout << "Stackoverflow case detected. Aborting the push";
        }
        else
        {
            stack[++rear] = pushElement;
        }
    }

    // Function to print the reverse of the stack
    void printReverseStack()
    {
        for (int i = rear; i >= 0; i--)
        {
            cout << "The " << i << "th element is " << stack[i] << "\n";
        }
    }

    // Function to pop out an element from the stack
    void deleteElement()
    {
        // Checking for the stack underflow case
        if (checkStackUnderflow())
        {
            cout << "Stack underflow case detected. Aborting the deletion";
        }
        else
        {
            rear--;
        }
    }

    // Constructor function to create a stack of specified size, using dynamic allocation
    Stack(int stackSize)
    {
        stack = new int[stackSize];
        cout << "Created a stack\n";
        stackMaxSize = stackSize;
    }

    // Function to return true in the case of stack underflow, else false
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

    // Function to return true in the case of stack overflow, else false
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

    // Function to print the stack
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

    // Function to delete an element from a specific index
    bool deleteFromSpecificIndex(int index)
    {
        // Implementing dynamic allocation
        int *temporaryArray = new int[stackMaxSize-index];
        // Iterating from last elements, and storing them in an array
        int counter = 0;
        for (int i = index + 1; i < rear + 1; i ++){
            *(temporaryArray + counter) = stack[i];
            counter++;
        }
        // Removing that element by simply decrementing the rear value, and pushing all element of temporaryArray into the stack again
        rear--;
        for (int i = 0; i < counter; i++){
            stack[index + i] = *(temporaryArray + i);
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
    Stack1.push();
    Stack1.deleteFromSpecificIndex(2);
    Stack1.printStack();
    return 1;
}