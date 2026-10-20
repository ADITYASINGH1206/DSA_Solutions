/**
 * Problem: Modify Columns (2884)
 * Link: https://leetcode.com/problems/modify-columns/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame: 
    employees['salary'] = employees['salary']*2
    return employees
