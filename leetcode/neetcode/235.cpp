#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = root;

        while (res) {
            if (p->val > res->val && q->val > res->val) {
                res = res->right;
            } else if (p->val < res->val && q->val < res->val) {
                res = res->left;
            } else {
                return res;
            }
        }
        return nullptr;
    }
};
