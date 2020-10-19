/*
Demonstrate sliding window (in C)
Input: array A, window size k
Output: the max product of such k consecutive elements

e.g. A= 1 2 3 4 5, k= 3
output= 3*4*5 = 60
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int maxprod(int *, int, int);
void main()
{
	int n, *A, k, i;
	printf("enter array size: ");
	scanf("%d", &n);
	A = (int *)malloc(sizeof(int) * n);
	/*array input*/
	printf("enter array: ");
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	printf("enter window size: ");
	scanf("%d", &k);
	printf("max product: %d", maxprod(A, n, k));
}
int maxprod(int A[], int n, int k)
{
	int i = 0, prod = 1, maxprod = INT_MIN;
	/*initial window*/
	while (i < k)
		prod *= A[i++];
	/*sliding*/
	i = 0;
	while ((i + k - 1) < n)
	{
		if (prod > maxprod)
			maxprod = prod;
		/*divide by element not present\
		and multiply by new element*/
		prod = (prod / A[i]) * A[i + k];
		i++;
	}
	return maxprod;
}
/*
enter array size: 10
enter array: 1 3 -1 2 8 -4 16 3 1 1
enter window size: 4
max product: 64

explanation: for window with i=2
prod	= A[2]*A[3]*A[4]*A[5]
	=(-1)*2*8*(-4)
	= 64
*/
