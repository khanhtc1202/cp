/*
https://leetcode.com/problems/maximal-rectangle/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle_n3(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = matrix[i][j] - '0';
                prefix[i][j] = i == 0 ? tmp : prefix[i-1][j] + tmp;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cnt = 0, len = 0;
                for (int k = 0; k < m; k++) {
                    if (j-i+1 == (prefix[j][k] - prefix[i][k] + matrix[i][k] - '0'))
                        cnt++;
                    else cnt = 0;

                    len = max(len, cnt);
                }
                res = max(res, len * (j-i+1));
            }
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);

        auto build = [&]() -> pair<vector<int>, vector<int>> {
            int sz = height.size();
            vector<int> L(sz), R(sz);
            stack<int> stk;
            for (int i = 0; i < sz; i++) {
                while (!stk.empty() && height[stk.top()] >= height[i])
                    stk.pop();
                
                L[i] = stk.empty() ? 0 : stk.top() + 1;
                stk.push(i);
            }
            stk = {};
            for (int i = sz - 1; i > -1; i--) {
                while (!stk.empty() && height[stk.top()] >= height[i])
                    stk.pop();

                R[i] = stk.empty() ? sz - 1 : stk.top() - 1;
                stk.push(i);
            }
            return {L, R};
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            auto [L, R] = build();
            for (int j = 0; j < m; j++) {
                res = max(res, (R[j] - L[j] + 1) * height[j]);
            }
        }
        return res;
    }
};
