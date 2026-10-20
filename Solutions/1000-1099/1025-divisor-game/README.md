# [1025. Divisor Game](https://leetcode.com/problems/divisor-game/)
**Difficulty:** `Easy` | **Tags:** `math`, `dynamic-programming`, `brainteaser`, `game-theory`, `impartial-game`

---

## Problem Description
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `n` on the chalkboard. On each player's turn, that player makes a move consisting of:

* Choosing any integer `x` with `0 < x < n` and `n % x == 0`.
* Replacing the number `n` on the chalkboard with `n - x`.

Also, if a player cannot make a move, they lose the game.

Return `true` *if and only if Alice wins the game, assuming both players play optimally*.

**Example 1:**

```
Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
```

**Example 2:**

```
Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
```

**Constraints:**

* `1 <= n <= 1000`

---

## Solution & Editorial
# Intuition
The problem describes an impartial game where two players take turns making moves. By analyzing the winning and losing states for small values of $n$, we can observe a strict parity pattern that completely determines the outcome of the game.

# Approach
1. Check the parity of the input integer `n` using the modulo operator `n % 2 == 0`.
2. If `n` is even, Alice can always choose `x = 1` to pass an odd number `n - 1` to Bob. Since any odd number can only yield odd divisors resulting in an even number, Bob will always receive an even number until he runs out of moves, guaranteeing a win for Alice.
3. If `n` is odd, any valid divisor `x` must also be odd, meaning `n - x` is always even. Thus, Alice is forced to pass an even number to Bob, allowing Bob to win by applying the same strategy.

### Visual Trace Walkthrough
For Example 1: `n = 2`
- `n % 2 == 0` evaluates to `true` (2 is even).
- Alice chooses `x = 1`, leaving `n - 1 = 1` on the chalkboard.
- Bob has no valid moves (`0 < x < 1` with `1 % x == 0` has no solutions).
- Bob loses, so Alice wins (`true`).

# Complexity
- Time complexity: $$O(1)$$ — only a single modulo operation is performed.
- Space complexity: $$O(1)$$ — no extra memory is allocated.

# Code
```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n%2 == 0;
    }
};
```
