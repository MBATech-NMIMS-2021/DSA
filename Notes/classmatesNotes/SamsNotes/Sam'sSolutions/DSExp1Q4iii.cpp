#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){

    int array[5] = {10, 2, 3, 4, 5};

    int leastValue = array[0];
    int maxValue = array[0];

    for (int i = 0; i < 5; i++)
    {
        if(array[i] < leastValue){
            leastValue = array[i];
        } else if (array[i] > maxValue){
            maxValue = array[i];
        }
    }

    cout << "\nThe max value is " << maxValue << " and the least value is " << leastValue;

    return 0;
}