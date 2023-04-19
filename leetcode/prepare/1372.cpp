/*
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
            if (!node) return {-1, -1};

            pair<int, int> zigzag {dfs(node->left).second + 1, dfs(node->right).first + 1};
            ans = max({ans, zigzag.first, zigzag.second});

            return zigzag;
        };

        dfs(root);
        return ans;
    }
};
