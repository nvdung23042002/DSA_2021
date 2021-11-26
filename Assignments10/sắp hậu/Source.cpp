#include <iostream>
#include <math.h>
using namespace std;
int a[1000];
int dem = 0;
bool check_postition(int x, int y)
{
	for (int i = 1; i < x; i++)
	{
		if ((a[i] == y) || (abs(i - x) == abs(a[i] - y)))
			return false;
	}
	return true;
}

void display(int n)
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void thu(int k, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (check_postition(k, i) == true)
		{
			a[k] = i;

			if (k == n)
			{
				/*display(n);*/
				dem++;
			}
			thu(k + 1, n);
		}
	}

}

int main()
{
	int n;
	cin >> n;
	thu(1, n);
	cout << dem;
	return 0;
}