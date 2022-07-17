#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hp;
        for (auto& x: nums) {
            if (hp.find(x) != hp.end())
                return true;
            hp[x] = 1;
        }
        return false;
    }

    bool containDuplicateSet(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
