//$ Program to create a linked list...
//* This linked list will basically have 3 elements, values would be 100, 200, 300 resp. All elements will be harcoded.

#include<iostream>
#include<string>

using namespace std;

//* Structure for the node
struct node{
    int data;
    node *pointer;
};

int main(void){

    // Using dynamic allocation to create elements...
    //* Creating element1
    node *element1;
    element1 = new node();

    (*element1).data = 10;

    //* Creating head pointer
    node *head = element1;

    //* Creating element2
    node *element2;
    element2 = new node();

    (*element2).data = 20;

    // Setting the pointer of element1
    (*element1).pointer = element2;

    //* Creating element3
    node *element3;
    element3 = new node();

    (*element3).data = 30;

    // Setting the pointer of element2
    (*element2).pointer = element3;

    // Setting the pointer of element3
    (*element3).pointer = NULL;

    // Just an example of how to access the pointer, and node's data
    cout << (*(*element1).pointer).data;

    return 0;
}