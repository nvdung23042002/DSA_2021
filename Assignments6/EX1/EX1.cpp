// EX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define MAX 11

int a[MAX] = { 2,1,10,6,3,8,7,13,20 };
int pos = 9;

void print()
{
	for (int i = 0; i < pos; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void selectionSort()
{
	for (int i = 0; i < pos; i++)
	{
		int min = a[i];
		int index = i;
		for (int j = i + 1; j < pos; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				index = j;
			}
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
}

void bubbleSort()
{
	for (int i = 0; i < pos - 1; i++)
	{
		for (int j = i + 1; j < pos ; j++)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

void insertSort()
{
	for (int i = 1; i < pos; i++)
	{
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0; --j)
		{
			if (temp < a[j])
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = temp;
	}
}

int main()
{
	insertSort();
	print();
}

