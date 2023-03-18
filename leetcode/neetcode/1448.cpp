/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    int goodNodes(TreeNode* root) {
        int res = 0;

        function <void(TreeNode*, int)> dfs = [&](TreeNode* root, int currmax) -> void {
            if (!root) return;

            if (root->val >= currmax) res++;

            currmax = max(currmax, root->val);
            dfs(root->left, currmax);
            dfs(root->right, currmax);
        };

        dfs(root, 0);
        return res;
    }
};
