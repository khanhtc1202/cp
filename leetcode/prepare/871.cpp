/*
https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel) return 0;

        priority_queue<int> heap;
        stations.push_back({target, 0});

        int currFuel = startFuel;
        int currPos = 0;
        int ans = 0;
        for (int i = 0; i < stations.size(); i++) {
            int dis = stations[i][0] - currPos;
            while (currFuel < dis && !heap.empty()) {
                currFuel += heap.top();
                ans++;
                heap.pop();
            }

            if (currFuel < dis) return -1;

            currFuel -= dis;
            currPos = stations[i][0];

            heap.push(stations[i][1]);
        }
        return ans;
    }
};
