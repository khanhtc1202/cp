/*
https://leetcode.com/problems/number-of-recent-calls/
*/
#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
queue<int> bucket;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        bucket.push(t);
        int pivot = max(t-3000, 0);
        while (!bucket.empty() && bucket.front() < pivot) {
            bucket.pop();
        }
        return bucket.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
