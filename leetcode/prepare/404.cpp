/*
https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        function<int(TreeNode*, bool)> cal = [&](TreeNode* node, bool isLeft) -> int {
            if (!node) return 0;
            if (!node->left && !node->right)
                return isLeft ? node->val : 0;
            return cal(node->left, true) + cal(node->right, false);
        };

        return cal(root, false);
    }
};
