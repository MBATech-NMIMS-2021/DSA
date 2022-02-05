#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the array
void printArray(int arrayLength, int array[])
{
    for (int i = 0; i < arrayLength - 1; i++)
    {
        cout << "\nThe " << i << "th element of the array is: " << array[i] << "\n";
    }
}

bool removeElement(int *array, int removeIndex, int arrayLength)
{
    if (removeIndex == arrayLength - 1)
    {
        cout << "\nEnding at index: " << removeIndex;
        printArray(arrayLength, array);
        return (false);
    }
    else
    {
        cout << "Replacing element at index " << removeIndex << " with " << removeIndex + 1;
        array[removeIndex] = array[removeIndex + 1];
        return removeElement(array, removeIndex + 1, arrayLength);
    }
}

int main(void)
{

    int arrayLength;

    cout << "Kindly enter the length of the array: ";
    cin >> arrayLength;

    // Creating an array through dynamic allocation

    int *array;
    array = new int[arrayLength + 5];

    // Getting the elements of the array as input

    for (int i = 0; i < arrayLength; i++)
    {
        // taking each element through user input
        cout << "\nKindly enter the " << i << "th element of the array: ";
        cin >> *(array + i);
    }

    int deleteIndex;

    cout << "Which index element do you want to remove? ";
    cin >> deleteIndex;

    // function to remove that element in a recursive fashion
    removeElement(array, deleteIndex, arrayLength);

    return 0;
}