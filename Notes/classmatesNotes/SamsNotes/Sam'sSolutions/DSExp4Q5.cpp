//$ Program to traverse through the linked list

// node structure
struct node
{
    int value;
    int *pointer;
};

#include <iostream>
#include <vector>

using namespace std;
void recursiveTraversal(node )
{
    // Breakpoint
    if (pointer == NULL)
    {
        cout << "Exiting from the program...";
    };
    cout << "\nThe element is = " << *pointer.value;
    recursiveTraversal(*pointer.pointer);
};
int main(void)
{

    //* Creating a linkedlist

    node element1;
    element1.value = 100;
    int *head = &element1.value;

    node element2;
    element2.value = 200;

    element1.pointer = &element2.value;

    node element3;
    element3.value = 300;

    element2.pointer = &element3.value;

    element3.pointer = NULL;

    // Linked list created

    // Traversing through the linked list...
    // Using recursion for traversal...

    

    return 0;
}