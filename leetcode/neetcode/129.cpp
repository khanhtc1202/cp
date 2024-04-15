/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int curr = 0;
        
        function<void(TreeNode*)> read = [&](TreeNode* node) -> void {
            if (!node->left && !node->right) {
                sum += curr;
                return;
            }
            
            if (node->left) {
                curr = curr * 10 + node->left->val;
                read(node->left);
                curr /= 10;
            }
            
            if (node->right) {
                curr = curr * 10 + node->right->val;
                read(node->right);
                curr /= 10;
            }
        };
        
        curr = root->val;
        read(root);
        return sum;
    }
};
