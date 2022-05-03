// Program for bfsTraversal

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    Node *rightNode = NULL;
    int data;
    Node *leftNode = NULL;
    bool visited = false;
};

class Queue
{
private:
    vector<Node *> queueVector;
    int front = 0;
    int rear = -1;

public:
    bool enqueue(Node *enqueueNode)
    {
        if (enqueueNode == NULL)
        {
            return false;
        }
        queueVector.push_back(enqueueNode);
        rear++;
        return true;
    }
    void printQueue()
    {
        for (int i = front; i <= rear; i++)
        {
            // cout << "\nNext element: " << queueVector[i]->data << " visited: " << queueVector[i]->visited;
        }
        // int a;
        // cout << endl;
        // cin >> a;
        // cout << endl;
    }
    bool dequeue()
    {
        front++;
        return true;
    }
    Node *returnTopElement()
    {
        return queueVector[front];
    }
    vector<Node *> getPointerVector()
    {
        vector<Node *> vectorNodes;
        for (int i = front; i <= rear; i++)
        {
            vectorNodes.push_back(queueVector[i]);
        }
        return vectorNodes;
    }
    bool queueEmpty()
    {
        if (queueVector.size() == 0)
        {
            return true;
        }
        return false;
    }
    bool allNodesVisited()
    {
        for (int i = front; i <= rear; i++)
        {
            if (!queueVector[i]->visited)
            {
                return false;
            }
        }
        return true;
    }
    int size()
    {
        return queueVector.size();
    }
};

class bfsTraversal
{
private:
    Node *treeRootNode;
    Queue visitedNodes;

public:
    bfsTraversal(Node *rootNode)
    {
        treeRootNode = rootNode;
    }
    bool printNode(Node *node)
    {
        if (node != NULL)
        {
            cout << node->data;
            return true;
        }
        return false;
    }
    void unitTraversalProcess(Node *currentNode)
    {
        currentNode->visited = true;
        visitedNodes.enqueue(currentNode->leftNode);
        visitedNodes.enqueue(currentNode->rightNode);
        cout << "\nThe node having " << currentNode->data << " has been visited sir.";
        visitedNodes.enqueue(currentNode);
    }
    void startTraversalPlease()
    {
        if (visitedNodes.queueEmpty())
        {
            unitTraversalProcess(treeRootNode);
            visitedNodes.printQueue();
            startTraversalPlease();
        }
        else
        {
            vector<Node *> nodeList = visitedNodes.getPointerVector();
            while (!visitedNodes.allNodesVisited())
            {
                visitedNodes.printQueue();
                for (int i = 0; i < nodeList.size(); i++)
                {
                    if (!nodeList[i]->visited)
                    {
                        // cout << "\nSending " << nodeList[i]->data << " to single processor";
                        unitTraversalProcess(nodeList[i]);
                        break;
                    }
                }
                nodeList = visitedNodes.getPointerVector();
            }
        }
    }
};

int main(void)
{
    Node *rootNode = new Node;
    rootNode->data = 1;
    rootNode->leftNode = new Node;
    rootNode->leftNode->data = 2;
    rootNode->rightNode = new Node;
    rootNode->rightNode->data = 3;
    rootNode->rightNode->rightNode = new Node;
    rootNode->rightNode->leftNode = new Node;
    rootNode->rightNode->leftNode->data = 200;
    rootNode->rightNode->rightNode->data = 100;

    bfsTraversal a(rootNode);
    a.startTraversalPlease();
    return 0;
}