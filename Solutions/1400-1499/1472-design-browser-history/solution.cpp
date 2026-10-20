/**
 * Problem: Design Browser History (1472)
 * Link: https://leetcode.com/problems/design-browser-history/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
