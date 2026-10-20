/**
 * Problem: Counter (2620)
 * Link: https://leetcode.com/problems/counter/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
