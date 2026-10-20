/**
 * Problem: Interval Cancellation (2725)
 * Link: https://leetcode.com/problems/interval-cancellation/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

function cancellable(fn: Function, args: any[], t: number): Function {
    fn(...args);
    const time = setInterval(() => fn(...args), t);
    return () => clearInterval(time);
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 2
 *  const args = [4], t = 20, cancelT = 110
 *
 *  const log = (...argsArr) => {
 *      result.push(fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(fn, args, t);
 *
 *  setTimeout(() => {
 *     cancel()
 *     console.log(result) // [
 *                         //      {"time":0,"returned":8},
 *                         //      {"time":20,"returned":8},
 *                         //      {"time":40,"returned":8},
 *                         //      {"time":60,"returned":8},
 *                         //      {"time":80,"returned":8},
 *                         //      {"time":100,"returned":8}
 *                         //  ]
 *  }, cancelT)
 */
