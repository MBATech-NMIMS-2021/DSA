#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    Node *rightPointer = NULL;
    int data;
    Node *leftPointer = NULL;
};

class inorderTraversal
{
public:
    void traverse(Node *currentNode)
    {
        cout << endl
             << "Traversing...\n";
        if (currentNode == NULL)
        {
        }
        else
        {
            traverse(currentNode->leftPointer);
            cout << currentNode->data;
            traverse(currentNode->rightPointer);
        }
    }
};

class preorderTraversal{
public:
    void traverse(Node *currentNode)
    {
        cout << endl
             << "Traversing...\n";
        if (currentNode == NULL)
        {
        }
        else
        {
            cout << currentNode->data;
            traverse(currentNode->leftPointer);
            traverse(currentNode->rightPointer);
        }
    }
};
class postorderTraversal{
public:
    void traverse(Node *currentNode)
    {
        cout << endl
             << "Traversing...\n";
        if (currentNode == NULL)
        {
        }
        else
        {
            traverse(currentNode->leftPointer);
            traverse(currentNode->rightPointer);
            cout << currentNode->data<<endl;
        }
    }
};

int main(void)
{
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    // Creating a tree
    Node *rootNode = new Node;
    rootNode->data = 1;
    rootNode->rightPointer = new Node;
    rootNode->rightPointer->data = 3;
    rootNode->leftPointer = new Node;
    rootNode->leftPointer->data = 2;
    rootNode->leftPointer->leftPointer = new Node;
    rootNode->leftPointer->leftPointer->data = 4;
    rootNode->leftPointer->rightPointer = new Node;
    rootNode->leftPointer->rightPointer->data = 5;
    postorderTraversal a;
    a.traverse(rootNode);

    return 0;
}