/*
https://leetcode.com/problems/maximum-average-pass-ratio/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calGain = [](int p, int t) -> double {
            return (double)(p+1) / (t+1) - (double)p / t;
        };

        // max heap of {possible gain: current class info} pair
        priority_queue<pair<double, pair<int,int>>> heap;
        for (const auto& c: classes) {
            heap.push({calGain(c[0], c[1]), {c[0], c[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [gain, classinfo] = heap.top();
            heap.pop();
            // use best gain value by add one to the classinfo to remember
            auto [passes, total] = classinfo;
            heap.push({calGain(passes+1, total+1), {passes+1, total+1}});
        }

        // Calculate final result
        double totalRatio = 0;
        while (!heap.empty()) {
            auto [_, classinfo] = heap.top(); heap.pop();
            totalRatio += (double)classinfo.first / classinfo.second;
        }
        return totalRatio / classes.size();
    }
};
