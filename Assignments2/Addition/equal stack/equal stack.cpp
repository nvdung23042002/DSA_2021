// equal stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int set_min(int a, int b, int c)
{
    if (a <= b and a <= c)
        return a;
    else
    {
        if (b <= c)
            return b;
        else
            return c;
    }
}
int main()
{
    long n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    long sum1 = 0, sum2 = 0, sum3 = 0;
    long arr1[100000], arr2[100000], arr3[100000];
    long min = 0;
    stack <int> h1, h2, h3;
    for (long i = 1; i <= n1; i++)
    {
        cin >> arr1[i];
        sum1 = sum1 + arr1[i];
    }
    for (long i = n1; i >= 1; i--)
    {
        h1.push(arr1[i]);
    }

    //
    for (long i = 1; i <= n2; i++)
    {
        cin >> arr2[i];
        sum2 = sum2 + arr2[i];
    }
    for (long i = n3; i >= 1; i--)
    {
        h2.push(arr2[i]);
    }
    //
    for (long i = 1; i <= n3; i++)
    {
        cin >> arr3[i];
        sum3 = sum3 + arr3[i];
    }
    for (long i = n3; i >= 1; i--)
    {
        h3.push(arr3[i]);
    }
    //
    min = set_min(sum1, sum2, sum3);
    while (!h1.empty() or !h2.empty() or !h3.empty())
    {
        if (sum1 == sum2 and sum1 == sum3)
        {
            cout << sum1;
            return 0;
        }
        if (sum1 > min)
        {
            sum1 = sum1 - h1.top();
            h1.pop();
        }
        else
            min = sum1;
        if (sum2 > min)
        {
            sum2 = sum2 - h2.top();
            h2.pop();
        }
        else
            min = sum2;
        if (sum3 > min)
        {
            sum3 = sum3 - h3.top();
            h3.pop();
        }
        else
            min = sum3;
    }
    cout << 0;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
