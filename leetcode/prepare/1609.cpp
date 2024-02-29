/*
https://leetcode.com/problems/even-odd-tree/
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        int k = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; ++i) {
                TreeNode* curr = q.front(); q.pop();
                if (k % 2) {
                    if (curr->val % 2) return false;
                    if (tmp.empty()) tmp.push_back(curr->val);
                    else if (tmp.back() <= curr->val) return false;
                    else tmp.push_back(curr->val);
                } else {
                    if (curr->val % 2 == 0) return false;
                    if (tmp.empty()) tmp.push_back(curr->val);
                    else if (tmp.back() >= curr->val) return false;
                    else tmp.push_back(curr->val);
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ++k;
        }
        return true;
    }
};
