//$ Modify the info of a node (position to be specified by the user)
//* In this code, I'll edit the element2 value with 150

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

    //* Editing the element2 value...

    // Working on element2 value

    element2.value = 150;

    // Updating the element1 pointer...

    element1.pointer = &element2.value;

    return 0;
}