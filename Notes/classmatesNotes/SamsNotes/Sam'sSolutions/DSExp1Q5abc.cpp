#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Function to print the array
void printArray(int arrayLength, int array[])
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "\nThe " << i << "th element of the array is: " << array[i];
    }
}

// Function to print the vector
void printVector(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << "\nThe " << i << "th element of vector is = " << array[i];
    }
}

// Function to print out the array in reverse
void printReverseArray(int array[20])
{
    int endElement;
    for (int i = 0; i < int(20 / 2); i++)
    {
        endElement = array[i];
        cout << "\nreplacing " << array[i] << " with " << array[20 - i - 1];
        array[i] = array[20 - i - 1];
        array[20 - i - 1] = endElement;
    }
    printArray(20, array);
}

// Function to find out the mode
void findMode(int array[])
{
    map<int, int> uniqueElements;
    for (int i = 0; i < 20; i++)
    {
        uniqueElements[array[i]]++;
    }
    int maxCount = uniqueElements[array[0]];
    int mode = 0;
    // Iterating over the map to find mode
    for (auto it = uniqueElements.begin(); it != uniqueElements.end(); ++it)
    {
        cout << "\nCount of " << it->first << " is " << it->second;
        if ((maxCount < (it->second)))
        {
            mode = (it->first);
            cout << endl
                 << "Making " << it->first << " as the mode";
        }
    }
    if (mode == 0)
    {
        cout << "\nMode does not exists";
    }
    else
    {
        cout << "\nMode is " << mode;
    }
}

// Function to move zeroes to the end
void moveZeroes(int array[], int arrayLength){
    vector<int> arrayClone;
    int zeroesCounter = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if(array[i] != 0){
            arrayClone.push_back(array[i]);
        } else {
            zeroesCounter++;
        }
    }
    for (int i = 0; i < zeroesCounter; i++)
    {
        arrayClone.push_back(0);
    }
    printVector(arrayClone);
}

int main(void)
{

    // Taking array as input
    int array[20];
    int sum = 0;

    for (int i = 0; i < 20; i++)
    {
        cout << "Enter the " << i << "th element: ";
        cin >> array[i];
        sum += array[i];
    }

    // Printing in reverse
    cout << "\nPRINTING THE REVERSED ARRAY: \n";
    printReverseArray(array);

    // Printing out the array with 0's shifted to the end
    cout << "\n\nPRINTING OUT THE ARRAYS WITH SHIFTED ZEROES: \n";
    moveZeroes(array, 20);

    // Printing mean
    cout << "\n\nMean of the array is " << sum / 20<<"\n";

    // Calculating the mode
    findMode(array);
    return 0;
}