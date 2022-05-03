#include <iostream>
#include <vector>
#include <string>

using namespace std;

class insertionSort
{
private:
    vector<int> unsortedVector;
    int sortedIndex = 0;

public:
    insertionSort(vector<int> sampleVector)
    {
        this->unsortedVector = sampleVector;
        traverseSortedVector();
    }
    void traverseSortedVector()
    {
        for (int i = 0; i < unsortedVector.size(); i++)
        {
            cout << "\nNext element: " << unsortedVector[i];
        }
    }
    bool sortVector()
    {
        cout << "\n\nSorting the " << sortedIndex << endl;
        // Terminating condition
        if (sortedIndex == unsortedVector.size() - 1)
        {
            traverseSortedVector();
            return true;
        }
        else
        {

            swap(sortedIndex, findMin(sortedIndex));
            sortedIndex++;
            traverseSortedVector();
            sortVector();
        }
        return false;
    }
    // Utility function to find the minimum element int the vector
    int findMin(int startingIndex)
    {
        int minNumberIndex = startingIndex;
        for (int i = startingIndex + 1; i < unsortedVector.size(); i++)
        {
            if (unsortedVector[i] < unsortedVector[minNumberIndex])
            {
                minNumberIndex = i;
            }
        }
        return minNumberIndex;
    }
    // Utility function to swap 2 elements in the vector
    bool swap(int m, int n)
    {
        int tempStorage = this->unsortedVector[m];
        this->unsortedVector[m] = this->unsortedVector[n];
        this->unsortedVector[n] = tempStorage;
        return true;
    }
};

int main(void)
{
    vector<int> a = {100, 78, 45, 65, 73, 38, 94, 35};
    insertionSort b(a);
    b.sortVector();
    return 0;
}