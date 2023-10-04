/*
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        int n = preorder.size();

        function<TreeNode*(int, int)> build = [&](int low, int high) -> TreeNode* {
            if (idx == n) return nullptr;

            int val = preorder[idx];
            if (val < low || val > high) return nullptr;

            idx++;
            TreeNode* node = new TreeNode(val);
            node->left = build(low, val);
            node->right = build(val, high);
            return node;
        };

        return build(0, 1001);
    }
};
