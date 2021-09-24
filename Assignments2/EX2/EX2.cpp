// EX2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* pre;

    Node()
    {
        val = 0;
        pre = NULL;
        next = NULL;
    }
};

struct DouList
{
    Node* head;
    Node* tail;

    DouList()
    {
        head = NULL;
        tail = NULL;
    }

    Node* CreateNode(int x)
    {
        Node* newnode = new Node;
        newnode->val = x;
        newnode->next = NULL;
        newnode->pre = NULL;
        return newnode;
    }

    void addLast(int x)
    {
        Node* newnode = CreateNode(x);
        if (tail == NULL)
        {
            tail = newnode;
            head = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->pre = tail;
            tail = newnode;
        }

    }
    //
    void print()
    {
        for (Node* p = head; p != NULL; p = p->next)
        {
            cout << p->val << " ";
        }
        cout << endl;
    }
    //
    Node* get_pos(int p)
    {
        Node* q = head;
        while(p > 0)
        {
            p--;
            q = q->next;
            if (p == 1)
                return q;
        }
    }
    //
    void insert(int p, int x)
    {    
        Node* newnode = CreateNode(x);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node* pos = get_pos(p);
            if (pos == head)
            {
                pos->pre = newnode;
                newnode->next = pos;
                head = newnode;
            }
            else
            {
                pos->pre->next = newnode;
                newnode->pre = pos->pre;
                newnode->next = pos;
                pos->pre = newnode;
            }
        }
        
    }
    //
    void del(int p)
    {
        Node* del = get_pos(p);
        del->next->pre = del->pre;
        del->pre->next = del->next;
        delete del;
    }
    //
    int EX3()
    {
        Node* p = head->next;
        int count = 0;
        for (p; p->next != NULL; p = p->next)
        {
            if (p->val + p->pre->val + p->next->val == 0)
                count++;
        }
        return count;
    }
};

int main()
{
    DouList list;
    while (true)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        list.addLast(x);
    }
    /*int p;
    cin >> p;*/
    /*int x;
    cin >> x;
    list.insert(p, x);*/
    /*list.del(p);*/
    list.print();
    cout << list.EX3();
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
