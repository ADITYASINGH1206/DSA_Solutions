/**
 * Problem: Maximum Number of Words Found in Sentences (2114)
 * Link: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @param {string[]} sentences
 * @return {number}
 */
var mostWordsFound = function(sentences) {
    return Math.max(...sentences.map(s => s.split(" ").length)) 
};
