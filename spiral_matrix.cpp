#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
	cout<<"spiral form: ";
	const array<array<int,2>,4> D{{{0,1},{1,0},{0,-1},{-1,0}}};
	int i=0,j=0,i_next,j_next;
	int dir=0,count=0;
	while(count<A.size()*A.size())
	{
		cout<<A[i][j]<<" ";
		A[i][j]= -1;
		i_next=i+D[dir][0],j_next=j+D[dir][1];
		if(i_next<0 || j_next<0 || j_next>=A.size() || A[i_next][j_next]== -1)
		{
			dir=(dir+1)%4;
			i_next=i+D[dir][0],j_next=j+D[dir][1];
		}
		i=i_next,j=j_next;
		count++;
	}
}

/*
input (A):
1 2 3
4 5 6
7 8 9

output:
spiral form: 1 2 3 6 9 8 7 4 5
*/
