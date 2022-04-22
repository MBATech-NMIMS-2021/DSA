#include <iostream>
#include <vector>
#include <string>

using namespace std;

int factorial(int n, int temporaryAnswer = 1)
{
    if (n == 0)
    {
        return temporaryAnswer;
    }
    else
    {
        temporaryAnswer *= (n);
        return factorial(n - 1, temporaryAnswer);
    }
}

int main(void)
{

    cout << factorial(6);

    return 0;
}