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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        unordered_map<int, int> nodes;
        for (int i = 0; i < n; i++)
            nodes[inorder[i]] = i;

        int preorderIdx = 0;
        function<TreeNode*(int, int)> addToTree = [&](int start, int end) -> TreeNode* {
            if (start > end) return nullptr;

            int val = preorder[preorderIdx++];
            TreeNode* root = new TreeNode(val);

            root->left = addToTree(start, nodes[val]-1);
            root->right = addToTree(nodes[val]-1, end);

            return root;
        };

        return addToTree(0, n-1);
    }
};
