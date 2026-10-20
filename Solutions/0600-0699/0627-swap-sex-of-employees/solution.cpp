/**
 * Problem: Swap Sex of Employees (627)
 * Link: https://leetcode.com/problems/swap-sex-of-employees/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

UPDATE salary SET sex =
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;
