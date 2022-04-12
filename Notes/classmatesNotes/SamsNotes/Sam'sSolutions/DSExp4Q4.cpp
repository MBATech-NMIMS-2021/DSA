//$ Program to delete a node...
//* In this code, I'll delete the element2 node

// node structure
struct node
{
    int value;
    int *pointer;
};

#include <iostream>
#include <vector>

using namespace std;

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

    // Deleting the element2 node

    // Updating element1 pointer...

    element1.pointer = &element3.value;

    return 0;
}