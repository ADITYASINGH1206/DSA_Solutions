/**
 * Problem: Fill Missing Data (2887)
 * Link: https://leetcode.com/problems/fill-missing-data/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0)
    return products
