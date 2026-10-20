/**
 * Problem: Flatten Deeply Nested Array (2625)
 * Link: https://leetcode.com/problems/flatten-deeply-nested-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    if (!n) {
        return arr;
    }
    const ans: MultiDimensionalArray = [];
    for (const x of arr) {
        if (Array.isArray(x) && n) {
            ans.push(...flat(x, n - 1));
        } else {
            ans.push(x);
        }
    }
    return ans;
};
