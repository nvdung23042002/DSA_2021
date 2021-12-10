// Equal Stacks using Map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1;
    set <int> st1, st2, st3;
    int a1[100], s1 = 0;
    for (int i = 0; i < n1; i++)
    {
        cin >> a1[i];
        s1 += a1[i];
    }
    for (int i = n1 - 1; i >= 0; i--)
    {
        st1.emplace(s1);
        s1 -= a1[i];
    }
    //
    int a2[100], s2 = 0;
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
        s2 += a2[i];
    }
    for (int i = n2 - 1; i >= 0; i--)
    {
        st2.emplace(s2);
        s2 -= a2[i];
    }
    //
    int a3[100], s3 = 0;
    for (int i = 0; i < n3; i++)
    {
        cin >> a3[i];
        s3 += a3[i];
    }
    for (int i = n1 - 1; i >= 0; i--)
    {
        st3.emplace(s3);
        s3 -= a3[i];
    }
    //
    set <int>::iterator it1, it2, it3;
    for (it1 = st1.begin(); it1 != st1.end(); ++it1)   
        for (it2 = st2.begin(); it2 != st2.end(); ++it2)      
            for (it3 = st3.begin(); it3 != st3.end(); ++it3)          
                if (*it1 == *it2 and *it2 == *it3)
                {
                    cout << *it1 << endl;
                    return 0;
                }
}

