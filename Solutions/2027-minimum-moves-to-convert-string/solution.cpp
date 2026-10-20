/**
 * Problem: Minimum Moves to Convert String (2027)
 * Link: https://leetcode.com/problems/minimum-moves-to-convert-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minimumMoves(string s) {
	int i = 0, n = s.length(), count = 0;
	while (i < n) {
		if (s[i] == 'O')  
			i++;
		else
			count++, i += 3; 
	}
	return count;
}
};
