#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node
{
    int data;
    node *pointer;
};

class linkedlist
{
public:
    int linkedlistSize;
    // A vector that can store pointers to node
    vector<node *> linkedlist;
    node *head;

    //* Function to generate a linked list
    // It'll ask from users the number of elements, and the data at each node
    void makeLinkedList()
    {
        cout << "Enter the size of linked list: ";
        cin >> linkedlistSize;

        for (int i = 0; i < linkedlistSize; i++)
        {
            // Creating a new node, as an element of
            linkedlist.push_back(new node());

            // Inserting its value
            cout << "Enter the data to get inserted at the " << i << "th position: ";
            cin >> (*linkedlist[i]).data;

            // Setting the pointer value of the previous element...
            if (i == 0)
            // Setting the head value if it's the first node
            {
                head = linkedlist[0];
            }
            else if (i == linkedlistSize - 1)
            {
                // Setting the null pointer, if it's the last element
                (*linkedlist[linkedlistSize - 1]).pointer = NULL;
            }
            else
            {
                (*linkedlist[i - 1]).pointer = linkedlist[i];
            }
        }
    };

    //* Recursive function to traverse through the linked list
    void traverseLinkedlist(node *pointer)
    {
        if (pointer == (NULL))
        {
            cout << "The last element is " << *(linkedlist[linkedlistSize-1]).data;
        }
        else
        {

            cout << "\nThe element is " << (*pointer).data;
            traverseLinkedlist((*pointer).pointer);
        }
    }

    void Traversal(){
        traverseLinkedlist(head);
    }

    //* Function for the insertion of an element into the linked list
    void insertion()
    {
        node *iteratorPointer = head;
        char userResponse;

        for (int i = 0; i < linkedlistSize + 1; i++)
        {
            cout << "Would you like to insert the element at " << i << "th index? (Y/N) ";
            cin >> userResponse;

            if (userResponse == 'Y')
            {
                int inputData;
                cout << "Kindly enter the element to get inserted: ";
                cin >> inputData;

                // If the user wants to insert the element in the beginning
                if (i == 0)
                {
                    node *insertedElement = new node();
                    head = insertedElement;

                    (*insertedElement).pointer = linkedlist[0];
                }
                else if (i == linkedlistSize)
                {
                    // Here i is basically the linkedlistSize
                    linkedlist.push_back(new node());

                    (*linkedlist[i - 1]).pointer = linkedlist[i];

                    (*linkedlist[i]).pointer = NULL;
                }
                else
                {
                    node *insertedElement = new node();
                    (*linkedlist[i - 1]).pointer = insertedElement;

                    (*insertedElement).pointer = linkedlist[i + 1];
                }
                cout << "Element inserted at the " << i << "th position.\nTerminating the loop...";
                break;
            }
            else if (userResponse == 'N')
            {
            }
        }
    }

    //* Function to delete an element from the linked list
    void deleteElement()
    {
        char userInput;
        for (int i = 0; i < linkedlistSize; i++)
        {
            cout << "Would you like to delete " << (*linkedlist[i]).data << " whose memory address is " << (*linkedlist[i]).pointer << "? (Y/N) ";
            cin >> userInput;

            // Deleting the element

            // If the first elements needs to get deleted
            if (i == 0)
            {
                head = linkedlist[1];
            }
            else if (i == linkedlistSize - 1)
            {
                // If the last element needs to get deleted
                (*linkedlist[i - 1]).pointer = NULL;
            }
            else
            {
                (*linkedlist[i - 1]).pointer = linkedlist[i + 1];
            }
        }
    }
};

int main(void)
{
    linkedlist myLinkedList;

    myLinkedList.makeLinkedList();
    myLinkedList.Traversal();

    return 0;
}