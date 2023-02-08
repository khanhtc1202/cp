/*
Problem desc: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> travel = [&](Node* node) {
            if (!node) return;

            for (auto c: node->children) {
                travel(c);
            }
            ans.push_back(node->val);
        };

        travel(root);
        return ans;
    }
};
