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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* clone = new TreeNode(0);
        TreeNode* curr = clone;

        function<void(TreeNode*)> travel = [&](TreeNode* node) {
            if (!node) return;

            travel(node->left);
            node->left = nullptr;
            curr->right = node;
            curr = node;
            travel(node->right);
        };

        travel(root);
        return clone->right;
    }
};
