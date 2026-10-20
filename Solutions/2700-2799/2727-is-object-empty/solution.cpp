/**
 * Problem: Is Object Empty (2727)
 * Link: https://leetcode.com/problems/is-object-empty/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function (obj) {
    for (const x in obj) {
        return false;
    }
    return true;
};
