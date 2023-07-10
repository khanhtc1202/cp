/*
https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> qn;
        qn.push(root);
        while (!qn.empty()) {
            TreeNode* curr = qn.front(); qn.pop();
            if (curr->left) {
                adj[curr->val].push_back(curr->left->val);
                adj[curr->left->val].push_back(curr->val);
                qn.push(curr->left);
            }
            if (curr->right) {
                adj[curr->val].push_back(curr->right->val);
                adj[curr->right->val].push_back(curr->val);
                qn.push(curr->right);
            }
        }

        int ans = -1;
        queue<int> q; q.push(start);
        unordered_set<int> visited;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front(); q.pop();
                for (auto v: adj[u]) {
                    if (visited.find(v) != visited.end()) continue;
                    q.push(v);
                }
                visited.insert(u);
            }
            ans++;
        }
        return ans;
    }
};
