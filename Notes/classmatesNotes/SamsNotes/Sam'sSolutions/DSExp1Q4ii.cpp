// ii.	Find the sum and Average of all the elements of a 2-D array.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){

    int sum = 0;

    int TwoDArray[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i = 0; i < 3; i ++){

        for (int j = 0; j < 3; j++)
        {
            sum += TwoDArray[i][j];
        }
        
    }

    cout << "\nThe sum of this array is = " << sum << " and the average is = " << sum / 9;

    

    return 0;
}