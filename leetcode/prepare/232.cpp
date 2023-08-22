/*
https://leetcode.com/problems/implement-queue-using-stacks/
*/
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    // s1 use as a buffer, s2 store the queue from head (for popping)
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty())
                s2.push(s1.top()), s1.pop();
        }
        int x = s2.top(); s2.pop();
        return x;
    }
    
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty())
                s2.push(s1.top()), s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
