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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        TreeNode* curr;

        while (!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            for (int i = 0; i < len; i++) {
                curr = q.front(); q.pop();
                if (!curr) continue;
                tmp.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            if (tmp.size()) res.push_back(tmp);
        }
        return res;
    }
};
