#include <iostream>
#include <vector>
#include <string>

using namespace std;

//* Class to create nodes

class Node
{
public:
    // Creating components of node

    Node *leftNode = NULL;
    int data;
    // This is a component in order to keep record whether the data in the node is a garbage value, or was manually entered
    bool dataEntered = false;
    Node *rightNode = NULL;

    // Creating methods to CRUD Node

    void createLeftNode()
    {
        (*this).leftNode = new Node;
        // Setting the right node pointer of the new node to the current node
        (*(*this).leftNode).rightNode = this;
    }
    void createRightNode()
    {
        this->rightNode = new Node;
        // Setting the left node of the right node to be the current node
        (*(*this).rightNode).leftNode = this;
    }
    /*
    This is a function in order to put the data in current node
    Return values:

    - true: If the data didn't exist in the node, and has now been stored in that node
    - false: If the data already existed in the node, hence updating the previously entered data has been denied

    */
    bool enterData(int data)
    {
        if (dataEntered)
        {
            return false;
        }
        else
        {
            data = data;
            dataEntered = true;
            return true;
        }
    }
};

//* Class to create binary tree, and perform CRUD operations on it

class binarySearchTree
{
private:
    Node *rootNode = new Node;
    Node *currentNode = rootNode;

public:
    void insertElement(int element)
    {
        // If the current node's data is empty, then insert the element here
        if ((*currentNode).enterData(element))
        {
            cout << "\nElement inserted at the data portion of node at address " << currentNode;
        }
        else
        {
            // If was already there in the node, then update the current node, and perform recursion
            if ((*currentNode).data > element)
            {
                // Creating a left node
                (*currentNode).createLeftNode();
                // Let current node be the left node
                currentNode = (*currentNode).leftNode;
                insertElement(element);
            }
            else
            {
                // Create a right node
                (*currentNode).createRightNode();
                // Let the current node be the right node
                currentNode = (*currentNode).rightNode;
                insertElement(element);
            }
        }
    }
};

int main(void)
{
    binarySearchTree a;
    a.insertElement(2);
    a.insertElement(3);
    return 0;
}