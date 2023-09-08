/*
https://leetcode.com/problems/pascals-triangle/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            if (i == 1)
                ans.push_back({1});
            else if (i == 2)
                ans.push_back({1,1});
            else {
                vector<int> row;
                row.push_back(1);
                
                for (int j = 1; j < ans[ans.size()-1].size(); j++) {
                    row.push_back(ans[ans.size()-1][j]+ans[ans.size()-1][j-1]);
                }
                
                row.push_back(1);
                ans.push_back(row);
            }
        }
        return ans;
    }
};
