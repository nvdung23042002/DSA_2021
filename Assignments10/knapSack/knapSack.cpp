// knapSack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> mass;
vector <double> value;

double ratio(double m)
{
    for (int i = 0; i < mass.size(); i++)
    {
        if (value[i] == m)
            return m / mass[i];
    }
}

void Sort(vector <double> &ra)
{
    for (int i = 0; i < value.size(); i++)
    {
        for (int j = i + 1; j < value.size(); j++)
        {
            if (ra[i] < ra[j])
            {
                // sap xep gia tri
                int temp = value[i];
                value[i] = value[j];
                value[j] = temp;
                // sap xep ti le
                int ind = ra[i];
                ra[i] = ra[j];
                ra[j] = ind;
                // sap xep khoi luong
                int pos = mass[i];
                mass[i] = mass[j];
                mass[j] = pos;
            }
        }
    }
}

void greedy(vector <double> ra, int mMax)
{
    int i = 0;
    int vMax = 0;
    int dMax = 0;
    while (i < mass.size() and mMax > 0)
    {
        if (mass[i] > mMax) i++;
        else {
            int cou = mMax / mass[i];
            vMax = vMax + cou * value[i];
            dMax = dMax + cou * mass[i];
            mMax = mMax % mass[i];
            i++;
        }
    }
    cout << "Khoi luong lon nhat lay duoc la: " << dMax << "\n\n\n";
    cout << "Gia Tri lon nhat lay duoc la: " << vMax;
}
int main()
{
    // khoi luong toi da cua balo
    int mMax;
    cout << "Nhap Vao khoi luong toi da cua balo: ";
    cin >> mMax;
    
    //so luong do vat 
    cout << "So luong do vat: ";
    int n;
    cin >> n;    
    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Khoi Luong vat " << i + 1 << " la: ";
        cin >> m;
        mass.push_back(m);
    }
    

    //gia tri cua do vat
   
    for (int i = 0; i < n; i++)
    {
        double m;
        cout << "Gia tri cua vat " << i + 1 << " la: ";
        cin >> m;
        value.push_back(m);
    }
    
   
    //ti le gia tri / khoi luong
    vector <double> ra;
    for (int i = 0; i < n; i++)
    {
        ra.push_back(value[i] / mass[i]);
    }
    cout << "\n\n\n";
    // sap xep lai theo ti le va in ra man hinh
    Sort(ra);
    cout << "Ti le: ";
    for (int i = 0; i < n; i++)
    {
        cout << ra[i] << "    ";
    }
    cout << "\n\n\n";
    // 
    cout << "Gia Tri: ";
    for (int i = 0; i < n; i++)
    {
        cout << value[i] << setw(4);
    }
    cout << "\n\n\n";
    // khoi luong
    cout << "Khoi Luong: ";
    for (int i = 0; i < n; i++)
    {
        cout << mass[i] << setw(4);
    }
    cout << "\n\n\n";
    
    // ap dung thuat toan tham lam
    greedy(ra, mMax);
    return 0;
}
