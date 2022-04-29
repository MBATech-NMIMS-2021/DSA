// BFS traversal

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node{
    public:
        Node *rightNode;
        int data;
        Node *leftNode;
};

class queue{
    private:
        unsigned int front = 0;
        unsigned int rear = -1;
        vector<int> queueVector;

    public:
        bool enqueue(int data){
            queueVector.push_back(data);
            rear++;
            return true;
        }
        int dequeue(){
            return queueVector[front ++];
        }
        bool traverse(){
            for (int iterator = front; iterator <= rear; iterator ++){
                cout << "\nThe next element is " << queueVector[iterator] << endl;
            }
            return true;
        }
};

class nodeQueue{
    private:
        unsigned int front = 0;
        unsigned int rear = -1;
        vector<Node *> queueVector;

    public:
        bool enqueue(Node *data){
            queueVector.push_back(data);
            rear++;
            return true;
        }
        Node *dequeue(){
            if(rear == -1){
                return NULL;
            }
            return queueVector[front ++];
        }
        bool traverse(){
            for (int iterator = front; iterator <= rear; iterator ++){
                cout << "\nThe next element is " << queueVector[iterator] << endl;
            }
            return true;
        }
};

class bfsTraversal{
    private:
        Node *rootNode;
        nodeQueue bfsAddressQueue;
        queue bfsDataQueue;

    public:
        bfsTraversal(Node *treeRootNode){
            rootNode = treeRootNode;
        }
        void traverse(Node *currentNode){
            bfsDataQueue.enqueue(bfsAddressQueue.dequeue()->data);
            bfsAddressQueue.enqueue(currentNode);
            bfsAddressQueue.enqueue(currentNode->leftNode);
            bfsAddressQueue.enqueue(currentNode->rightNode);
        }
};

int main(void){

    queue a;
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    cout << a.dequeue();
    a.traverse();

    return 0;
}