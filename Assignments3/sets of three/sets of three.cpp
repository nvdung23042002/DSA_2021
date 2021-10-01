// sets of three.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

int a[MAX];

using namespace std;

// way1 is have the complexity O(n^3)
void Way1(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
             for (int m = j + 1; m < n; m++)
                if (a[i] + a[j] + a[m] == 0)
                    cout << a[i] << " " << a[j] << " " << a[m] << endl;     
}

bool myfunction(int i, int j) { return (i < j); }

int binarySearch(vector <int> pos, int l, int r, int x) {
    if (r >= l) {
        int mid = (r + l) / 2; 
        if (pos[mid] == x)
            return mid;

        if (pos[mid] > x)
            return binarySearch(pos, l, mid - 1, x);

        
        return binarySearch(pos, mid + 1, r, x);
    }
    return -1;
}


void Way2(vector <int> neg, vector <int> pos)
{
    // 2 positive 1 negative
    for (int i = 0; i < neg.size(); i++)
    {
        for (int j = 0; j < pos.size(); j++)
            if (pos[j] < abs(neg[i]))
            {
                int x = abs(neg[i]) - pos[j];
                int mid = binarySearch(pos, j + 1, pos.size() - 1, x);
                if (mid != -1)
                    cout << neg[i] << " " << pos[j] << " " << pos[mid] << endl;
            }
    }
         
    // 2 negative 1 positive
    for (int i = 0; i < pos.size(); i++)
    {
        for (int j = 0; j < neg.size(); j++)
            if (pos[i] > abs(neg[j]))
            {
                int x = -pos[i] - neg[j];
                int mid = binarySearch(neg, j + 1, neg.size() - 1, x);
                if (mid != -1)
                    cout << pos[i] << " " << neg[j] << " " << neg[mid] << endl;
            }
    }
}


int main()
{
    int n;
    cin >> n;    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector <int> neg;
    vector <int> pos;
    // positive vector
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            pos.push_back(a[i]);
    int sizePos = pos.size();
    sort(pos.begin(), pos.begin() + sizePos);

    // negative vector
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            neg.push_back(a[i]);
    int sizeNeg = neg.size();
    sort(neg.begin(), neg.begin() + sizeNeg, myfunction);
    //do Way1 
    // Way1(n);
    
    
    //do Way2
    Way2(neg, pos);
    return 0;
}

