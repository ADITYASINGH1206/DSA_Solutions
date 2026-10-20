/**
 * Problem: Create a DataFrame from List (2877)
 * Link: https://leetcode.com/problems/create-a-dataframe-from-list/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

import pandas as pd


def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])
