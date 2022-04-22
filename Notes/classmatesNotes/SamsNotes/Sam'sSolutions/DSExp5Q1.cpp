// Write a program in C/C++ to insert a node at the beginning of a doubly linked list. Take the element to be inserted from User.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    Node *previousElement;
    Node *nextElement;
    int data;
};

class doublyLinkedList
{
private:
    Node *linkedlistArray;
    Node *head;
    int elementsCount;

public:
    bool makeDoublyLinkedList()
    {
        int data;
        cout << "Enter the numbers of elements in the doubly linked list: ";
        cin >> elementsCount;
        head = new Node;
        linkedlistArray = new Node[elementsCount];
        cout << "\nEnter the data in 0th element: ";
        cin >> data;
        (*head).data = data;
        (*head).nextElement = (linkedlistArray + 0);
        linkedlistArray[1].previousElement = head;
        linkedlistArray[1].nextElement = (linkedlistArray + 2);
        cout << "\nEnter the data in 1st element: ";
        cin >> data;
        linkedlistArray[1].data = data;
        for (int i = 2; i < elementsCount; i++)
        {
            cout << "\nEnter the data in " << i << "th element: ";
            cin >> data;
            linkedlistArray[i].previousElement = (linkedlistArray + i - 1);
            linkedlistArray[i].nextElement = (linkedlistArray + i + 1);
            linkedlistArray[i].data = data;
        }
        linkedlistArray[0] = *head;
        // Making the doubly linked list a circular doubly linked list
        linkedlistArray[elementsCount].nextElement = head;
        (*head).previousElement = &linkedlistArray[elementsCount];
        return true;
    }
    void accessElement()
    {
        int index;
        cout << "Enter which element's data you wanna access: ";
        std::cin >> index;
        cout << "\nProcessing sir...\n";
        if (index >= elementsCount)
        {
            cout << "Index exceeded...";
        }
        else
        {
            cout << "\nData in this index is " << linkedlistArray[index].data << endl;
        }
    }
};

int main(void)
{
    doublyLinkedList linkedlist;
    linkedlist.makeDoublyLinkedList();
    cout << "Created";
    linkedlist.accessElement();
    int a;
    cin >> a;
    return 0;
}