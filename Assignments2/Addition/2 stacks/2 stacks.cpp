// 2 stacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;
    stack <int> fir;
    stack <int> sec;
    while (N >= 0)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int k;
            cin >> k;
            fir.push(k);
        }
        else
        {
            while (!fir.empty())
            {
                sec.push(fir.top());
                fir.pop();
            }
            if (n == 2)
                sec.pop();
            if (n == 3)
                cout << sec.top();
            while (!sec.empty())
            {
                fir.push(sec.top());
                sec.pop();
            }
        }
        N--;
    }
    return 0;
}
