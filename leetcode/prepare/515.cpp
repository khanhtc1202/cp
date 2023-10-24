/*
https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int rMax = INT_MIN;
            for (int i = 0; i < sz; ++i) {
                TreeNode* curr = q.front();
                rMax = max(rMax, curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                q.pop();
            }
            ans.push_back(rMax);
        }
        return ans;
    }
};
