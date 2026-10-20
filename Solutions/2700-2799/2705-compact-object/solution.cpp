/**
 * Problem: Compact Object (2705)
 * Link: https://leetcode.com/problems/compact-object/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    return Object.entries(obj).reduce((acc, [key, value]) => {
        if (value) {
            acc[key] = compactObject(value);
        }
        return acc;
    }, {});
};
