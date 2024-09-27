/*
https://leetcode.com/problems/my-calendar-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    // All single booking
    vector<pair<int,int>> bookings;
    // All overlap exist between 2 bookings
    vector<pair<int,int>> overlapBookings;

    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // Overlap with overlapped one -> false
        for (pair<int,int> b: overlapBookings) {
            if (doesOverlap(b.first, b.second, start, end)) {
                return false;
            }
        }
        // Add overlap if exist with all current booking
        for (pair<int,int> b: bookings) {
            if (doesOverlap(b.first, b.second, start, end)) {
                overlapBookings.push_back(getOverlap(b.first, b.second, start, end));
            }
        }
        // Add bookings
        bookings.push_back({start, end});
        return true;
    }
private:
    bool doesOverlap(int s1, int e1, int s2, int e2) {
        return max(s1, s2) < min(e1, e2);
    }

    // Return the overlap between [s1, e1) & [s2, e2)
    pair<int,int> getOverlap(int s1, int e1, int s2, int e2) {
        return {max(s1,s2), min(e1,e2)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
