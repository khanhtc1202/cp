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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root->left && !root->right) return {to_string(root->val)};

        vector<string> res;
        string path;
        
        function<void(TreeNode*)> backtrack = [&](TreeNode* node) -> void {
            if (!node->left && !node->right) {
                res.push_back(path + "->" + to_string(node->val));
                return;
            }
            
            string curr = path;
            if (node->left) {
                path += "->" + to_string(node->val);
                backtrack(node->left);
                path = curr;
            }
            
            if (node->right) {
                path += "->" + to_string(node->val);
                backtrack(node->right);
                path = curr;
            }
        };
        
        path = to_string(root->val);
        if (root->left) backtrack(root->left);
        if (root->right) backtrack(root->right);
        return res;
    }
};
