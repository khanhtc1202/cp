/*
https://leetcode.com/problems/implement-stack-using-queues/
*/
#include <bits/stdc++.h>
using namespace std;

class MyStack {
int sz;
queue<int> que;
public:
    MyStack(): sz(0) {}
    
    void push(int x) {
        que.push(x);
        for (int i = 0; i < sz; i++) {
            que.push(que.front());
            que.pop();
        }
        sz++;
    }
    
    int pop() {
        sz--;
        int e = que.front();
        que.pop();
        return e;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return sz == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
