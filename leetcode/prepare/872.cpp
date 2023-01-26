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
        vector<int> leaf;

        auto bfs = [&](TreeNode* node) -> void {
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

        bfs(root1);
        bfs(root2);
        if (leaf.size() % 2) return false;
        for (int i = 0; i < leaf.size() / 2; i++) {
            if (leaf[i] != leaf[leaf.size()/2 + i]) return false;
        }
        return true;
    }
};
