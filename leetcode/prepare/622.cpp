/*
https://leetcode.com/problems/design-circular-queue/
*/
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    int q[1000];
    int k, front, back, len;

public:
    MyCircularQueue(int k) : k(k), front(0), back(k-1), len(0) {}

    bool enQueue(int value) {
        if (len == k)
            return 0;
        back = (back == k - 1) ? 0 : back + 1;
        q[back] = value;
        len++;
        return 1;
    }

    bool deQueue() {
        if (len == 0)
            return 0;
        front = (front == k-1) ? 0 : front + 1;
        len--;
        return 1;
    }

    int Front() { return (len == 0) ? -1 : q[front]; }

    int Rear() { return (len == 0) ? -1 : q[back]; }

    bool isEmpty() { return len == 0; }

    bool isFull() { return len == k; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
