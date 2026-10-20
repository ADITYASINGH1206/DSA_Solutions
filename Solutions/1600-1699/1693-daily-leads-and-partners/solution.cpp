/**
 * Problem: Daily Leads and Partners (1693)
 * Link: https://leetcode.com/problems/daily-leads-and-partners/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
select date_id, make_name, count(distinct lead_id) as unique_leads, count(distinct partner_id) as unique_partners
from DailySales
group by date_id, make_name;
