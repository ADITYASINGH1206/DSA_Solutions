/**
 * Problem: Sleep (2621)
 * Link: https://leetcode.com/problems/sleep/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(r => setTimeout(r, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
