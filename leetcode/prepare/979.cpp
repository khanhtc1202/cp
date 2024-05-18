/*
https://leetcode.com/problems/distribute-coins-in-binary-tree/
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
    int distributeCoins(TreeNode* root) {
        int total = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;

            // cal number of coins this should hold if its children
            // are coins fullfiled
            int hold = dfs(node->left) + dfs(node->right) + node->val;
            // The number of move needed since it should hold only 1 coins at last
            int move = 1 - hold;
            // Update move count
            total += abs(move);
            return -move;
        };

        dfs(root);
        return total;
    }
};
