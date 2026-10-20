# [950. Reveal Cards In Increasing Order](https://leetcode.com/problems/reveal-cards-in-increasing-order/)
**Difficulty:** `Medium` | **Tags:** `array`, `queue`, `sorting`, `simulation`

---

## Problem Description
You are given an integer array `deck`. There is a deck of cards where every card has a unique integer. The integer on the `ith` card is `deck[i]`.

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

1. Take the top card of the deck, reveal it, and take it out of the deck.
2. If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
3. If there are still unrevealed cards, go back to step 1. Otherwise, stop.

Return *an ordering of the deck that would reveal the cards in increasing order*.

**Note** that the first entry in the answer is considered to be the top of the deck.

**Example 1:**

```
Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
```

**Example 2:**

```
Input: deck = [1,1000]
Output: [1,1000]
```

**Constraints:**

* `1 <= deck.length <= 1000`
* `1 <= deck[i] <= 106`
* All the values of `deck` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to order a deck of cards such that when we reveal them one by one using a specific reveal-and-rotate process, the revealed cards appear in strictly increasing order. By sorting the input deck first, we know the exact sorted sequence in which the cards must eventually be revealed. We can simulate the exact card movement process using a queue of indices to determine where each sorted card should be placed in the final answer array.

# Approach
1. Sort the `deck` array in ascending order so we know the target sequence of revealed cards.
2. Initialize an answer vector `ans` of size `n` with `-1` and a queue `q` containing all indices from `0` to `n - 1` representing the initial positions in the deck.
3. Simulate the card revelation process using the queue: pop the front index (representing the currently revealed card slot), add it to an `indices` vector, and if the queue is not empty, pop the next index and push it back to the rear of the queue.
4. Map the sorted values from `deck` to their correct positions in `ans` using the sequence of indices recorded in `indices`.

### Visual Walkthrough (Example 1: deck = [17, 13, 11, 2, 3, 5, 7])
- Sorted deck: `[2, 3, 5, 7, 11, 13, 17]`
- Initial queue of indices: `[0, 1, 2, 3, 4, 5, 6]`
- Simulating queue operations to record position order (`indices`):
  - Pop `0`, push `1` to back -> `indices` = `[0]`, queue = `[2, 3, 4, 5, 6, 1]`
  - Pop `2`, push `3` to back -> `indices` = `[0, 2]`, queue = `[4, 5, 6, 1, 3]`
  - Continuing this simulation yields `indices` = `[0, 2, 4, 6, 3, 1, 5]`
- Assigning sorted deck values to `ans` at `indices`: `ans[0] = 2`, `ans[2] = 3`, `ans[4] = 5`, etc.

# Complexity
- Time complexity: $$O(N \log N)$$ — Dominating operation is sorting the `deck` array of size $$N$$. The queue simulation iterates $$N$$ times, performing $$O(1)$$ operations per card.
- Space complexity: $$O(N)$$ — Auxiliary space is required for the queue, indices vector, and answer array, all scaling linearly with $$N$$.

# Code
```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n,-1);
        queue<int> q;
        sort(deck.begin(),deck.end());
        vector<int> indices;
        for(int i = 0;i<n;i++){
            q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            indices.push_back(top);
            q.pop();
            if(!q.empty()){
                int next = q.front();
                q.push(next);
                q.pop();
            }
        }
        for(int i = 0;i<n;i++){
            ans[indices[i]] = deck[i];
        }
        return ans;
    }
};
```
