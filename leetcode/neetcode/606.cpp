/*
https://leetcode.com/problems/construct-string-from-binary-tree/
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
    string tree2str(TreeNode* root) {
        string out;
        
        function<void(TreeNode*)> build = [&](TreeNode* root) -> void {
            if (!root) return;
            out += to_string(root->val);
            
            if (!root->left && !root->right) return;
            out += '(';
            build(root->left);
            out += ')';
            
            if (root->right) {
                out += '(';
                build(root->right);
                out += ')';
            }
        };
        
        build(root);
        return out;
    }
};
