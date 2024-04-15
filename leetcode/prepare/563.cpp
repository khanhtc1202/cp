/*
https://leetcode.com/problems/binary-tree-tilt/
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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        function<int(TreeNode*)> travel = [&](TreeNode* node) -> int {
            if (node == nullptr) return 0;

            int leftSum = travel(node->left);
            int rightSum = travel(node->right);
            tilt += abs(leftSum - rightSum);

            return node->val + leftSum + rightSum;
        };

        travel(root);
        return tilt;
    }
};
