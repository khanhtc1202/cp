#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }

        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while (!q.empty()) {
            int n = q.size();

            if (level++ == k)
                break;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parents[curr] && !visited[parents[curr]]) {
                    q.push(parents[curr]);
                    visited[parents[curr]] = true;
                }
            }
        }

        vector<int> out;
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            out.push_back(curr->val);
        }
        return out;
    }
};
