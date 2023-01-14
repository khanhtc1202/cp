#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long bitmask = 0;
        for (auto num: nums) bitmask ^= num;

        long long diff = bitmask & (-bitmask);

        int x = 0;
        for (auto num: nums) if ((num & diff) != 0) x ^= num;
        
        return {x, (int)bitmask ^ x};
    }
};
