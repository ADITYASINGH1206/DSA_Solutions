# [1472. Design Browser History](https://leetcode.com/problems/design-browser-history/)
**Difficulty:** `Medium` | **Tags:** `array`, `linked-list`, `stack`, `design`, `doubly-linked-list`, `data-stream`

---

## Problem Description
You have a **browser** of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:

* `BrowserHistory(string homepage)` Initializes the object with the `homepage` of the browser.
* `void visit(string url)` Visits `url` from the current page. It clears up all the forward history.
* `string back(int steps)` Move `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current `url` after moving back in history **at most** `steps`.
* `string forward(int steps)` Move `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you will forward only `x` steps. Return the current `url` after forwarding in history **at most** `steps`.

**Example:**

```
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
```

**Constraints:**

* `1 <= homepage.length <= 20`
* `1 <= url.length <= 20`
* `1 <= steps <= 100`
* `homepage` and `url` consist of  '.' or lower case English letters.
* At most `5000` calls will be made to `visit`, `back`, and `forward`.

---

## Solution & Editorial
# Intuition
To simulate browser history, we need a data structure that supports efficient insertion and bidirectional traversal. A Doubly Linked List is ideal because visiting a new URL effectively truncates the "forward" history, which is equivalent to deleting the remainder of the list and appending a new node.

# Approach
1. **Data Structure**: Use a `LL` (Linked List) node class containing `prev`, `next` pointers, and a `url` string.
2. **Initialization**: Create a head node with the `homepage`.
3. **Visit**: Create a new node, link it to the current node (`curr->next = newPage`), and update `curr` to this new node. This naturally discards any existing forward history.
4. **Back/Forward**: Traverse the `prev` or `next` pointers respectively, decrementing `steps` until either `steps` reaches zero or the boundary (null pointer) is hit.

### Visual Trace (Example 1)
| Operation | State (Nodes) | `curr` | Output |
| :--- | :--- | :--- | :--- |
| Init | [leetcode] | leetcode | - |
| Visit google | [leetcode] <-> [google] | google | - |
| Visit facebook | [leetcode] <-> [google] <-> [facebook] | facebook | - |
| Back(1) | [leetcode] <-> [google] <-> [facebook] | google | google |

# Complexity
- Time complexity: $$O(K)$$ for `back` and `forward` operations, where $$K$$ is the number of steps requested. `visit` is $$O(1)$$.
- Space complexity: $$O(N)$$ where $$N$$ is the total number of unique URLs visited, as we store each in a node.

# Code
```cpp
class LL{
public:
    LL* prev= nullptr;
    LL* next= nullptr;
    string url;

    LL(LL* prev,LL* next,string url){
        this->prev= prev;
        this->next= next;
        this->url = url;
    }
};

class BrowserHistory {
public:
    LL* curr = nullptr;
    BrowserHistory(string homepage) {
        curr = new LL(nullptr,nullptr,homepage);
    }
    
    void visit(string url) {
        LL* newPage = new LL(curr,nullptr,url);
        curr->next = newPage;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps && curr->prev){
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps && curr->next){
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
```
