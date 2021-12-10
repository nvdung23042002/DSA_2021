// Pair using Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#define MAX 1000

using namespace std;

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

int main()
{
    int n, k;
    cin >> n;
    int a[MAX];
    set <int> sum;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum.emplace(a[i] + k);
    }
    //
    set <int>::iterator it;
    int count = 0;
    for (it = sum.begin(); it != sum.end(); ++it)
    {
        if (binarySearch(a, 0, n - 1, *it) != -1)
            count++;
    }
    cout << count;
    return 0;
}
