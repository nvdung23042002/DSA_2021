// Sherlock and array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define MAX 100001

int a[MAX];
int sum_lower(int k)
{
    int sum1 = 0;
    for (int i = 1; i < k; i++)
        sum1 = sum1 + a[i];
    return sum1;

}

int sum_upper(int k, int n)
{
    int sum2 = 0;
    for (int i = k + 1; i <= n; i++)
        sum2 = sum2 + a[i];
    return sum2;
}

// complexity = O(n^2)
void Way1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (sum_lower(i) == sum_upper(i, n))
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

// complexity = O(n)
void Way2(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sum + a[i];
    //
    int sumLeft = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum - a[i] - 2 * sumLeft == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO";
}


int main()
{
    int k;
    cin >> k;
    while (k > 0)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        Way2(n);
        k--;
    }
    return 0;
}
