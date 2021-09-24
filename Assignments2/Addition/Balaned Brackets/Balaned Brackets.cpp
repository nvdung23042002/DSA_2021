// Balaned Brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

bool check(char a, char b)
{
    if (a == '{' and b == '}')
        return true;
    if (a == '(' and b == ')')
        return true;
    if (a == '[' and b == ']')
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        stack <char> st;
        int i = 0;

        while (i < s.size())
        {
            if (st.empty())
            {
                st.push(s[i]);
                i++;
            }
            else
            {
                if (check(st.top(), s[i]) == true)
                {
                    st.pop();
                    i++;
                }
                else
                {
                    st.push(s[i]);
                    i++;
                }
            }
            
        }
        if (st.empty())
        {
            cout << "YES" << endl;        
        }
        else
        {
            cout << "NO" << endl;
        }
        n--;
    }
    
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
