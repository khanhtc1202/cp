/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int> mx_heap;
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (auto num: nums) {
            if (mn_heap.size() < k) {
                mn_heap.push(num);
                continue;
            }
            
            if (mn_heap.top() >= num) {
                mx_heap.push(num);
                continue;
            }
            
            if (mn_heap.top() < num) {
                int tmp = mn_heap.top(); mn_heap.pop();
                mn_heap.push(num);
                mx_heap.push(tmp);
            }
        }
    }
    
    int add(int val) {
        if (mn_heap.size() < kth) {
            mn_heap.push(val);
            return mn_heap.top();
        }

        if (mn_heap.top() == val) {
            mx_heap.push(val);
            return val;
        }
        
        if (mn_heap.top() > val) {
            mx_heap.push(val);
            return mn_heap.top();
        }
        
        if (mn_heap.top() < val) {
            mn_heap.push(val);
            int tmp = mn_heap.top(); mn_heap.pop();
            mx_heap.push(tmp);
            return mn_heap.top();
        }
        
        // unreachable
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
