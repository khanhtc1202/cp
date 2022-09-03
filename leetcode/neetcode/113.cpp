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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> path; path.push_back(root->val);
        int sum = root->val;
        function<void(TreeNode*)> backtrack = [&](TreeNode* node) -> void {
            if (!node->left && !node->right) {
                if (sum == targetSum) {
                    res.push_back(path);
                }
                return;
            }

            if (node->left) {
                path.push_back(node->left->val);
                sum += node->left->val;
                backtrack(node->left);
                path.pop_back();
                sum -= node->left->val;
            }
            
            if (node->right) {
                path.push_back(node->right->val);
                sum += node->right->val;
                backtrack(node->right);
                path.pop_back();
                sum -= node->right->val;
            }
        };
        
        backtrack(root);
        return res;
    }
};
