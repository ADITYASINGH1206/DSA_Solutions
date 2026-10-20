/**
 * Problem: Reshape Data: Concatenate (2888)
 * Link: https://leetcode.com/problems/reshape-data-concatenate/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

import pandas as pd


def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2], ignore_index=True)
