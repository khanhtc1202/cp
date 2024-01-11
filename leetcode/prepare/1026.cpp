/*
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
using infor = tuple<TreeNode*,int,int>; // node/min/max
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        vector<infor> stk;
        stk.emplace_back(root,INT_MAX,INT_MIN);

        while (!stk.empty()) {
            auto [node, _min, _max] = stk.back(); stk.pop_back();
            int x = node->val;
            _min = min(x, _min);
            _max = max(x, _max);
            ans = max({ans, abs(x - _min), abs(x - _max)});
            
            if (node->right) stk.emplace_back(node->right, _min, _max);
            if (node->left) stk.emplace_back(node->left, _min, _max);
        }
        return ans;
    }
};
