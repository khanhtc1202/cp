#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hm;

        for (auto& n: nums) {
            hm.insert(n);
        }

        int ans = 0, cnt, cur;
        for (auto& n: hm) {
            if (hm.find(n-1) != hm.end())
                continue;

            cnt = 1; cur = n;
            while (hm.count(cur+1)) {
                cnt++; cur++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
