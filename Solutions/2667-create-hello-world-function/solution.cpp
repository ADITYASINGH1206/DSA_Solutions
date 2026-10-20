/**
 * Problem: Create Hello World Function (2667)
 * Link: https://leetcode.com/problems/create-hello-world-function/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
