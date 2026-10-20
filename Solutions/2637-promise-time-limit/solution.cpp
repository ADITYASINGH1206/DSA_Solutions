/**
 * Problem: Promise Time Limit (2637)
 * Link: https://leetcode.com/problems/promise-time-limit/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
    return async function (...args) {
        return Promise.race([
            fn(...args),
            new Promise((_, reject) => setTimeout(() => reject('Time Limit Exceeded'), t)),
        ]);
    };
}

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
