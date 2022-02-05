#include <iostream.h>
#include <conio.h>
int main(void)
{
    clrscr();
    int array[3][4] = {{34, 12, 9, 42}, {45, 86, 14, 44}, {43, 88, 6, 91}};
    int max = 34;
    int min = 34;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (max < array[i][k])
            {
                max = array[i][k];
            }
            if (array[i][k] < min)
            {
                min = array[i][k];
            }
        }
    }
    cout << "Maximimum value is" << max << endl
         << "Minimum value is" << min;
    getch();
    return (0);
}