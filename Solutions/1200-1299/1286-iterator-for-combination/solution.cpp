/**
 * Problem: Iterator for Combination (1286)
 * Link: https://leetcode.com/problems/iterator-for-combination/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
public:
    vector<string> arr;
    int i = 0;
    
    void backtrack(string &s, int len, int i, string &cur){
        if(i==s.size()){
            if(cur.size()==len) arr.push_back(cur);
            return;
        }
        cur.push_back(s[i]);
        backtrack(s,len,i+1,cur);
        cur.pop_back();
        backtrack(s,len,i+1,cur);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string cur = "";
        backtrack(characters, combinationLength, 0, cur);
    }
    
    string next() {
        string ans = arr[i++];
        return ans;
    }
    
    bool hasNext() {
        return i<arr.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
