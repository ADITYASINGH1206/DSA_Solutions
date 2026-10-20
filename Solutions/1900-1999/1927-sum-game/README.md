# [1927. Sum Game](https://leetcode.com/problems/sum-game/)
**Difficulty:** `Medium` | **Tags:** `math`, `string`, `greedy`, `game-theory`

---

## Problem Description
Alice and Bob take turns playing a game, with **Alice****starting first**.

You are given a string `num` of **even length** consisting of digits and `'?'` characters. On each turn, a player will do the following if there is still at least one `'?'` in `num`:

1. Choose an index `i` where `num[i] == '?'`.
2. Replace `num[i]` with any digit between `'0'` and `'9'`.

The game ends when there are no more `'?'` characters in `num`.

For Bob to win, the sum of the digits in the first half of `num` must be **equal** to the sum of the digits in the second half. For Alice to win, the sums must **not be equal**.

* For example, if the game ended with `num = "243801"`, then Bob wins because `2+4+3 = 8+0+1`. If the game ended with `num = "243803"`, then Alice wins because `2+4+3 != 8+0+3`.

Assuming Alice and Bob play **optimally**, return `true` *if Alice will win and* `false` *if Bob will win*.

**Example 1:**

```
Input: num = "5023"
Output: false
Explanation: There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
```

**Example 2:**

```
Input: num = "25??"
Output: true
Explanation: Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
```

**Example 3:**

```
Input: num = "?3295???"
Output: false
Explanation: It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
```

**Constraints:**

* `2 <= num.length <= 105`
* `num.length` is **even**.
* `num` consists of only digits and `'?'`.

---

## Solution & Editorial
# Intuition
This problem can be reduced to a simple mathematical invariant. Let $S_1$ be the sum of the first half and $S_2$ be the sum of the second half. We want to know if $S_1 = S_2$ at the end. Let $Q_1$ and $Q_2$ be the number of '?' in the first and second halves, respectively. Each '?' in the first half adds to $S_1$, and each '?' in the second half adds to $S_2$. Since Alice wants to make $S_1 \neq S_2$ and Bob wants $S_1 = S_2$, we can track the net difference $D = S_1 - S_2$. Each '?' in the first half effectively contributes $+4.5$ on average, and each '?' in the second half contributes $-4.5$. Bob wins if and only if the final sum of these contributions exactly cancels out the initial difference of the known digits.

# Approach
1. Calculate the initial difference `diff` between the sum of the first half and the second half using existing digits.
2. Count the number of '?' in the first half ($Q_1$) and second half ($Q_2$).
3. The net effect of all '?' is that $Q_1$ question marks add to the sum and $Q_2$ question marks subtract from the sum. Since each '?' can be replaced by a digit $0-9$ (average $4.5$), the total expected change is $4.5 \times (Q_1 - Q_2)$.
4. Bob wins if the initial `diff` is exactly equal to $4.5 \times (Q_2 - Q_1)$. Multiplying by 2 to avoid floating point, Bob wins if $2 \times \text{diff} + 9 \times (Q_1 - Q_2) == 0$.

### Visual Trace (Example 2: "25??")
- Initial: `diff = (2+5) - (0+0) = 7`. $Q_1 = 0, Q_2 = 2$.
- Formula: $2 \times 7 + 9 \times (0 - 2) = 14 - 18 = -4$.
- Since $-4 \neq 0$, Alice wins (return `true`).

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the string, as we iterate through the string exactly once.
- Space complexity: $$O(1)$$ as we only store a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    bool sumGame(string& num) {
        const int n=num.size(), n2=n>>1;
        int diff=0;
        for(int i=0; i<n; i++){
            const char c=num[i];
            bool isq=c=='?', half=i<n2;
            int sgn=(half<<1)-1;
            int d=(-isq & 9)+(-!isq & (c-'0')<<1);
            diff+=sgn*d;
        }
        return diff!=0;
    }
};
```
