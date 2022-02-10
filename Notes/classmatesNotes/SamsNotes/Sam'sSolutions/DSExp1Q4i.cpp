// Find the sum and Average of all the elements of a 1-D array

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){

    int arrayLength;

    cout << "Kindly enter the length of the array: ";
    cin >> arrayLength;

    int sum = 0;

    int *array;
    array = new int[arrayLength];

    for (int elementIndex = 0; elementIndex < arrayLength; elementIndex++)
    {
        cout << "\nKindly enter the " << elementIndex << "th value of the array: ";
        cin >> *(array + elementIndex);
        sum += *(array + elementIndex);
    }

    cout << "\nThe sum of this array is = " << sum << " and the average is = " << sum / arrayLength;

    return 0;
}