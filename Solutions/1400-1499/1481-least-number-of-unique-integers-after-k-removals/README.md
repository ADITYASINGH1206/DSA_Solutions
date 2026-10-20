# [1481. Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `greedy`, `sorting`, `counting`

---

## Problem Description
Given an array of integers `arr` and an integer `k`. Find the *least number of unique integers* after removing **exactly** `k` elements**.**

**Example 1:**

```

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
```

**Example 2:**

```

Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
```

**Constraints:**

* `1 <= arr.length <= 10^5`
* `1 <= arr[i] <= 10^9`
* `0 <= k <= arr.length`

---

## Solution & Editorial
# Intuition
To minimize the number of unique integers remaining after removing `k` elements, we must greedily remove elements that appear the least frequently. By eliminating the rarest elements first, we exhaust the count of specific unique integers as quickly as possible, thereby reducing the total count of unique integers most efficiently.

# Approach
1. **Frequency Counting**: Use an `unordered_map<int, int>` to store the frequency of each integer in `arr`. Simultaneously, track the initial count of unique integers in `ans`.
2. **Sorting**: Transfer the frequency map into a `vector<pair<int, int>>` and sort it in ascending order based on the frequency values (`v[i].second`).
3. **Greedy Removal**: Iterate through the sorted frequencies. For each element, decrement its frequency and `k` until `k` reaches zero. If an element's frequency drops to zero, it means that unique integer has been completely removed, so we decrement `ans`.

### Visual Trace (Example 2: arr = [4,3,1,1,3,3,2], k = 3)
| Step | Sorted Frequencies (val, count) | k | ans |
| :--- | :--- | :--- | :--- |
| Init | (4,1), (2,1), (1,2), (3,3) | 3 | 4 |
| Remove 4 | (4,0), (2,1), (1,2), (3,3) | 2 | 3 |
| Remove 2 | (4,0), (2,0), (1,2), (3,3) | 1 | 2 |
| Remove 1 | (4,0), (2,0), (1,1), (3,3) | 0 | 2 |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of elements in `arr`. Counting frequencies takes $$O(N)$$, and sorting the unique elements takes $$O(U \log U)$$ where $$U \le N$$. The final pass is $$O(U)$$.
- Space complexity: $$O(N)$$ to store the frequency map and the vector of pairs in the worst case where all elements are unique.

# Code
```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(mp.find(arr[i]) == mp.end()) ans++;
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto [key,value]:mp){
            v.push_back({key,value});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second < b.second;
        });
        int i = 0;
        int sz = v.size();
        while(k>0 && i<sz){
            if(v[i].second>0){
                v[i].second--;
                if(v[i].second == 0){
                    i++;
                    ans--;
                }
                k--;
            }
            
        }
        return ans;
    }
};
```
