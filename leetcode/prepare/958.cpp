/*
https://leetcode.com/problems/check-completeness-of-a-binary-tree/
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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        bool seenNull = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node == nullptr) seenNull = true;
            else {
                // if previously saw a null node, and this node is not null
                // -> false
                if (seenNull) return false;

                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
