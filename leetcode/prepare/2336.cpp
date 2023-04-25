/*
https://leetcode.com/problems/smallest-number-in-infinite-set/description/
*/
#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    set<int> pool;
    int current;
public:
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        int ans;
        if (!pool.empty()) {
            ans = *pool.begin();
            pool.erase(pool.begin());
        } else {
            ans = current++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (current <= num || pool.find(num) != pool.end())
            return;

        pool.insert(num);
    }
};
