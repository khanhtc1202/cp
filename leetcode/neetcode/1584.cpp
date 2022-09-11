#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;
        pq.push({0, 0});
        
        int ans = 0;
        while (visited.size() < n) {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (visited.find(u) != visited.end()) continue;

            visited.insert(u);
            ans += w;
            
            for (int i = 1; i < n; i++) {
                if (visited.find(i) != visited.end()) continue;
                pq.push({abs(points[u][0] - points[i][0])+abs(points[u][1] - points[i][1]), i});
            }
        }
        return ans;
    }
};
