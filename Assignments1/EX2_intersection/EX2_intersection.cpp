// EX2_intersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    double x;
    double y;

public:
        double getx()
        {
            return x;
        }
        double gety()
        {
            return y;
        }
        void input()
            {
                cin >> this->x;
                cin >> this->y;
            }
         void output()
            {
                cout << this->x << endl;
                cout << this->y << endl;
            }

// nạp chồng toán tử + cho c
public:Point operator - (Point b)
    {
        Point c;
        c.x = (this->x - b.x) ;
        c.y = (this->y - b.y) ;
        return c;
    }
};

int pt_AB(int nABx, int nABy, int xo, int yo, int x, int y)
{
    int k = nABx * (x - xo) + nABy * (y - yo);
    return k;
}

int main()
{
    Point A, B, C, D;
    A.input();
    B.input();
    C.input();
    D.input();
    Point AB = A - B;
    Point CD = C - D;
    int nABx = -AB.gety();
    int nABy = AB.getx();
    int nCDx = -CD.gety();
    int nCDy = CD.getx();
    if ((nABx / nABy) * nCDy == nCDx and (nABy == 0 and nCDy == 0))
    {
        if (pt_AB(nABx, nABy, A.getx(), A.gety(), C.getx(), C.gety()) == 0)
            if( (C.getx() <= A.getx() and C.getx() >= B.getx()) or (C.getx() >= A.getx() and C.getx() <= B.getx()))
            cout << "MANY";
        else
            cout << "NO";
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
