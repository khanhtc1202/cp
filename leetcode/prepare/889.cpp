/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    vector<int> x2pre, x2post;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int n = preorder.size();
        x2pre.assign(n+1, -1);
        x2post.assign(n+1, -1);

        for (int i=0; i<n; i++) {
            x2pre[preorder[i]]=i;  // Store preorder indices
            x2post[postorder[i]]=i;  // Store postorder indices
        }
        return constructTree(preorder, postorder, 0, 0, n-1);
    }

    // preE index can be found by 
    TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder, int preS, int postS, int postE) {
        if (postS>postE) return NULL;  // Base case
        TreeNode* root=new TreeNode(preorder[preS]);
        if (postS==postE) return root;  // Only 1 node

        // Identify left child and find its range in postorder
        int lRoot=preorder[preS+1];  // Left child is next in preorder (and it will be the root of subtree on left)
        int lrPostIdx=x2post[lRoot];   // Index of left root in postorder

        // Recursively build left and right subtrees
        root->left=constructTree(preorder, postorder, preS+1, postS, lrPostIdx);
        root->right=constructTree(preorder, postorder, x2pre[postorder[postE-1]], lrPostIdx+1, postE-1);

        return root;
    }
};
