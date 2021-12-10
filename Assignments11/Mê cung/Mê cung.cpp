// Mê cung.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void nhapmang(int a[500][500], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];
}
void PrintArray(int a[500][500], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void Exit(int a[500][500], int rows, int cols, int i, int j)
{
    if (i == rows - 1 && j == cols - 1) {
        a[i][j] = 2;
        PrintArray(a, rows, cols);
    }

    if (a[i][j + 1] == 0 && j < cols - 1) {
        a[i][j] = 2;
        Exit(a, rows, cols, i, j + 1);
        a[i][j] = 0;
    }
    if (a[i + 1][j] == 0 && i < rows - 1) {
        a[i][j] = 2;
        Exit(a, rows, cols, i + 1, j);
        a[i][j] = 0;
    }
    if (a[i][j - 1] == 0 && j > 0) {
        a[i][j] = 2;
        Exit(a, rows, cols, i, j - 1);
        a[i][j] = 0;
    }
    if (a[i - 1][j] == 0 && i > 0) {
        a[i][j] = 2;
        Exit(a, rows, cols, i - 1, j);
        a[i][j] = 0;
    }
}
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    int a[500][500];
    nhapmang(a, rows, cols);
    Exit(a, rows, cols, 0, 0);
    return 0;
}