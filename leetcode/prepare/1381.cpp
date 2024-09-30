/*
https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x, Node* next=NULL): data(x), next(next){}
};
class CustomStack {
    Node* top;
    int maxSz, sz;
public:
    CustomStack(int maxSize): top(NULL), maxSz(maxSize), sz(0) {}
    
    void push(int x) {
        if (sz==maxSz) return;
        Node* newNode=new Node(x, top);
        top=newNode;
        sz++;
    }
    
    int pop() {
        if (sz==0) return -1;
        Node* tmp=top;
        top=top->next;
        int x=tmp->data;
        delete tmp;
        sz--;
        return x; 
    }
    
    void increment(int k, int val) {
        int k0=min(k, sz), i=0;
        for(Node* ptr=top; ptr; i++, ptr=ptr->next)
            if (i>=sz-k0) ptr->data+=val;       
    }
};
