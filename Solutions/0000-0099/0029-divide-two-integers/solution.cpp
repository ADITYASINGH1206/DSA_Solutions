/**
 * Problem: Divide Two Integers (29)
 * Link: https://leetcode.com/problems/divide-two-integers/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    let q = dividend/divisor
    let result = q > 0 ? Math.floor(q) : Math.ceil(q)
    if (result <= -2147483648) {
        result = -2147483648;
    } else if (result >= 2147483647) {
        result = 2147483647;
    }    
    return result;
    
};
