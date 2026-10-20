/**
 * Problem: Return Length of Arguments Passed (2703)
 * Link: https://leetcode.com/problems/return-length-of-arguments-passed/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
