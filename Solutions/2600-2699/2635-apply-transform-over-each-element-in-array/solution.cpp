/**
 * Problem: Apply Transform Over Each Element in Array (2635)
 * Link: https://leetcode.com/problems/apply-transform-over-each-element-in-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }   
    return arr;
};
