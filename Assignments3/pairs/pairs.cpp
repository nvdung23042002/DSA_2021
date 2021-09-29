// Closet number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int Way1(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[j] - arr[i] == k)
                count++;

    }
    return count;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2; 

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    // if can not be found
    return -1;
}

int Way2(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + k <= arr[n - 1])
        {
            if (binarySearch(arr, i, n - 1, arr[i] + k) != -1)
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[MAX];
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //
    sort(arr, arr + n);
    // search min
    cout << Way2(arr, n, k);
    return 0;
}

