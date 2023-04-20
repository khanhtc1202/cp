/*
https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, double>> q;
        q.push({root, 0});
        double ans = 0;
        while (!q.empty()) {
            double headNodeColIndex = q.front().second;
            int sz = q.size();
            double lastNodeColIndex = 0;
            for (int i = 0; i < sz; i++) {
                auto [node, colIndex] = q.front(); q.pop();
                if (node->left) q.push({node->left, 2 * colIndex});
                if (node->right) q.push({node->right, 2 * colIndex + 1});
                lastNodeColIndex = colIndex;
            }
            ans = max(ans, lastNodeColIndex - headNodeColIndex + 1);
        }
        return (int)ans;
    }
};
