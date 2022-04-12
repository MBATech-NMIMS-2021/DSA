//$ Program to insert an element into the linked list
//* This is a program of insertion into the linked list with 100, 200, and 300 as the values of 3 nodes. Inserted element will have a value of 150

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
    //* Firstly creating a linked list of 3 elements...

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

    //* Now inserting an element in the 1st index... (value = 150)

    node midElement;
    midElement.value = 150;

    // Updating element1....

    element1.pointer = &midElement.value;

    // Updating the midElement pointer...

    midElement.pointer = &element2.value;

    return 0;
}