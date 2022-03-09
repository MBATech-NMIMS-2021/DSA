// Insertion into the array

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the array
void printArray(int arrayLength, int array[])
{
    for (int i = 0; i < arrayLength + 1; i++)
    {
        cout << "The " << i << "th element of the array is: " << array[i] << "\n";
    }
}

// Inserting an element through recursion
bool recursiveInsertion(int arrayLength, int *array, int insertElement, int index)
{
    cout << "\nRunning for the " << index << "th index\n";
    //$ Breaking condition
    if (index == arrayLength + 1)
    {
        printArray(arrayLength, array);
        return (false);
    }
    else
    {
        int currentElement = array[index];
        array[index] = insertElement;
        return recursiveInsertion(arrayLength, array, currentElement, index + 1);
    }
}

int main(void)
{

    int arrayLength;

    cout << "Kindly enter the length of the array: ";
    cin >> arrayLength;

    // Creating an array through dynamic allocation

    int *array;

    //$ Adding 5 to make space for the element that needs to get inserted

    array = new int[arrayLength + 5];

    // Getting the elements of the array as input

    for (int i = 0; i < arrayLength; i++)
    {
        // taking each element through user input
        cout << "\nKindly enter the " << i << "th element of the array: ";
        cin >> *(array + i);
    }

    int insertElement, index;
    cout << "Enter the index where you need to insert an element: ";
    cin >> index;

    cout << "Enter the element to be inserted: ";
    cin >> insertElement;

    // Running the recursive insertion function
    recursiveInsertion(arrayLength, array, insertElement, index);

    return 0;
}