/*
https://leetcode.com/problems/meeting-rooms-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < intervals.size(); i++) {
            vector<int> mtg = intervals[i];
            if (!heap.empty() && heap.top().first <= mtg[0]) {
                heap.pop();
            }
            heap.push({mtg[1], mtg[0]});
        }
        return heap.size();
    }
};
