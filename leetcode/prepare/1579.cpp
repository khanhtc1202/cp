/*
https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
*/
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> root, Size;
    int components;
public:
    UnionFind(int n): root(n+1), Size(n+1,1), components(n){
        iota(root.begin(), root.end(), 0);    
    }
    
    int Find(int x) {
        if (x==root[x]) 
            return x;
        return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {       
        x=Find(x), y=Find(y);
        
        if (x == y) return 0;
        
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        components--;
        return 1;
    }

    bool isConnected() {
        return components == 1;
    }
        
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n), Bob(n);

        int edgesNeed=0;
        // Process type 3 edges first
        for (vector<int>& e: edges) {
            if (e[0]==3) {
                edgesNeed+=(Alice.Union(e[1], e[2]) | Bob.Union(e[1], e[2]));
            }
        }
        // Process type 1 and type 2 edges
        for (vector<int>& e: edges){
            if (e[0]==1) edgesNeed+=Alice.Union(e[1], e[2]);
            else if (e[0]==2) edgesNeed+=Bob.Union(e[1], e[2]);
        }

        if (Alice.isConnected() && Bob.isConnected())
            return edges.size()-edgesNeed;
        return -1;
    }
};
