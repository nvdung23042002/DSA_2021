// Closet number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int searchMin(int arr[MAX], int n)
{
    int min = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        int res = arr[i + 1] - arr[i];
        if (res < min)
            min = res;
    }
    return min;
}
int main()
{
    int arr[MAX];
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //
    sort(arr, arr + n);
    // search min
    int min = searchMin(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        int res = arr[i + 1] - arr[i];
        if (res == min)
            cout << arr[i] << " " << arr[i + 1]<<" ";
    }
    return 0;
}

