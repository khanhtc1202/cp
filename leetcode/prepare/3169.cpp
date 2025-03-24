/*
https://leetcode.com/problems/count-days-without-meetings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int freeDays = 0, lastEnd = 0;
        for (auto& m: meetings) {
            int start = m[0], end = m[1];
            if (start > lastEnd + 1) {
                freeDays += start - lastEnd - 1;
            }
            lastEnd = max(lastEnd, end);
        }
        freeDays += days - lastEnd; // add the rest free day
        return freeDays;
    }
};
