/**
 * Problem: Drop Duplicate Rows (2882)
 * Link: https://leetcode.com/problems/drop-duplicate-rows/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

import pandas as pd


def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset=['email'])
