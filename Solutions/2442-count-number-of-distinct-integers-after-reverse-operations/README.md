# [2442. Count Number of Distinct Integers After Reverse Operations](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `math`, `counting`

---

## Problem Description
You are given an array `nums` consisting of **positive** integers.

You have to take each integer in the array, **reverse its digits**, and add it to the end of the array. You should apply this operation to the original integers in `nums`.

Return *the number of **distinct** integers in the final array*.

**Example 1:**

```
Input: nums = [1,13,10,12,31]
Output: 6
Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).
```

**Example 2:**

```
Input: nums = [2,2,2]
Output: 1
Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 106`

---

## Solution & Editorial
# Intuition
To count the number of distinct integers after adding their reversed counterparts, we need to efficiently track unique values. Since the problem asks for the count of distinct integers in the final set, a hash-based container (like `std::unordered_set` or `std::unordered_map`) is ideal for deduplication.

# Approach
1. Iterate through the original `nums` array. For each integer, calculate its reverse by repeatedly extracting the last digit (`temp % 10`) and building the new number (`new_num * 10 + digit`).
2. Append these reversed integers to the collection. 
3. Insert all original and reversed integers into an `unordered_map` (or `unordered_set`) to automatically handle duplicates.
4. The size of the map represents the count of distinct integers.

### Visual Trace (Example 1: [1, 13, 10])
| Original | Reversed | Set State |
| :--- | :--- | :--- |
| 1 | 1 | {1} |
| 13 | 31 | {1, 13, 31} |
| 10 | 1 | {1, 13, 31, 10} |

# Complexity
- Time complexity: $$O(N \cdot \log_{10}(M))$$, where $$N$$ is the number of elements in `nums` and $$M$$ is the maximum value in `nums`. Each integer is processed in logarithmic time relative to its value to reverse its digits.
- Space complexity: $$O(N)$$, as we store up to $$2N$$ integers in the hash map.

# Code
```cpp
class Solution {
public:
    void reverse_digits(int num,vector<int>&nums){
        int temp = num;
        int new_num = 0;
        while(temp > 0){
            int digit = temp%10;
            new_num = (new_num * 10) + digit;
            temp /= 10;
        }
        nums.push_back(new_num);
    }
    int countDistinctIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            reverse_digits(nums[i],nums);
        }
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto& [key,value] : mp){
            ans++;
        }
        return ans;
    }
};
```
