#include <iostream>
using namespace std;
int main()
{
	//custom array or vector input (2D)
	int row = 3, col = 4;
	int A[3][4] = { {1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12} };
	cout << "spiral form: ";
	//direction array -> decides the shift in i,j direction
	//right: 0,+1	down: +1,0	left: 0,-1	top: -1,0
	int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	//i, j are iteration variables for row and column
	//i_next, j_next are the next possible values for i, j
	//dir is the direction: 0 for right, 1 for down, 2 for left and 3 for up
	//count is the counter variable
	int i = 0, j = 0, i_next, j_next, dir = 0, count = 0;
	//loop eliminates when count is equal to number of elements, i.e. #rows * #columns
	while (count < row * col)
	{
		//print element
		cout << A[i][j] << " ";
		//traversed element is marked as visited, -1 or 0 or other special character
		A[i][j] = -1;
		//evaluate next values of i,j
		i_next = i + D[dir][0], j_next = j + D[dir][1];
		//check if the values fall within the ranges
		if (i_next < 0 || j_next < 0 || j_next >= col || i_next >= row || A[i_next][j_next] == -1)
		{
			dir = (dir + 1) % 4; //rotation occurs between 0,1,2,3 -> four directions
			i_next = i + D[dir][0], j_next = j + D[dir][1]; //re-evaluate
		}
		//next values assigned to i,j
		i = i_next, j = j_next;
		//counter variable incremented
		count++;
	}
	cout << "\n";
}
/*
o/p:
spiral form: 1 2 3 4 8 12 11 10 9 5 6 7
*/
