#include <iostream>
#include <vector>
#include <string>

using namespace std;

int printElement(int array[], int index)
{
    // Breaking condition
    if (index == 5)
    {
        return 0;
    }
    else
    {
        cout << "\nThe " << index << "th element is " << array[index];
        printElement(array, index + 1);
    }
}

int main(void)
{

    int array[5] = {1, 2, 3, 4, 5};

    printElement(array, 0);

    return 0;
}