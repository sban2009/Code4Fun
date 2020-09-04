#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate(const vector<vector<int>> A, int m, int n, int dir = 0) //brute force O(m*n) t&s
{
	array<array<int, 2>, 2> shift = {{{+1, -1},
									  {-1, +1}}};
	vector<vector<int>> B(m, vector<int>(n, 0));
	int i_b, j_b, i_re;
	if (dir == 0) //clock
	{
		i_b = 0, j_b = n - 1;
		i_re = 0;
	}
	else //anti
	{
		i_b = m - 1, j_b = 0;
		i_re = m - 1;
	}
	int i_sh = shift[dir][0], j_sh = shift[dir][1];
	for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
			B[i_b][j_b] = A[i][j];
			i_b += i_sh;
		}
		j_b += j_sh, i_b = i_re;
	}
	return B;
}
void print(vector<vector<int>> A)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	int m, n, ch = 0;
	cout << "#rows: ";
	cin >> m;
	cout << "#columns: ";
	cin >> n;
	vector<vector<int>> A(m, vector<int>(n));
	cout << "enter matrix:\n";
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			cin >> A[i][j];
		}
	}
	do
	{
		cout << "1. clockwise 2. anti-clockwise 3. print\nenter choice (0 to exit): ";
		cin >> ch;
		switch (ch)
		{
		case 0:
			return 0;
		case 1:
			A = rotate(A, m, n, 0); //clockwise
			break;
		case 2:
			A = rotate(A, m, n, 1); //counter-clockwise
			break;
		case 3:
			print(A);
			break;
		default:
			cout << "wrong choice entered!\n";
			break;
		}
	} while (ch != 0);
	return 1;
}
/*
input/output:

#rows: 3
#columns: 3
enter matrix:
1 2 3
4 5 6
7 8 9
1. clockwise 2. anti-clockwise 3. print
enter choice (0 to exit): 1
1. clockwise 2. anti-clockwise 3. print
enter choice (0 to exit): 3
7 4 1 
8 5 2 
9 6 3 
1. clockwise 2. anti-clockwise 3. print
enter choice (0 to exit): 2
1. clockwise 2. anti-clockwise 3. print
enter choice (0 to exit): 3
1 2 3 
4 5 6 
7 8 9 
1. clockwise 2. anti-clockwise 3. print
enter choice (0 to exit): 0
*/