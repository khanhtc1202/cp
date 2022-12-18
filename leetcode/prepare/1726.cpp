#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> pairs;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i+1; j < nums.size(); j++)
                // new pair will attact with previous ones to be new (a, b), (c, d)
                ans += pairs[nums[i]*nums[j]]++;
        return ans*8;
    }
};
