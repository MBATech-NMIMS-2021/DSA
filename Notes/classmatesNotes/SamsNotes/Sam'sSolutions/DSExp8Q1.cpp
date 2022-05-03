// Program for BFS
// Using stacks

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Queue
{
private:
    vector<int> queueVector;
    int front = 0, rear = -1;

public:
    bool enqueue(int element)
    {
        queueVector.push_back(element);
        rear++;
        return true;
    }
    bool dequeue()
    {
        if (front > rear)
        {
            cout << "\nQueue underflow...";
            return false;
        }
        front++;
        return true;
    }
    int getFrontElement()
    {
        return queueVector[front];
    }
};

class Node
{
public:
    Node *rightPointer;
    int data;
    Node *leftPointer;
};

class bfsTraversal
{
private:
    Node *rootNode;
    Queue traversalQueue;

public:
    bfsTraversal(Node *nodeAddress)
    {
        rootNode = nodeAddress;
    }
    bool traverseBro(Node *currentNode)
    {
        // Terminating condition
        if(currentNode->leftPointer == NULL && currentNode->righ)
    }
};

int main(void)
{

    return 0;
}