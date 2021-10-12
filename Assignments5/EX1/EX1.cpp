// EX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* firstChild;
    Node* nextSibling;
};

struct Tree
{
    Node* root;
    Tree()
    {
        root = NULL;
    }

    void insert(int m, int x, Node*& t) {
        if (t != NULL)
        {
            if (t->data == m)
            {
                Node* temp = new Node;
                temp->data = x;
                temp->firstChild = NULL;
                temp->nextSibling = NULL;
                if (t->firstChild == NULL)
                    t->firstChild = temp;
                else
                {
                    for (Node* p = t->firstChild; p != NULL; p = p->nextSibling)
                    {
                        if (p->nextSibling == NULL)
                        {
                            p->nextSibling = temp;
                            break;
                        }
                    }
                }
            }
            else
            {
                insert(m, x, t->firstChild);
                insert(m, x, t->nextSibling);
            }
        }
       
    }
    void preOder(Node* t)
    {
        if (t != NULL)
        {
            cout << t->data << " ";
            preOder(t->firstChild);
            preOder(t->nextSibling);
        }
    }
    //Post oder
    void postOder(Node* t)
    {
        postOder(t->firstChild);
        cout << t->data << " ";
        preOder(t->nextSibling); 
    }
};

int main()
{
    Tree* a = new Tree;
    Node* temp = new Node;
    temp->data = 1;
    temp->firstChild = NULL;
    temp->nextSibling = NULL;
    a->root = temp;
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a->insert(x, y, a->root);
    }
    a->preOder(a->root);
}

