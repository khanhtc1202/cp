/*
https://leetcode.com/problems/average-waiting-time/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int N = customers.size();
        double time = 0, wait = 0;
        for (int i = 0; i < N; ++i) {
            time = max(customers[i][0] * 1.0, time);
            time += customers[i][1];
            wait += (time - customers[i][0]);
        }
        return wait / N;
    }
};
