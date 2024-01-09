/*
https://leetcode.com/problems/leaf-similar-trees/
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto bfs = [&](TreeNode* node, vector<int>& leaf) -> void {
            stack<TreeNode*> q;
            q.push(node);
            while (!q.empty()) {
                TreeNode* tmp = q.top(); q.pop();
                if (!tmp->left && !tmp->right) {
                    leaf.push_back(tmp->val);
                    continue;
                }
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        };

        vector<int> leaf1, leaf2;
        bfs(root1, leaf1);
        bfs(root2, leaf2);
        return leaf1 == leaf2;
    }
};
