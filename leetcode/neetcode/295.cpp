#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minheap.size() == maxheap.size()) {
            if (minheap.empty()) {
                maxheap.push(num);
            } else if (num <= minheap.top()) {
                maxheap.push(num);
            } else {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }
        } else {
            // maxheap has more element that minheap (the diff must be 1)
            if (num >= maxheap.top()) {
                minheap.push(num);
            } else {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (minheap.size() == maxheap.size()) {
            return (1.0 * minheap.top() + 1.0 * maxheap.top()) / 2;
        }
        return maxheap.top();
    }
};
