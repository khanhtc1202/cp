/*
https://leetcode.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        
        function<void(TreeNode*)> travel = [&](TreeNode* node) {
            if (!node) return;

            if (node->val >= low && node->val <= high)
                sum += node->val;

            travel(node->left); travel(node->right);
        };

        travel(root);
        return sum;
    }
};
