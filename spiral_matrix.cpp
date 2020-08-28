#include <iostream>
using namespace std;
int main()
{
	int row = 3, col = 4;
	int A[3][4] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12}};
	cout << "spiral form: ";
	int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int i = 0, j = 0, i_next, j_next, dir = 0, count = 0;
	while (count < row * col)
	{
		cout << A[i][j] << " ";
		A[i][j] = -1;
		i_next = i + D[dir][0], j_next = j + D[dir][1];
		if (i_next < 0 || j_next < 0 || j_next >= col || i_next >= row || A[i_next][j_next] == -1)
		{
			dir = (dir + 1) % 4;
			i_next = i + D[dir][0], j_next = j + D[dir][1];
		}
		i = i_next, j = j_next;
		count++;
	}
	cout << "\n";
}
/*
i/p (A):
1	2	3	4
5	6	7	8
9	10	11	12

o/p:
spiral form: 1 2 3 4 8 12 11 10 9 5 6 7
*/