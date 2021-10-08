// Additional1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Student
{
    map <int, string> bucket [11];
    vector <int> nul;
    int hashKey(int mssv) {
        return mssv % 11;
    }

    // put  
    void put(int mssv, string fullname)
    {
            int key = hashKey(mssv);
            if(bucket[key].count(mssv) == 0)
                bucket[key].emplace(mssv, fullname);
    }
    // remove
    void remove(int mssv)
    {
            int key = hashKey(mssv);
            bucket[key].erase(mssv);
    }
    // get
    string get(int mssv)
    {
        int key = hashKey(mssv);
        if(bucket[key].count(mssv) > 0)
            return bucket[key][mssv];
        return "Not exist";
    }

};



int main()
{
    Student list;
    list.put(1, "NV Dung");
    list.put(2, "NT Ha");
    list.put(3, "NQ Anh");
    list.put(12, "NV Hung");
    cout << list.get(11);
}

