/**
 * Problem: Roman to Integer (13)
 * Link: https://leetcode.com/problems/roman-to-integer/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {string} s
 * @return {number}
 */
const romanToInt = function (s) {
    const d = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };
    let ans = d[s[s.length - 1]];
    for (let i = 0; i < s.length - 1; ++i) {
        const sign = d[s[i]] < d[s[i + 1]] ? -1 : 1;
        ans += sign * d[s[i]];
    }
    return ans;
};
