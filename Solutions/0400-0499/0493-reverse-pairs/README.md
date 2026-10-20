# [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `divide-and-conquer`, `binary-indexed-tree`, `segment-tree`, `merge-sort`, `ordered-set`, `treap`

---

## Problem Description
Given an integer array `nums`, return *the number of **reverse pairs** in the array*.

A **reverse pair** is a pair `(i, j)` where:

* `0 <= i < j < nums.length` and
* `nums[i] > 2 * nums[j]`.

**Example 1:**

```
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
```

**Example 2:**

```
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
```

**Constraints:**

* `1 <= nums.length <= 5 * 104`
* `-231 <= nums[i] <= 231 - 1`

---

## Solution & Editorial
# Intuition
The problem asks us to count pairs $(i, j)$ such that $0 \le i < j < n$ and $\text{nums}[i] > 2 \cdot \text{nums}[j]$. This resembles the classic inversion count problem, but with a scaling factor of $2$. A modified Merge Sort algorithm allows us to count these cross-subproblem pairs efficiently in $O(N \log N)$ time while simultaneously sorting the array.

# Approach
1. **Divide and Conquer**: The `mergeSort` function recursively splits the array into halves until single-element base cases are reached ($low \ge high$).
2. **Count Cross Pairs**: Before merging the sorted left subarray and sorted right subarray, the `countPairs` function counts the number of valid reverse pairs where the left element comes from $[low, mid]$ and the right element comes from $[mid + 1, high]$. Because both halves are already internally sorted, we can use a two-pointer approach (`right` pointer scanning the right half for each element in the left half) without recounting.
3. **Merge Step**: The standard `merge` function combines the two sorted halves into a temporary vector and copies them back to maintain global sorting order for subsequent recursive steps.

# Complexity
- Time complexity: $$O(N \log N)$$ — The array is divided into halves in $\log N$ levels of recursion, and at each level, linear time $$O(N)$$ is spent on counting reverse pairs and merging.
- Space complexity: $$O(N)$$ — Auxiliary storage is required for the `temp` vector during the merge step and for the recursive call stack of depth $O(\log N)$.

# Code
```cpp
class Solution {
public:
    int countPairs(vector<int> &arr,int low,int mid,int high){
        int count = 0;
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right <= high && arr[i] > 2LL *arr[right]) right++;
            count += (right - (mid+1));
        }
        return count;
    }
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int count = 0;
        if (low >= high)
            return count;
        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += countPairs(arr,low,mid,high);
        merge(arr, low, mid, high);
        return count;
    }



    int reversePairs(vector<int>& nums) {
        int ans = mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};
```
