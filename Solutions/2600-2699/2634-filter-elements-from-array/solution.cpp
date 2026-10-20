/**
 * Problem: Filter Elements from Array (2634)
 * Link: https://leetcode.com/problems/filter-elements-from-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans =[];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            ans.push(arr[i]);
        }
    }
    return ans;
};
