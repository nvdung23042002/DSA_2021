// EX3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* father;

    Node()
    {
       left = NULL;
       right = NULL;
       father = NULL;
    }
};

struct Tree
{
    Node* root;

    Tree()
    {
        root = NULL;
    }
    void insert(int x, Node*& t)
    {
        if (t->left == NULL and t->right == NULL)
        {
            Node* temp = new Node();
            temp->data = x;
            t->left = temp;
            Node* p = t->left;
            p->father = t;
            while (p->father != NULL)
            {
                if (p->data > p->father->data)
                {
                    int index = p->data;
                    p->data = p->father->data;
                    p->father->data = index;
                }
                p = p->father;
            }
        }
        else
        {
            if (t->right == NULL)
            {
                Node* temp = new Node();
                temp->data = x;               
                t->right = temp;
                Node* p = t->right;
                p->father = t;
                while (p->father != NULL)
                {
                    if (p->data > p->father->data)
                    {
                        int index = p->data;
                        p->data = p->father->data;
                        p->father->data = index;
                    }
                    p = p->father;
                }
            }
            else
            {
                if (t->left->left == NULL or t->left->right == NULL) insert(x, t->left);
                else insert(x, t->right);
            }
 
        }
    }
    void print(Node* t)
    {
        if (t != NULL)
        {
            print(t->left);
            cout << t->data << " ";            
            print(t->right);
        }
    }
};
int main()
{
    Tree* a = new Tree;
    Node* temp = new Node;
    temp->data = 1;
    a->root = temp;
    a->insert(3, a->root);
    a->insert(2, a->root);
    a->insert(5, a->root);
    a->print(a->root);
}

