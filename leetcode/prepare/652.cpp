/*
https://leetcode.com/problems/find-duplicate-subtrees/
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> memo;
        vector<TreeNode*> ans;

        function<string(TreeNode*)> build = [&](TreeNode* node) -> string {
            if (!node) return "#";

            // post travel left->right->root
            string s = build(node->left) + ',' + build(node->right) + ',' + to_string(node->val);

            memo[s]++;
            // Only count duplicate once
            if (memo[s] == 2) ans.push_back(node);

            return s;
        };

        build(root);
        return ans;
    }
};
