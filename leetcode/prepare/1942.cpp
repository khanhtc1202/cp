/*
https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // pair store {leavingTime, chairNum}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        int nextChair = 0;
        set<int> availableChairs;

        for (auto time: times) {
            int arrival = time[0], leave = time[1];
            while (!minHeap.empty() && minHeap.top().first <= arrival) {
                availableChairs.insert(minHeap.top().second);
                minHeap.pop();
            }

            int currentChair;
            if (availableChairs.empty()) {
                currentChair = nextChair++;
            } else {
                currentChair = *availableChairs.begin(); // smallest possible chair
                availableChairs.erase(availableChairs.begin());
            }

            if (arrival == targetArrival) return currentChair;
            // Track chairs
            minHeap.push({leave, currentChair});
        }
        return 0;
    }
};
