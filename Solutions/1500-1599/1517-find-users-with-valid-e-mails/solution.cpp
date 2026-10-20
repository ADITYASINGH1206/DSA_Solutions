/**
 * Problem: Find Users With Valid E-Mails (1517)
 * Link: https://leetcode.com/problems/find-users-with-valid-e-mails/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

SELECT 
    user_id, 
    name, 
    mail
FROM 
    users
WHERE 
    mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' 
    AND mail LIKE BINARY '%@leetcode.com';
