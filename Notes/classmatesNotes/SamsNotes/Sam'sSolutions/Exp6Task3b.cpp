#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool generateFibonacci(int totalTerms, int currentTerm, vector<int> fibonacciNumbers)
{
    if (currentTerm == totalTerms)
    {
        return true;
    }
    else
    {
        fibonacciNumbers.push_back(fibonacciNumbers[currentTerm - 1] + fibonacciNumbers[currentTerm - 2]);
        cout << "\nNext fibonacci number " << fibonacciNumbers[currentTerm];
        generateFibonacci(totalTerms, ++currentTerm, fibonacciNumbers);
    }
}

int main(void)
{
    vector<int> ini = {0, 1};
    
    cout << "\nNext fibonacci number " << ini[0];
    cout << "\nNext fibonacci number " << ini[1];

    generateFibonacci(15, 2, ini);
    return 0;
}