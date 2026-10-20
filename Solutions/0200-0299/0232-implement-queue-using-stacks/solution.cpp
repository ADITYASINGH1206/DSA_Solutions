/**
 * Problem: Implement Queue using Stacks (232)
 * Link: https://leetcode.com/problems/implement-queue-using-stacks/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2; 

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int val = peek();
        s2.pop();
        return val;
    }

    int peek() {
        transfer();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
