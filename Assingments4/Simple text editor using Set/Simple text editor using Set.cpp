// Simple text editor using Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int ops;
    cin >> ops;
    set <string> st;
    st.emplace("dung");
    cout << *(st.end()--);
}

