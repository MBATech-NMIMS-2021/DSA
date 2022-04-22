// Write a program in C/C++ to delete a node from the end of a doubly linked list. Take the element to be deleted from User.
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
        (*head).nextElement = (linkedlistArray + 1);
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
        // Making the linked list a circular doubly linked list
        linkedlistArray[elementsCount].nextElement = head;
        (*head).previousElement = &linkedlistArray[elementsCount];
        return true;
    };
    int accessElement()
    {
        int index;
        cout << "Enter the index of the element you wanna access: ";
        cin >> index;
        cout << "Making struct...\n"<< index << endl;
        Node *nextElement = head;
        cout << "Ok sir \n";

        for (int i = 0; i < elementsCount; i++)
        {
            cout << "Looping\n";
            if (index == i)
            {
                return (*nextElement).data;
            }
            nextElement = linkedlistArray[i].nextElement;
        }
        return 1;
    }
    bool deleteElement()
    {
        int index;
        cout << "\nEnter the index of the element that needs to get deleted: ";
        cin >> index;
        Node *previousElement = (*head).previousElement;
        // If last element needs to get deleted
        if (index + 1 == elementsCount)
        {

            (*head).previousElement = (*previousElement).previousElement;
            (*(*previousElement).previousElement).nextElement = head;
            return true;
        }
        // If the first element needs to get deleted
        if (index == 0)
        {
            head = (*head).nextElement;
            (*head).previousElement = (*(*head).previousElement).previousElement;
            return true;
        }
        for (int i = elementsCount; i >= 0; i--)
        {
            cout << "Processing...\n";
            // If middle element needs to get deleted
            if (i == index + 1)
            {
                (*(*previousElement).previousElement).nextElement = (*previousElement).nextElement;
                (*(*previousElement).nextElement).previousElement = (*previousElement).previousElement;
                return true;
            }
            previousElement = (*previousElement).previousElement;
        }
    }
};

int main(void)
{
    doublyLinkedList linkedlist;
    linkedlist.makeDoublyLinkedList();
    cout << linkedlist.accessElement();
    linkedlist.deleteElement();
    cout << linkedlist.accessElement();
    return 0;
}