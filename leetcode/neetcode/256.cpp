#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int l1, l2, l3;
        l1 = l2 = l3 = 0;
        for (int i = 0; i < costs.size(); i++) {
            int tmp1 = costs[i][0] + min(l2, l3);
            int tmp2 = costs[i][1] + min(l1, l3);
            int tmp3 = costs[i][2] + min(l1, l2);
            l1 = tmp1, l2 = tmp2, l3 = tmp3;
        }
        return min(l1, min(l2, l3));
    }
};
