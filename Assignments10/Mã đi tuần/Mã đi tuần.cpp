// Mã đi tuần.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int a[10][10] = { 0 };
int X[10] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int Y[10] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int k = 0;

// check position
bool OK(int x, int y)
{
    if (x >= 1 and x <= 8 and y >= 1 and y <= 8 and a[x][y] == 0)
        return true;
    return false;
}

void Try(int x, int y)
{
    if (OK(x, y))
    {
        k++;
        a[x][y] = 1;
        for (int i = 0; i < 8; i++)
        {
            Try(x + X[i], y + Y[i]);
        }
    }
    
}

int main()
{
    Try(1, 1);
    cout << k << endl;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

