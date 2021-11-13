// Graphs1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void NhapMang(vector<vector<int>>& a)
{
	int dong;
	cout << "\nNhap vao so phan tu: ";
	cin >> dong;
	a.resize(dong + 1);

	for (int i = 1; i <= dong; i++)
	{
		int cot;
		cout << "\nNhap vao so phan tu lien ke " << i << ": ";
		cin >> cot;
		a[i].resize(cot + 1);
		for (int j = 1; j <= cot; j++)
		{
			cout << "\nNhap vao a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}


bool notExist(vector <int> b, int idx)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == idx)
			return false;
	}
	return true;
}
void BFS(vector<vector<int>> a)
{
	int k;
	cin >> k;
	vector <int> pr;
	int i = 0;
	pr.push_back(k);
	while (i < pr.size())
	{
		int length = a[pr[i]].size();
		for (int j = 1; j < length; j++)
		{
			if (notExist(pr, a[pr[i]][j]))
			{
				pr.push_back(a[pr[i]][j]);
			}
		}
		i++;
	}
	for (int j = 0; j < pr.size(); j++)
	{
		cout << pr[j] << setw(4);
	}
}

void DFS(vector<vector<int>> a, vector <int> &dfs, int k)
{
		dfs.push_back(k);
		int cot = a[k].size();
		for (int i = 1; i < cot; i++)
		{
			if (notExist(dfs,a[k][i]))
			{
				DFS(a, dfs, a[k][i]);
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<int>> a; // Khai báo vector 2 chiều.
	NhapMang(a);
	/*BFS(a);*/
	vector <int> dfs;
	DFS(a, dfs, 3);
	for (int i = 0; i < dfs.size(); i++)
		cout << dfs[i] << setw(4);
	cout << endl;
	system("pause");
	return 0;
}