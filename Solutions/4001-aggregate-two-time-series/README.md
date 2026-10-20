# [4001. Aggregate Two Time Series](https://leetcode.com/problems/aggregate-two-time-series/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`

---

## Problem Description
You are given two 2D integer arrays `series1` and `series2`.

Each element in both series is of the form `[timestamp, value]`, where:

* `timestamp` is an integer representing the time.
* `value` is an integer representing the value at that timestamp.

Each array is sorted in strictly increasing order of `timestamp`.

For any timestamp **not present** in a series, its value is taken from the **next available timestamp** in the same series if one exists. Otherwise, its value is considered 0.

The **aggregated series** is formed by summing the corresponding values from both series at every timestamp that appears in either series.

Return the **aggregated series** as a 2D integer array of `[timestamp, summedValue]` pairs, sorted in **strictly increasing** order of timestamp.

**Example 1:**

**Input:** series1 = [[1,3],[4,1]], series2 = [[2,2],[5,2]]

**Output:** [[1,5],[2,3],[4,3],[5,2]]

**Explanation:**

| Timestamp | `series1` | `series2` | `summedValue` |
| --- | --- | --- | --- |
| 1 | 3 | 2 | 5 |
| 2 | 1 | 2 | 3 |
| 4 | 1 | 2 | 3 |
| 5 | 0 | 2 | 2 |

Thus, the aggregated series is `[[1, 5], [2, 3], [4, 3], [5, 2]]`.

**Example 2:**

**Input:** series1 = [[1,5],[3,1]], series2 = [[2,2]]

**Output:** [[1,7],[2,3],[3,1]]

**Explanation:**

| Timestamp | `series1` | `series2` | `summedValue` |
| --- | --- | --- | --- |
| 1 | 5 | 2 | 7 |
| 2 | 1 | 2 | 3 |
| 3 | 1 | 0 | 1 |

Thus, the aggregated series is `[[1, 7], [2, 3], [3, 1]]`.

**Example 3:**

**Input:** series1 = [[1,5]], series2 = [[1000000000,2]]

**Output:** [[1,7],[1000000000,2]]

**Explanation:**

At timestamp 1, the next available value in `series2` is 2 at timestamp 1000000000. At timestamp 1000000000, there is no later timestamp in `series1`, so its value is 0. Only timestamps that appear in at least one of the two series are included.

**Constraints:**

* `1 <= series1.length, series2.length <= 105`
* `series1[i].length == series2[i].length == 2`
* `1 <= series1[i][0], series2[i][0] <= 109`
* `1 <= series1[i][1], series2[i][1] <= 109`
* Each series is sorted in strictly increasing order of `timestamp`.

---

## Solution & Editorial
# Intuition
The problem requires aggregating values from two sorted time series. Since both series are already sorted by timestamp, we can use a two-pointer approach to traverse both arrays simultaneously. The key observation is that for any timestamp, if a value is missing in one series, it takes the value of the *next* available timestamp in that series, which is exactly what the current pointer in that series points to.

# Approach
1. Initialize two pointers `i` and `j` at the start of `series1` and `series2` respectively.
2. Iterate while both pointers are within bounds:
   - If `series1[i][0] == series2[j][0]`, the timestamp is common; sum both values and increment both pointers.
   - If `series1[i][0] < series2[j][0]`, the current timestamp is from `series1`. The value for `series2` at this time is the value at `series2[j][1]` (the next available value). Sum them and increment `i`.
   - If `series1[i][0] > series2[j][0]`, the current timestamp is from `series2`. The value for `series1` at this time is the value at `series1[i][1]`. Sum them and increment `j`.
3. After one series is exhausted, append the remaining elements of the other series to the result.

### Visual Trace (Example 1)
`series1 = [[1,3],[4,1]]`, `series2 = [[2,2],[5,2]]`

| Step | i | j | Time | series1[i][1] | series2[j][1] | Sum | Result |
|---|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 1 | 3 | 2 | 5 | [[1,5]] |
| 2 | 1 | 0 | 2 | 1 | 2 | 3 | [[1,5],[2,3]] |
| 3 | 1 | 1 | 4 | 1 | 2 | 3 | [[1,5],[2,3],[4,3]] |
| 4 | 2 | 1 | 5 | - | 2 | 2 | [[1,5],[2,3],[4,3],[5,2]] |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `series1` and `series2`. We traverse each array exactly once.
- Space complexity: $$O(N + M)$$ to store the aggregated result.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        int m = series1.size();
        int n = series2.size();
        int i =0 ,j=0;
        while(i<m && j<n){
            int sum = 0;
            int time = 0;
            if(series1[i][0]==series2[j][0]){
                time = series1[i][0];
                sum=series1[i][1]+series2[j][1];
                i++;
                j++;
            }else if(series1[i][0]<series2[j][0]){
                time = series1[i][0];
                sum=series1[i][1] + series2[j][1];
                i++;
            }else{
                time = series2[j][0];
                sum=series2[j][1]+series1[i][1];
                j++;
            }
            ans.push_back({time,sum});
        }
        while(i<m){
            ans.push_back({series1[i][0],series1[i++][1]});
        }
        while(j<n){
            ans.push_back({series2[j][0],series2[j++][1]});
        }
        return ans;
    }
};
```
