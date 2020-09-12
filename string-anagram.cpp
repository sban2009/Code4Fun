// Check if two strings are anagrams
#include <iostream>
//#include <chrono> //uncomment for time
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
//using namespace std::chrono;

// brute force
bool anagram1(string s1, string s2) // O(n log n)
{
	sort(s1.begin(), s1.end()); // O(n logn)
	sort(s2.begin(), s2.end());
	return (s1 == s2); // O(n)
}

// hash map (for finite character sets)
typedef unordered_map<char, unsigned int> hashmap;
bool anagram2(string s1, string s2) // O(n)
{
	hashmap string_rep;
	// increment frequency count for string 1 chars
	for (unsigned int i = 0; s1[i]; i++) // O(n)
	{
		if (!string_rep.count(s1[i])) //O(1)
			string_rep[s1[i]] = 1;
		else
			string_rep[s1[i]]++;
	}
	// decrement frequency for each char in string 2
	for (unsigned int i = 0; s2[i]; i++) // O(n)
	{
		if (!string_rep.count(s2[i])) //O(1)
			return false;			  // not present in map
		else
			string_rep[s1[i]]--;
	}
	//search for non-zero values
	for (auto i : string_rep) // O(n)
	{
		if (i.second)
			return false;
	}
	return true;
}
int main()
{
	string s1, s2; //case sensitive
	cin >> s1 >> s2;
	//auto start = high_resolution_clock::now();
	if (s1.length() != s2.length())
		cout << "not anagram";
	if (anagram1(s1, s2)) //replace X by 1 or 2
		cout << "anagram";
	else
		cout << "not anagram";
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cerr << "\ntime (µs): " << duration.count();
	return 0;
}
/*
output with example:
car acr  => anagram
car rcaa => not anagram

algo1:
car --sorted--> acr
rca --sorted--> acr == acr
rcaa --sorted--> aacr != acr

algo2:
map+(car): (c->1,a->1,r->1)
map-(rca): (c->0,a->0,r->0) => all zero
map-(rcaa): (r->0,c->0,a->-1) => non-zero present
*/