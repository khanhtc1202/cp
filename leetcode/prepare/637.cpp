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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans; double tmp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size(); tmp = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                tmp += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            tmp /= sz;
            ans.push_back(tmp);
        }
        return ans;
    }
};
