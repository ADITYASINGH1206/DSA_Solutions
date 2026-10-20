/**
 * Problem: Drop Missing Data (2883)
 * Link: https://leetcode.com/problems/drop-missing-data/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

import pandas as pd


def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['name'].notnull()]
