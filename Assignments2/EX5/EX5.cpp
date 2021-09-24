// EX5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct stack
{
	int arr[10] = { 1,2,3 };
	int size = 0;
	int x;

	void push(int x)
	{
		arr[size] = x;
		size++;
	}

	void pop()
	{
		if (size == 0)
			cout << "EMPTY";
		size--;
	}
	
	void print()
	{
		for (int i = 0; i <= size - 1; i++)
			cout << arr[i] <<" ";
	}
};

int main()
{
	stack no1;
	while (true)
	{
		int x;
		cin >> x;
		if (x == 0)
			break;
		else
			no1.push(x);
	}
	no1.pop();
	no1.pop();
	no1.pop();
	no1.print();
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
