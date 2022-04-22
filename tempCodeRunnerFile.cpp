#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){

    vector<int> a = {1,2,3};
    int b = a.pop_back();
    cout << b;

    return 0;
}