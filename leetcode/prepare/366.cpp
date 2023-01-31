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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        function<int(TreeNode*)> cal = [&](TreeNode* node) {
            if (!node) return -1;

            int leftHeight = cal(node->left);
            int rightHeight = cal(node->right);
            int currHeight = 1 + max(leftHeight, rightHeight);

            // Init new row.
            if (currHeight == ans.size())
                ans.push_back({});

            ans[currHeight].push_back(node->val);
            return currHeight;
        };
        cal(root);
        return ans;
    }
};
