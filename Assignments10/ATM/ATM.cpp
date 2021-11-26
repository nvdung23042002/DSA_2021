// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//type of money (thoudsand dong)
int money[10] = {500,200,100,50,20,10,5,2,1};

void unLimited()
{
    // so tien muon rut
    int num;
    // nhap vao so tien muon rut
    cout << "Nhap vao so tien muon rut(dv: nghin dong): ";
    cin >> num;
    // tinh so luong tien can tra ra
    cout << "So tien tra ra la:\n";
    int i = 0;
    while (i < 9 and num > 0)
    {
        if (num < money[i]) i++;
        else {
            int count = num / money[i];
            cout << count << " to " << money[i] << " nghin dong \n";
            num = num % money[i];
            i++;
        }
    }
}

void Limited()
{
    //so tien muon rut
    int num;
    // nhap vao so tien muon rut
    cout << "Nhap vao so tien muon rut(dv: nghin dong): ";
    cin >> num;
    int remaining[10];
    for (int i = 0; i < 9; i++)
    {
        cout << "So luong to " << money[i] << " nghin dong con lai trong may la: ";
        cin >> remaining[i];
    }
    cout << "\n\n\n";
    int i = 0;
    while (i < 9 and num > 0)
    {
        if (num < money[i]) i++;
        else {
            int count = num / money[i];
            if (count >= remaining[i])
            {
                cout << "Co " << remaining[i] << " to " << money[i] << " nghin dong; \n";
                num = num - remaining[i] * money[i];
                i++;
            }
            else {
                cout << "Co " << count << " to " << money[i] << " nghin dong; \n";
                num = num / money[i];
                i++;
            }
        }
    }
}
int main()
{
   Limited();
    return 0;
}

