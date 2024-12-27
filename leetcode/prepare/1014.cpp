/*
https://leetcode.com/problems/best-sightseeing-pair/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int sumi = values[0] + 0;
        int sumj = values[1] - 1;
        int ans = sumi + sumj;
        for (int j = 2; j < values.size(); ++j) {
            sumj = values[j] - j;
            // Maximum sumi since sumj is fixed by index j
            sumi = max(sumi, values[j-1] + j-1);
            ans = max(ans, sumi+sumj);
        }
        return ans;
    }
};
