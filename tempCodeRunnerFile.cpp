//* Creating binary search tree

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
private:
    bool dataManuallyEntered = false;

public:
    Node *leftSubTree = NULL;
    Node *rightSubTree = NULL;
    int data;
    void insertRootElement(int rootNodeData)
    {
        if (this->dataManuallyEntered == false)
        {
            cout << "\nElement " << rootNodeData << " entered into the bst, at address " << this << "\n";
            this->data = rootNodeData;
        }
        else
        {
            cout << "\nDenied pushing of " << rootNodeData << " at " << this << " because this has already been filled.\n";
        }
        this->dataManuallyEntered = true;
    }
    void createRightSubTree()
    {
        if (this->rightSubTree == NULL)
        {
            this->rightSubTree = new Node;
            cout << "\nCreated a new right sub node, which has an address " << this->rightSubTree << "\n";
        }
        else
        {
            cout << "\nDenied to create a new node at right, because it has already been created.\n";
        }
    }
    void createLeftSubTree()
    {
        if (this->leftSubTree == NULL)
        {
            this->leftSubTree = new Node;
            cout << "\nCreated a new left sub node, which has an address " << this->leftSubTree << "\n";
        }
        else
        {
            cout << "\nDenied to create a new node at left, because it has already been created.\n";
        }
    }
    void getNodeDesc()
    {
        cout << "\n\nHere's the description of this node: \nMemory address: " << this << "\nRoot element manually entered: " << this->dataManuallyEntered << "\nLeft node pointer: " << this->leftSubTree << "\nRight node pointer: " << this->rightSubTree << "\n\n";
    }
    bool dataEntered()
    {
        return this->dataManuallyEntered;
    }
};

class binarySearchTree
{
private:
    Node *currentElement = mainRootElement;

public:
    Node *mainRootElement = new Node;
    bool insertElement(int element)
    {
        cout << "INserting...\n";
        // If the data at the current node has not been set, then insert the data over here
        if (currentElement->dataEntered() == false)
        {
            currentElement->insertRootElement(element);
            return true;
        }
        // If the data has been set
        else
        {
            // If the element is smaller than data at current node
            if (currentElement->data > element)
            {
                // Insertion has to be obviously at the left position
                // createLeftSubTree method only creates if the sub tree doesn't exist
                currentElement->createLeftSubTree();
                currentElement = currentElement->leftSubTree;
                return insertElement(element);
            }
            else
            {
                // Insertion at the right position
                currentElement->createRightSubTree();
                currentElement = currentElement->rightSubTree;
                return insertElement(element);
            }
        }
    }
};

// class bstTraversal
// {
// private:
//     Node *rootElement;

// public:
//     bstTraversal(Node *mainRootElement)
//     {
//         rootElement = mainRootElement;
//     }
//     void inorderTraversal(Node *operatingNode)
//     {
//         cout << "Traversing...";
//         // Terminating condition
//         if (operatingNode == NULL)
//         {
//         }
//         else
//         {
//             inorderTraversal(operatingNode->leftSubTree);
//             cout << operatingNode->data;
//             inorderTraversal(operatingNode->rightSubTree);
//         }
//     }
// };

int main(void)
{
    binarySearchTree a;
    a.insertElement(2);
    a.insertElement(1);
    a.insertElement(3);
    a.insertElement(5);
    a.insertElement(4);
    
    return 0;
}