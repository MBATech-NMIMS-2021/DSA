#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Node{
    Node *rightNode;
    Node *leftNode;
    string uniqueId;
};

int main(void){

    cout << "Enter the task you wanna execute: \n";

    cout << "1) Create element\n2)Delete element\n3)Insert element\n4)Traverse\n\nSelect the task: ";

    int taskSelected;
    cin >> taskSelected;

    

    return 0;
}