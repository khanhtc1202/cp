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
    TreeNode* pruneTree(TreeNode* root) {
        function<bool(TreeNode*)> containOne = [&](TreeNode* node) {
            if (!node) return false;
            bool left = containOne(node->left);
            bool right = containOne(node->right);
            // Remove left/right if not contain any 1.
            if (!left) node->left = nullptr;
            if (!right) node->right = nullptr;
            return node->val == 1 || left || right;
        };

        return containOne(root) ? root : nullptr;
    }
};
