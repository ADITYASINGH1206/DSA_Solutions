/**
 * Problem: Array Reduce Transformation (2626)
 * Link: https://leetcode.com/problems/array-reduce-transformation/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let ans = init;
    for(let i =0;i<nums.length;++i){
        ans = fn(ans,nums[i]);
    }
    return ans;
};
