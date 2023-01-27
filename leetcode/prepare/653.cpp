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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        
        function<bool(TreeNode*)> find = [&](TreeNode* node) {
            if (!node) return false;
            if (seen.find(k - node->val) != seen.end()) return true;
            seen.insert(node->val);
            return find(node->left) || find(node->right);
        };

        return find(root);
    }
};
