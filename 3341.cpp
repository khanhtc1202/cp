/*
https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
using int3 = tuple<int, int, int>; // (time, i, j)
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<int3, vector<int3>, greater<>> pq;

        auto isOutside = [&](int i, int j) -> bool {
            return i < 0 || i >= n || j < 0 || j >= m;
        };

        vector<int> dx = {0, 1, -1, 0};
        vector<int> dy = {1, 0, 0, -1};

        // init
        pq.emplace(0,0,0);
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1)
                return t;

            for (int a = 0; a < 4; ++a) {
                int r = i + dx[a], c = j + dy[a];
                // outside?
                if (isOutside(r, c)) continue;

                int nextTime = max(t, moveTime[r][c]) + 1; // wait if need

                // update if find better path
                if (nextTime < time[r][c]) {
                    time[r][c] = nextTime;
                    pq.emplace(nextTime, r, c);
                }
            }
        }
        return -1;
    }
};
