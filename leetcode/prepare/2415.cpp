/*
https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        function<void(TreeNode*, TreeNode*, int)> travel = [&](TreeNode* a, TreeNode* b, int lvl) -> void {
            if (!a) return;
            if (lvl % 2) swap(a->val, b->val);
            travel(a->left, b->right, lvl+1);
            travel(a->right, b->left, lvl+1);
        };

        travel(root->left, root->right, 1);
        return root;
    }
};
