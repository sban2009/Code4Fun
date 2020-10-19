// Searching algorithms
// Linear, Binary, Interpolation

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Linear Search
bool linear(vi A, int key) // O(n)
{
	for (auto element : A)
	{
		if (element == key)
			return true;
	}
	return false;
}

// Binary Search
bool binary(vi A, int key) // O(log n)
{
	sort(A.begin(), A.end());
	int mid, start = 0, end = A.size() - 1;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (A[mid] == key)
			return true;
		else if (A[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}

// Interpolation Search
bool interpolation(vi A, int key) // O(log n), best: O(log log n)
{
	sort(A.begin(), A.end());
	int idx, start = 0, end = A.size() - 1;
	while (start <= end)
	{
		idx = start + (((end - start) / (A[end] - A[start])) * (key - A[start]));
		if (A[idx] == key)
			return true;
		else if (A[idx] > key)
			end = idx - 1;
		else
			start = idx + 1;
	}
	return false;
}
int main()
{
	int n, key;
	cout << "# elements: ";
	cin >> n;
	vi A(n);
	cout << "enter array: ";
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cout << "key: ";
	cin >> key;
	if (algo_name(A, key)) //algo_name replace by function name
		cout << "found";
	else
		cout << "not found";
}