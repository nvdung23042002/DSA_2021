// EX4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct HashMap 
{
    int ID;
    string Name;
    string Class;

    map <int, string> data;
    // default constructor
    HashMap()
    {
        ID = 0;
        Name = "";
        Class = "";
    }
    // insert function
    void Insert(int ID, string Name, string Class)
    {
        string s = Name + "," + Class;
        data.emplace(ID, s);
    }

    // delete function
    void Delete(int ID)
    {
        data.erase(ID);
    }

    // get infor function
    void Infor(int ID)
    {
        map<int, string>::iterator it;
        for (it = data.begin(); it != data.end(); it++)
        {
            if (it->first == ID)
            {
                cout << it->second;
                return;
            }
        }
            cout << "NA,NA" << endl;
    }
};




int main()
{
    HashMap a;
    a.Insert(20021317, "Dung NV1", "K65 N");
    a.Insert(20021318, "Dung NV2", "K65 N");
    a.Insert(20021319, "Dung NV3", "K65 N");
    a.Infor(20021316);
    return 0;
}
