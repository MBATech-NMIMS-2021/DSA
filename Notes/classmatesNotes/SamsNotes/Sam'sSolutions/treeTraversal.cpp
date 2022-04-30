#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    bool enterData(int nodeData)
    {
        if (dataEntered)
        {
            return false;
        }
        else
        {
            data = nodeData;
            dataEntered = true;
            return true;
        }
    }
};

//* Class to create binary tree, and perform CRUD operations on it

class binarySearchTree
{
private:
public:
    Node *rootNode = new Node;
    Node *currentNode = rootNode;
    void insertElement(int element)
    {
        cout << "\nInserting element...";
        // If the current node's data is empty, then insert the element here
        if ((*currentNode).enterData(element))
        {
            cout << "\nElement inserted at the data portion of node at address " << currentNode;
        }
        else
        {
            if (currentNode->dataEntered)
            {
                // If was already there in the node, then update the current node, and perform recursion
                if ((*currentNode).data > element)
                {
                    // Creating a left node if it does not exists
                    if ((*currentNode).leftNode == NULL)
                    {
                        (*currentNode).createLeftNode();
                    }
                    // Let current node be the left node
                    currentNode = (*currentNode).leftNode;
                    insertElement(element);
                }
                else
                {
                    // Create a right node if it does not exists
                    if ((*currentNode).rightNode == NULL)
                    {
                        (*currentNode).createRightNode();
                    }
                    // Let the current node be the right node
                    currentNode = (*currentNode).rightNode;
                    insertElement(element);
                }
            } else {
                cout << "\nDANGEROUS CASE DETECTED";
            }
        }
    }
};

class inorderTraversal
{
private:
    Node *rootNode;
    Node *currentElement;

public:
    inorderTraversal(binarySearchTree tree)
    {
        rootNode = tree.rootNode;
    }
    bool performTraversal(Node *currentElement)
    {
        cout << "\nPerforming traversal. Currently at " << currentElement << " where the data is " << currentElement->data;
        // Breaking condition
        if (currentElement == NULL)
        {
            cout << "\nThe data at this location is " << currentElement->data;
            return false;
        }
        // Recursively performing the traversal
        performTraversal(currentElement->leftNode);
        cout << currentElement->data;
        performTraversal(currentElement->rightNode);
    }
};

int main(void)
{
    binarySearchTree a;
    a.insertElement(10);
    a.insertElement(12);
    a.insertElement(25);
    a.insertElement(30);
    a.insertElement(15);
    a.insertElement(36);
    inorderTraversal b(a);
    b.performTraversal(a.rootNode);
    return 0;
}