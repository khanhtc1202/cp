/*
https://leetcode.com/problems/meeting-rooms-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using info = pair<long long, int>;

    auto pop(auto& MinHeap) {
        pop_heap(MinHeap.begin(), MinHeap.end(), greater<>{});
        auto x = MinHeap.back();
        MinHeap.pop_back();
        return x;
    }

    void push(auto& MinHeap, auto x) {
        MinHeap.push_back(x);
        push_heap(MinHeap.begin(), MinHeap.end(), greater<>{});
        //MinHeap represents a min-heap, 
        //and the minimum element will be at the front (MinHeap.front()).
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        vector<int> freeRoom(n);
        iota(freeRoom.begin(), freeRoom.end(), 0); //[0,1,...,n-1]
        // 2 Min heap, 1 for free rooms; other for the info (ending time, room number)
        make_heap(freeRoom.begin(), freeRoom.end(), greater<int>{});
        vector<info> used;

        for (auto& meet : meetings) {
            int room;
            while (!used.empty() && used.front().first <= meet[0]) {//Min element on front
                room = pop(used).second;
                push(freeRoom, room);
            }

            long long start, m_time = meet[1] - meet[0];
            if (freeRoom.empty()) {
                tie(start, room) = pop(used);
            } else {
                start = meet[0];
                // Pop
                room = pop(freeRoom);
            }
            count[room]++;
            push(used, make_pair(start + m_time, room));
        }

        int idx = max_element(count.begin(), count.end()) - count.begin();

        return idx;
    }
};
