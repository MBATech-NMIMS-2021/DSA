#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class search
{
private:
    vector<int> vectorSet;
    int element;

public:
    // Constructor function to set vectorSet
    search(vector<int> sampleVector, int findElement)
    {
        this->vectorSet = sampleVector;
        this->element = findElement;
    }
    // Function to perform search using the linear search algorithm. Returns true if element is found, else false
    bool linearSearch()
    {
        for (int i = 0; i < vectorSet.size(); i++)
        {
            if (vectorSet[i] == element)
            {
                cout << "ELEMENT FOUND SIR...";
                return true;
            }
        }
        return false;
    }
    // Function to perform search using binary search algorithm
    bool binarySearch()
    {
        binarySearchUnitOperation(0, vectorSet.size());
    }
    bool binarySearchUnitOperation(int startIndex, int endIndex)
    {
        cout << "\nProcessing";
        int midIndex = findMidIndex(startIndex, endIndex);
        if (vectorSet[midIndex] == element)
        {
            cout << "\nELEMENT FOUND SIR...";
            return true;
        }
        else if (vectorSet[midIndex] < element)
        {
            binarySearchUnitOperation(midIndex + 1, endIndex);
        }
        else
        {
            binarySearchUnitOperation(startIndex, midIndex - 1);
        }
    }
    int findMidIndex(int startIndex, int endIndex)
    {
        cout << "\nChecking " << vectorSet[floor((startIndex + endIndex) / 2)];
        return floor((startIndex + endIndex) / 2);
    }
};

int main(void)
{
    vector<int> a = {1, 2, 4, 6, 8, 30};
    search b(a, 4);
    b.binarySearch();
    return 0;
}