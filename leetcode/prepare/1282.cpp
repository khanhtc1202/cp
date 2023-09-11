/*
https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ii=pair<int, int>;
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        priority_queue<ii, vector<ii>, greater<ii>> min_heap;
        vector<vector<int>> ans;
        int n = groupSizes.size();
        
        for (int i = 0; i < n; ++i) {
            int sz = groupSizes[i];
            if (sz == 1) ans.push_back({i});
            else min_heap.push({sz, i});
        }

        vector<int> tmp;
        while (!min_heap.empty()) {
            auto [sz, x] = min_heap.top(); min_heap.pop();
            tmp.push_back(x);
            if (tmp.size() == sz) {
                ans.push_back(tmp);
                tmp.clear();
            }
        }

        return ans;
    }

    vector<vector<int>> groupThePeople_HashMap(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        vector<vector<int>> ans;
        int n = groupSizes.size();

        for (int i = 0; i < n; ++i) {
            int gs = groupSizes[i];
            if (gs == 1) ans.push_back({i});
            else {
                hash[gs].push_back(i);
                if (hash[gs].size() == gs) {
                    ans.push_back(hash[gs]);
                    hash[gs].clear();
                }
            }
        }
        return ans;
    }
};
