/*
TCS CodeVita9 (2020) Round 1 Problem
Path Through Graph

You are given two natural numbers.
Imagine these natural numbers as nodes on a graph.
On this graph, a number is connected to its largest factor other than itself.
You have to find the shortest path between them.
If the two numbers do not have any common factor, then construct a path through 1.

Ex 1: Input: 16 4
Since we know that largest factor of 16 other than itself is 8.
Largest factor of 8 other than itself is 4. That’s the other input number, so
we will stop here.
Output: 16 <--> 8 <--> 4

Ex 2: Input: 15689 28
Since we know that largest factor of 15689 other than itself is 541.
Since 541 is a prime number, it’s largest factor other than itself is 1.
For number 28, it’s largest factor other than itself is 14.
Largest factor of 14, other than itself is 7.
Since 7 is a prime number, it’s largest factor other than itself is 1.
Output: 15689 <--> 541 <--> 1 <--> 7 <--> 14 <--> 28
*/
#include <bits/stdc++.h>
using namespace std;
//input (x,y) example: (72,6) or (6,72)
vector<int> path_between(int x, int y)
{
	//keep x>y
	//(6,72) becomes (72,6)
	if (x < y)
		swap(x, y);
	//graph for x factors
	vector<int> graph;
	graph.emplace_back(x);
	bool prime, done = false; //prime = if number is prime\
							done=if graph complete (optional)
	while (x != 1)
	{
		prime = true;
		if (x == y) //y is one of the nodes
		{
			done = true;
			break;
		}
		//finding largest factor other than number itself
		for (int i = 2; i <= (int)sqrt(x); i++)
		{
			if (x % i == 0)
			{
				prime = false;
				x /= i;
				graph.emplace_back(x);
				break;
			}
		}
		if (prime)
		{
			x = 1;
			graph.emplace_back(x);
			break;
		}
	}
	if (done) //y occurs in the graph already
		return graph;
	//graph: 72 -> 36 -> 18 -> 9 -> 3 -> 1
	//graph for y factors
	vector<int> graph2;
	graph2.emplace_back(y);
	//same process as graph for x
	while (y != 1)
	{
		prime = true;
		for (int i = 2; i <= (int)sqrt(y); i++)
		{
			if (y % i == 0)
			{
				prime = false;
				y /= i;
				graph2.emplace_back(y);
				break;
			}
		}
		if (prime)
			break; //1 is not inserted as already available\
					in previous graph
	}
	//graph2: 6 -> 3
	//reverse graph for y
	reverse(graph2.begin(), graph2.end());
	//graph2 reversed: 3 -> 6
	graph.insert(graph.end(), graph2.begin(), graph2.end());
	//graph = (graph)->(graph2 reversed)\
		i.e. (72 -> 36 -> 18 -> 9 -> 3 -> 1) -> (3 -> 6)\
			graph2 reversed and appended to end of graph
	return graph;
}
int main()
{
	int a, b;
	cout << "enter 1st num: ";
	cin >> a;
	cout << "enter 2nd num: ";
	cin >> b;
	vector<int> graph = path_between(a, b);
	for (auto i = graph.begin(); i != graph.end(); i++)
	{
		if (i + 1 != graph.end())
			cout << *i << " <--> ";
		else
			cout << *i;
	}
	//for original problem, #edges required\
	#edges=#nodes-1, i.e. cout<<graph.size()-1
}
//output: 72 <--> 36 <--> 18 <--> 9 <--> 3 <--> 1 <--> 3 <--> 6
//original o/p: 7