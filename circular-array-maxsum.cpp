/*
Given an array arr[] of N integers arranged in a circular fashion.
To find: maximum contiguous subarray sum.
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
/*
we take the function maxprod (https://bit.ly/2Tj3zDE)
and modify it to be applicable for sum instead of product
code is less verbose so check original for details
*/
int maxsum(int A[], int n, int k = 1) /* k = window size in [1,n] */
{
	int start = 0, sum = 0, maxsum = INT_MIN;
	int end = start + k - 1;
	while (start <= end)
		sum += A[start++];
	start = 0;
	while (start < n)
	{
		if (sum > maxsum)
			maxsum = sum;
		/*printf("sum (win%d [%d,%d]) = %d\n", k, start, end, sum);*/
		if (end + 1 == n)
			end = -1;
		sum = (sum - A[start++]) + A[++end];
	}
	return maxsum;
}
int main()
{
	int n, *A, win, i, max, final_max = INT_MIN;
	printf("enter array size: ");
	scanf("%d", &n);
	A = (int *)malloc(sizeof(int) * n);
	/*array input*/
	printf("enter array: ");
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	/* loop for finding maximum sum */
	for (win = 1; win <= n; win++)
	{
		max = maxsum(A, n, win);
		/*printf("win %d maxsum = %d\n\n", win, max);*/
		if (max > final_max)
			final_max = max;
	}
	printf("max subaray sum: %d\n", final_max);
	return 0;
}
/*
Sample I/O:
enter array size: 7
enter array: 8 -8 9 -9 10 -11 12
max subaray sum: 22

Explanation: Starting from the last element of the array,
and moving in circular fashion, we have max subarray as
12, 8, -8, 9, -9, 10, which gives a maximum sum as 22.

Uncomment lines 24 and 45 for more detailed output
*/