/*
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int _maxDepth(Node* root) {
        if (!root) return 0;

        queue<Node*> q; q.push(root);
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* tmp = q.front(); q.pop();
                for (auto c: tmp->children) q.push(c);
            }
            ans++;
        }
        return ans;
    }

    int maxDepth(Node* root) {
        if (!root) return 0;

        int ans = 0;
        function<void(Node*, int)> travel = [&](Node* node, int currDepth) {
            currDepth++;
            ans = max(ans, currDepth);

            for (auto c: node->children) {
                travel(c, currDepth);
            }
        };

        travel(root, 0);
        return ans;
    }
};
