/**
 * Problem: Sort By (2724)
 * Link: https://leetcode.com/problems/sort-by/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (value: JSONValue) => number

function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
}
