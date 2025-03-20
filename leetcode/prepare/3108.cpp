/*
https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
*/
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    int root[100000], rank[100000];
    UnionFind(int N){
        iota(root, root+N, 0);
        fill(rank, rank+N, 1);    
    }
    
    int Find(int x) {
        return (x==root[x]) ? x : root[x] = Find(root[x]);
    }

    void Union(int x, int y) {//Union by rank
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return;
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
    }
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        UnionFind graph(n);
        vector<unsigned> cost(n, UINT_MAX);
        for (auto& vec: edges){
            int u=vec[0], v=vec[1], w=vec[2];
            int wt=cost[graph.Find(u)] & cost[graph.Find(v)] & w;
            graph.Union(u, v);
            int rt=graph.Find(u);
            cost[rt]&=wt;
        }
        int m=query.size();
        vector<int> ans(m, -1);
        for(int i=0; i<m; i++){
            int s=query[i][0], t=query[i][1];
            if (graph.connected(s, t))
                ans[i]=cost[graph.Find(s)];
        }
        return ans;
    }
};
