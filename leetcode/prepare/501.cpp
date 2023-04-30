/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> findMode(TreeNode* root) {
        int maxc = 1;
        vector<int> ans;
        unordered_map<int, int> cnt;
        function<void(TreeNode*)> travel = [&](TreeNode* node) {
            if (!node) return;
            cnt[node->val]++;
            if (cnt[node->val] == maxc) ans.push_back(node->val);
            if (cnt[node->val] > maxc) {
                ans = {};
                ans.push_back(node->val);
                maxc = cnt[node->val];
            }
            travel(node->left);
            travel(node->right);
        };

        travel(root);
        return ans;
    }
};
