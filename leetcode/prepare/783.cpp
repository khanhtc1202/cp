/*
https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        function<void(TreeNode*)> travel = [&](TreeNode* node) {
            if (!node) return;

            travel(node->left);

            if (prev)
                ans = min(ans, (node->val - prev->val));

            prev = node;
            travel(node->right);
        };

        travel(root);
        return ans;
    }
};
