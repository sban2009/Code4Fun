/*
TCS CodeVita9 (2020) Round 1 Problem
Path Through Graph

You are given two natural numbers.
Imagine these natural numbers as nodes on a graph.
On this graph, a number is connected to its largest factor other than itself.
You have to find the #edges in the shortest path between them.
If the two numbers do not have any common factor, then construct a path through 1.

Ex 1: 16 4
Since we know that largest factor of 16 other than itself is 8.
Largest factor of 8 other than itself is 4. That’s the other input number, so
we will stop here.
16 <--> 8 <--> 4
Ans: 2

Ex 2: 15689 28
Since we know that largest factor of 15689 other than itself is 541.
Since 541 is a prime number, it’s largest factor other than itself is 1.
For number 28, its largest factor other than itself is 14.
Largest factor of 14, other than itself is 7.
Since 7 is a prime number, its largest factor other than itself is 1.
15689 <--> 541 <--> 1 <--> 7 <--> 14 <--> 28
Ans: 5
*/
#include <bits/stdc++.h>
using namespace std;
int factor(int n)
{
	for (int i = 2; i * i <= n; i++) //finding largest factor other than number itself
	{
		if (n % i == 0) // divide by lowest prime factor and return
			return n / i;
	}
	return 1; // number is prime
}
int main()
{
	int x, y;
	cout << "enter 1st num: ";
	cin >> x;
	cout << "enter 2nd num: ";
	cin >> y;
	if (x < y) // keeping first number larger
		swap(x, y);
	if (x == y) // numbers are equal. no edges
	{
		cout << 0;
		return 0;
	}
	map<int, int> graph; // stores x factors, with #edges
	bool done = false;
	int c = 0;
	while (x != 1) // x not prime
	{
		c++;
		x = factor(x);
		graph[x] = c; // insert <node,#edges>
		if (x == y)	  // no need to travel further
		{
			done = true;
			break;
		}
	}
	if (done) // y is in x factors
	{
		cout << "#edges: " << graph[y] << "\n";
		return 0;
	}
	// ^ this will reduce #operations in cases where y is very close to x
	c = 0;
	while (!graph.count(y)) // y not present in graph
	{
		c++;
		y = factor(y);
	}
	// #total edges = #(x factors till y link) + #(y link to y)
	cout << "#edges: " << graph[y] + c << "\n";
	return 0;
}
/*
example: 
enter 1st num: 54
enter 2nd num: 36
#edges: 4

explanation:
map looks like
27: 1, 9: 2, 3: 3, 1: 4
#edges in x graph = 4
54 <--> 27 <--> 9 <--> 3 <--> 1

when finding factors of 36, 9 is common
the loop runs as:
36 not in graph-> c=1, 18 not in graph-> c=2, 9 in graph. terminated.
#edges in y graph = c = 2
36<-->18<-->9

#edges in total graph = #edges till 9 in x graph + #edges in y graph
= map(9) + 2
= 2 + 2
= 4
54 <--> 27 <--> 9 <--> 18 <--> 36
*/
