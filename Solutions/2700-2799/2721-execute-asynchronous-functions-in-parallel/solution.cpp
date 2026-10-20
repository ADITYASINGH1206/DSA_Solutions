/**
 * Problem: Execute Asynchronous Functions in Parallel (2721)
 * Link: https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise<T[]>((resolve, reject) => {
        let cnt = 0;
        const ans = new Array(functions.length);
        for (let i = 0; i < functions.length; ++i) {
            const f = functions[i];
            f()
                .then(res => {
                    ans[i] = res;
                    cnt++;
                    if (cnt === functions.length) {
                        resolve(ans);
                    }
                })
                .catch(err => {
                    reject(err);
                });
        }
    });
}

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
