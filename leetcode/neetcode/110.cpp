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
    // O(nlogn)
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // O(n)
    bool isBalancedOpt(TreeNode* root) {
        int height;
        return isBalancedHelper(root, height);
    }

    bool isBalancedHelper(TreeNode* root, int& height) {
        if (!root) {
            height = -1;
            return true;
        }

        int left, right;
        if (isBalancedHelper(root->left, left) &&
            isBalancedHelper(root->right, right) &&
            abs(left - right) <= 1) {
                height = max(left, right);
                return true;
            }
        return false;
    }
};
