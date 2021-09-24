// simple text edition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str = "";
    stack <string> st;
    int n;
    cin >> n;
    while (n > 0)
    {
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            string s;
            cin >> s;
            st.push(str);
            str = str + s;
        }
        break;
        case 2:
        {
            int k;
            cin >> k;
            st.push(str);
            str = str.substr(0, str.size() - k);
            break;
        }
        case 3:
        {
            int p;
            cin >> p;
            cout << str[p - 1] << endl;
            break;
        }
        case 4:
        {
            str = st.top();
            st.pop();
            break;
        }
        }
    }
    return 0;
}

