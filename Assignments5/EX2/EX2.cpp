// EX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct Tree
{
    Node* root;
    // constructor
    Tree()
    {
        root = NULL;
    }
    // insert node
    void insert(int x, Node*& root)
    {
        if (root == NULL) {
            Node* temp = new Node;
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
        }
        else {
            if (x < root->data) {
                insert(x, root->left);
            }
            else {
                insert(x, root->right);
            }
        }
    }
    //check leaf
    bool isLeaf(Node* t)
    {
        if (t->left == NULL and t->right == NULL)
            return true;
        return false;
    }
    void del(int x, Node*& t)
    {
        if (t != NULL)
        {
            if (t->data == x)
            {
                if (isLeaf(t))
                {
                    t = NULL;
                    delete t;
                }
                else
                {
                    if (t->left == NULL)
                    {
                        t = t->right;
                    }
                    else if (t->right == NULL)
                    {
                        t = t->left;
                    }
                }
            }
            else
            {
                if (x < t->data) {
                    del(x, root->left);
                }
                else {
                    del(x, t->right);
                }
            }
        }
    }
    //goc-trai-phai
    void preOder(Node* t)
    {
        if (t != NULL)
        {
            cout << t->data << " ";
            preOder(t->left);
            preOder(t->right);
        }
    }
};

int main()
{
    Tree* da = new Tree;
    da->insert(2, da->root);
    da->insert(1, da->root);
    da->insert(10, da->root);
    da->insert(6, da->root);
    da->insert(3, da->root);
    /*da->insert(8, da->root);
    da->insert(7, da->root);
    da->insert(13, da->root);
    da->insert(20, da->root);*/
    da->del(10, da->root);
    da->preOder(da->root);
    cout << endl;
    /*da->insert(14, da->root);
    da->insert(0, da->root);
    da->insert(35, da->root);
    da->preOder(da->root);*/
}

