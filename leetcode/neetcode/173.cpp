/*
https://leetcode.com/problems/binary-search-tree-iterator/
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

class BSTIterator {
stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        build(root);
    }
    
    int next() {
        TreeNode* top = stk.top(); stk.pop();
        build(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

private:
    void build(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
};
