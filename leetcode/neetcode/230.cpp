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
    int kthSmallest(TreeNode* root, int k) {
        int res, cnt = 0;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
            if (!root) return;
            
            dfs(root->left);

            if (++cnt == k) {
                res = root->val;
                return;
            }
            
            dfs(root->right);
        };
        
        dfs(root);
        return res;
    }
};
