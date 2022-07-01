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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> out;
        queue<TreeNode*> q;
        q.push(root);

        bool left = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> row(n);

            for (int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                
                if (left) {
                    row[i] = tmp->val;
                } else {
                    row[n - 1 - i] = tmp->val;
                }
            }
            out.push_back(row);
            left = !left;
        }
        return out;
    }
};
