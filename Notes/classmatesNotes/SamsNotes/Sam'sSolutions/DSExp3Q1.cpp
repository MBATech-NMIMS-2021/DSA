#include <iostream>
using namespace std;

class Queue
{
public:
    int *queue;
    int rear = -1;
    int front = 0;
    int queueMaxSize = 0;
    // Constructor function to make a queue
    Queue(int size)
    {
        queueMaxSize = size;
        queue = new int[queueMaxSize];
        cout << "Queue created";
    }
    // Function for enqueueing
    void enqueue(int enqueueElement)
    {
        *(queue + (++rear)) = enqueueElement;
    }
    // Function for dequeueing
    void dequeue()
    {
        front++;
    }
    // Function to detect overflow
    bool checkOverflow()
    {
        if (rear == queueMaxSize - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Function to detect underflow
    bool checkUnderflow()
    {
        if (rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Utility function to print the queue
    void printQueue()
    {
        if (checkUnderflow())
        {
            cout << "Queue underflow case detected...";
        }
        else
        {
            cout << rear;
            for (int i = front; i < rear + 1; i++)
            {
                cout << "\nThe " << i << "th element of queue is " << *(queue + i);
            }
        }
    }
};

int main(void)
{
    Queue queue1(6);
    queue1.enqueue(7);
    queue1.enqueue(8);
    queue1.enqueue(9);
    queue1.dequeue();
    queue1.printQueue();
    return 0;
}