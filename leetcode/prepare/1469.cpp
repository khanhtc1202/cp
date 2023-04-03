/*
https://leetcode.com/problems/find-all-the-lonely-nodes/description/
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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
            if (!node) return;

            if (node->left && !node->right)
                res.push_back(node->left->val);

            if (node->right && !node->left)
                res.push_back(node->right->val);

            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return res;
    }
};
