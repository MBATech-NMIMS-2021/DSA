#include <iostream>
#include <vector>
#include <string>

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

    char optionSelected;
    int callCounter = 0;

    while (true)
    {

        cout << "Select what you wanna do?\n1) Get a call\n2) Answer a call\n";
        cin >> optionSelected;

        Queue callQueues(5);

        if (optionSelected == '1')
        {
            callQueues.enqueue(callCounter++);
        } else if (optionSelected == '2'){
            callQueues.dequeue();
        }
    }

    return 0;
}