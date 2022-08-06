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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        function<int(TreeNode*)> height = [&](TreeNode* root) -> int {
            if (!root) return 0;

            int left = height(root->left);
            int right = height(root->right);

            diameter = max(diameter, left+right);
            
            return 1 + max(left, right);
        };

        height(root);
        return diameter;
    }
};
