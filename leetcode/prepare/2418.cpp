/*
https://leetcode.com/problems/sort-the-people/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int N = names.size();
        vector<pair<int,int>> hi(N);
        for (int i = 0; i < heights.size(); ++i) {
            hi[i] = {heights[i], i};
        }
        sort(hi.begin(), hi.end());
        vector<string> ans(N);
        for (int i = N-1; i >= 0; --i) {
            ans[N-i-1] = names[hi[i].second];
        }
        return ans;
    }
};
