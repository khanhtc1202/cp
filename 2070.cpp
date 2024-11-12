/*
https://leetcode.com/problems/most-beautiful-item-for-each-query/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size());
        sort(items.begin(), items.end());
        vector<vector<int>> q(queries.size(), vector<int>(2));
        for (int i = 0; i < queries.size(); ++i) {
            q[i][0] = queries[i];
            q[i][1] = i; // index
        }
        sort(q.begin(), q.end());

        int itemIndex = 0;
        int maxBeauty = 0;

        for (int i = 0; i < q.size(); ++i) {
            int cq = q[i][0];
            int id = q[i][1];
            while (itemIndex < items.size() && items[itemIndex][0] <= cq) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            ans[id] = maxBeauty;
        }
        return ans;
    }
};
