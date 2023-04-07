/*
https://leetcode.com/problems/closest-binary-search-tree-value/
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
    int closestValue(TreeNode* root, double target) {
        int val, closest = root->val;
        while (root) {
            val = root->val;
            if (abs(val - target) == abs(closest - target)) closest = min(val, closest);
            else closest = abs(val - target) < abs(closest - target) ? val : closest;
            root = val > target ? root->left : root->right;
        }
        return closest;
    }
};
