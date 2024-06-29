/*
https://leetcode.com/problems/maximum-total-importance-of-roads/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indeg(n, 0);
        for (int i = 0; i < roads.size(); ++i) {
            indeg[roads[i][0]]++;
            indeg[roads[i][1]]++;
        }
        sort(indeg.begin(), indeg.end());
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += 1LL*i*indeg[i-1];
        }
        return ans;
    }
};
