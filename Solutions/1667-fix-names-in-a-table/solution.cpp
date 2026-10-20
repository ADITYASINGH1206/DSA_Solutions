/**
 * Problem: Fix Names in a Table (1667)
 * Link: https://leetcode.com/problems/fix-names-in-a-table/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

select user_id, concat(upper(substring(name,1,1)),lower(substring(name,2))) as name
from users
order by user_id
