# [901. Online Stock Span](https://leetcode.com/problems/online-stock-span/)
**Difficulty:** `Medium` | **Tags:** `stack`, `design`, `monotonic-stack`, `data-stream`

---

## Problem Description
Design an algorithm that collects daily price quotes for some stock and returns **the span** of that stock's price for the current day.

The **span** of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

* For example, if the prices of the stock in the last four days are `[7,2,1,2]` and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal to 2 for 4 consecutive days.
* Also, if the prices of the stock in the last four days is `[7,34,1,2]` and the price of the stock today is `8`, then the span of today is `3` because starting from today, the price of the stock was less than or equal `8` for `3` consecutive days.

Implement the `StockSpanner` class:

* `StockSpanner()` Initializes the object of the class.
* `int next(int price)` Returns the **span** of the stock's price given that today's price is `price`.

**Example 1:**

```
Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
```

**Constraints:**

* `1 <= price <= 105`
* At most `104` calls will be made to `next`.

---

## Solution & Editorial
# Intuition
The problem asks us to find the number of consecutive previous days with stock prices less than or equal to the current day's price. When a higher price arrives, it swallows up all preceding smaller prices along with their cumulative spans. This naturally points towards a Monotonic Stack data structure that stores pairs of `(price, span)`.

# Approach
1. Maintain a stack `st` holding `pair<int, int>` representing `(price, span)` for processed days.
2. For each incoming `price`, initialize `span = 1`.
3. While the stack is not empty and the top element's price is less than or equal to `price`, accumulate its span into `span` and pop it from the stack.
4. Push the current `price` and its accumulated `span` onto the stack.
5. Return `span`.

### Visual Trace Walkthrough (Example 1)

| Call | Price | Stack State Before | Popped Elements | Calculated Span | Stack State After |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `next(100)` | 100 | `[]` | None | `1` | `[(100, 1)]` |
| `next(80)` | 80 | `[(100, 1)]` | None | `1` | `[(100, 1), (80, 1)]` |
| `next(60)` | 60 | `[(100, 1), (80, 1)]` | None | `1` | `[(100, 1), (80, 1), (60, 1)]` |
| `next(70)` | 70 | `[(100, 1), (80, 1), (60, 1)]` | `(60, 1)` | `1 + 1 = 2` | `[(100, 1), (80, 1), (70, 2)]` |
| `next(60)` | 60 | `[(100, 1), (80, 1), (70, 2)]` | None | `1` | `[(100, 1), (80, 1), (70, 2), (60, 1)]` |
| `next(75)` | 75 | `[(100, 1), (80, 1), (70, 2), (60, 1)]` | `(60, 1), (70, 2)` | `1 + 1 + 2 = 4` | `[(100, 1), (80, 1), (75, 4)]` |
| `next(85)` | 85 | `[(100, 1), (80, 1), (75, 4)]` | `(75, 4), (80, 1)` | `1 + 4 + 1 = 6` | `[(100, 1), (85, 6)]` |

# Complexity
- Time complexity: $$O(1)$$ amortized per `next` call. Each element is pushed onto the stack exactly once and popped at most once across all `N` calls.
- Space complexity: $$O(N)$$ where `N` is the number of calls to `next`, as the stack stores at most `N` elements in the worst case of strictly increasing prices.

# Code
```cpp
class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```
