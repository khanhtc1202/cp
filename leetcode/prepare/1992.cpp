/*
https://leetcode.com/problems/find-all-groups-of-farmland/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> ans;

    pair<int, int> findRectangle(int r1, int c1, vector<vector<int>>& land){
        int r2=r1, c2=c1;
        for(;r2<n &&land[r2][c1]==1; r2++);
        for(;c2<m &&land[r1][c2]==1;c2++);
        for(int r=r1; r<r2; r++)// fill with 2
            fill(land[r].begin()+c1, land[r].begin()+c2, 2);
        return {--r2, --c2};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(land[i][j]==1){//Choose top left one (since we fill 2 to visited)
                    auto [r2, c2]=findRectangle(i, j, land);
                    ans.push_back({i, j, r2, c2});   
                }
            }
        return ans;
    }
};
