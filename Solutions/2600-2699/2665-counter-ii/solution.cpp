/**
 * Problem: Counter II (2665)
 * Link: https://leetcode.com/problems/counter-ii/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let i = init;
    return{
        increment(){
            return ++i;
        },
        decrement(){
            return --i;
        },
        reset(){
            return i=init;
        }
    }


};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
