/*
https://leetcode.com/problems/count-servers-that-communicate/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<int> rows(m, 0), cols(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
                count += grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && rows[i]==1 && cols[j]==1){
                    count--;
                }
            }
        }
        return count;
    }
};
