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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        stack<pair<TreeNode*, int>> stk;
        stk.push({root, targetSum - root->val});

        while (!stk.empty()) {
            TreeNode* curr = stk.top().first;
            int leftSum = stk.top().second;
            stk.pop();

            if (!curr->left && !curr->right && leftSum == 0)
                return true;
            if (curr->left)
                stk.push({curr->left, leftSum - curr->left->val});
            if (curr->right)
                stk.push({curr->right, leftSum - curr->right->val});
        }
        return false;
    }
};
