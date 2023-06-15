/*
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {
        int ans, level = 0, _max = INT_MIN;
        queue<TreeNode*> row; row.push(root);
        while (!row.empty()) {
            int sz = row.size();
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* u = row.front(); row.pop();
                sum += u->val;
                if (u->left) row.push(u->left);
                if (u->right) row.push(u->right);
            }
            level++;

            if (_max < sum) {
                _max = sum;
                ans = level;
            }
        }
        return ans;
    }
};
