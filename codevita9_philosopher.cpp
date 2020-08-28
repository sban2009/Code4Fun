/*
TCS CodeVita Season 9 (2020) Problem
It is known that Philosopher's Stones break apart into an odd number of shards when they're used up. After searching far and wide, Edgar has collected N shards of what he believes to be a previously-used Philosopher's Stone, where N is an odd integer. He believes that fusing these shards back together will yield a real stone in its entirety. Leveraging his encyclopedic knowledge of alchemy, Edgar recalls an ancient book with the following ritual for fusing shards:
1. Arrange the N shards in a row, numbered from 1 to N
2. Note the colour C(i) of each shard i, which is either auburn or black (denoted by the characters 'A' and 'B' respectively).
3. Choose a consecutive sequence of three shards, remove them from the row, and fuse them together into one new shard. The three shards must not all be the same colour, or such an intense concentration of similar energies will cause a dangerous rebound explosion. Instead, there must be two differently-coloured shards that will neutralize each other, get converted into energy (via the Law of Equivalent Exchange), and become infused with the third shard. In other words, assuming no explosion, the resulting shard's colour will be equal to the most common colour present amongst the three chosen shards.
4. Place the resulting shard back into the original gap in the row, with the remaining shards in the same relative order before and after it.
5. Repeat steps 3 and 4 until only one shard remains.
Note that each time steps 3 and 4 are performed, the number of remaining shards decreases by 2. Therefore, given that the initial number of shards is odd, enough successful repetitions will result in exactly one final shard: the Philosopher's Stone. Help Edgar determine whether or not it's possible to get to that point and hopefully save Alfred, without causing any rebound explosions along the way.

Input: Begins with an integer TT, the number of Philosopher's Stones that Edgar tries to reconstitute. For each stone there are two lines. The first contains the integer N. The second contains the length-N string C[1..N]

Output: "Y" if it's possible For Edgar to end up with the Philosopher's Stone, or "N" if not.
*/
#include <bits/stdc++.h>
using namespace std;
short val(char c) // value of shard
{
	if (c == 'A')
	{
		return 1; // +1 for A
	}
	else
	{
		return -1; // -1 for B
	}
}
bool philosopher(string S) // returns true if stone creation possible, else false
{
	short energy = 0, count;
	do
	{
		if (S.length() % 2 == 0)
		{
			return false;
		}
		count = 0;
		for (int k = 1; k < S.length() - 1; k++)
		{
			energy = val(S[k - 1]) + val(S[k]) + val(S[k + 1]);
			if (energy == 1 || energy == -1)
			{
				count++;
				if (energy == 1)
				{
					S = S.substr(0, k - 1) + 'A' + S.substr(k + 2);
				}
				else
				{
					S = S.substr(0, k - 1) + 'B' + S.substr(k + 2);
				}
			}
		}
	} while (S.length() > 1 && count > 0);
	if (S.length() == 1)
		return true;
	return false;
}
int main()
{
	int N; //no. of shards or string length
	cin >> N;
	string S; //string consisting of A and B
	cin >> S;
	if (philosopher(S))
		cout << "Y\n";
	else
		cout << "N\n";
}
