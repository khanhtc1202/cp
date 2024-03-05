/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            Node* prev = nullptr;
            for (int i = 0; i < sz; ++i) {
                auto curr = q.front(); q.pop();
                if (!prev) prev = curr;
                else prev->next = curr;
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                prev = curr;
            }
        }
        return root;
    }
};
