#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *nextElement;
    Node *previousElement;
};

class doublyLinkedList
{

private:
    unsigned int doublyLinkedListSize;
    Node *head = new Node;

public:
    void createDoublyLinkedList()
    {

        cout << "\nEnter the size of doubly linked list: ";
        cin >> doublyLinkedListSize;

        int elementData;

        Node *currentElement = head;

        for (int i = 0; i < doublyLinkedListSize; i++)
        {
            cout << "\nEnter the data at " << i << "th element: ";
            cin >> elementData;

            (*currentElement).data = elementData;
            (*currentElement).nextElement = new Node;
            // Setting previous element pointer of next element
            (*(*currentElement).nextElement).previousElement = currentElement;
            // Setting next element pointer of current element
            currentElement = (*currentElement).nextElement;
        }

        // Setting the null pointers
        (*(*currentElement).previousElement).nextElement = NULL;
        (*head).previousElement = (*currentElement).previousElement;
    }

    void traverseDoublyLinkedList()
    {
        Node *currentElement = head;
        unsigned int counter = 0;
        while (currentElement != NULL)
        {
            cout << "\nThe " << counter << "th element is " << (*currentElement).data;
            currentElement = (*currentElement).nextElement;
            counter++;
        }
    }

    void insertNodeAtBeginning()
    {
        int newNodeData;

        Node *newNode;
        newNode = new Node;

        cout << "\nEnter the data in new node: ";
        cin >> newNodeData;

        (*newNode).data = newNodeData;

        Node *tempNodeStorage = head;
        head = newNode;
        (*head).nextElement = tempNodeStorage;
        (*head).previousElement = (*tempNodeStorage).previousElement;
        (*tempNodeStorage).previousElement = head;
    }

    void deleteNodeFromEnd()
    {
        int elementDataToDelete;
        Node *lastElement = (*head).previousElement;

        cout << "\nEnter the element that you wanna get deleted from the doubly linked list: ";
        cin >> elementDataToDelete;

        Node *currentElement = (*head).previousElement;

        do
        {
            if ((*currentElement).data == elementDataToDelete)
            {
                // If it's the last element
                if ((*currentElement).nextElement == NULL)
                {
                    (*(*currentElement).previousElement).nextElement = NULL;
                }
                // If the element is the head
                else if (currentElement == head)
                {
                    // Updating the pointer value of next element
                    (*(*currentElement).nextElement).previousElement = (*currentElement).previousElement;
                    head = (*head).nextElement;
                }
                else
                {
                    // Updating the pointer value of previous element
                    (*(*currentElement).previousElement).nextElement = (*currentElement).nextElement;
                    // Updating the pointer value of next element
                    (*(*currentElement).nextElement).previousElement = (*currentElement).previousElement;
                };
            }
            currentElement = (*currentElement).previousElement;
        } while (currentElement != lastElement);

        cout << "\nFirst occurrence of the element deleted sir.";
    }

    void insertAtAnyPosition()
    {
        unsigned int index;
        int value;
        unsigned int indexCounter = 0;
        Node *newNode = new Node;

        cout << "\nEnter the index where you wanna insert a new node: ";
        cin >> index;

        cout << "\nEnter the data that you wanna store in that index: ";
        cin >> value;

        Node *currentNode = head;
        (*newNode).data = value;

        while (currentNode != NULL)
        {
            cout << "\nProcessing...";
            if (index == indexCounter)
            {
                // If element needs to get inserted at the last index
                if ((*currentNode).nextElement == NULL)
                {
                    (*currentNode).nextElement = newNode;
                    (*newNode).nextElement = NULL;
                    (*head).previousElement = newNode;
                }
                // If the element needs to get inserted at the head position
                else if (index == 0)
                {
                    (*newNode).previousElement = (*head).previousElement;
                    (*head).previousElement = newNode;
                    (*newNode).nextElement = head;
                    head = newNode;
                }
                // If its somewhere in the middle
                else
                {
                    // Setting the pointer of previous element
                    (*(*currentNode).previousElement).nextElement = newNode;
                    // Setting pointer of newNode
                    (*newNode).previousElement = (*currentNode).previousElement;
                    (*newNode).nextElement = currentNode;
                    // Setting the pointer of current element
                    (*currentNode).previousElement = newNode;
                }
                break;
            }
            currentNode = (*currentNode).nextElement;
            indexCounter++;
        }
    }

    void searchElement()
    {
        int valueSearch;
        unsigned int indexCounter = 0;

        cout << "\nEnter the value to search in the linked list: ";
        cin >> valueSearch;

        Node *currentElement = head;

        while (currentElement != NULL)
        {
            if ((*currentElement).data == valueSearch)
            {
                cout << "\nFound " << valueSearch << " at index " << indexCounter << " and memory address " << currentElement;
                break;
            }
            currentElement = (*currentElement).nextElement;
            indexCounter++;
        }
    }
};

int main(void)
{

    doublyLinkedList list;
    list.createDoublyLinkedList();
    list.traverseDoublyLinkedList();
    // list.insertNodeAtBeginning();
    // list.traverseDoublyLinkedList();
    // list.deleteNodeFromEnd();
    // list.traverseDoublyLinkedList();
    // list.insertAtAnyPosition();
    // list.traverseDoublyLinkedList();
    list.searchElement();

    return 0;
}