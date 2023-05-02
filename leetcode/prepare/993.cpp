/*
https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        bool found_x, found_y;
        TreeNode* p_x, *p_y;
        while (!q.empty()) {
            found_x = found_y = false;
            p_x = p_y = nullptr;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [node, parent] = q.front(); q.pop();
                if (node->val == x) { found_x = true; p_x = parent; }
                if (node->val == y) { found_y = true; p_y = parent; }
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
            if (found_x != found_y) return false;
            else if (found_x == true) return p_x != p_y;
        }
        return false;
    }
};
