/*
https://leetcode.com/problems/design-browser-history/
*/
#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
    vector<string> history;
    int curr;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        int n = history.size() - 1;
        while (n > curr) {
            history.pop_back();
            n--;
        }
        curr++;
        history.push_back(url);
    }
    
    string back(int steps) {
        curr -= steps;
        if (curr < 0) curr = 0;
        return history[curr];
    }
    
    string forward(int steps) {
        curr += steps;
        if (curr >= history.size()) curr = history.size() - 1;
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
