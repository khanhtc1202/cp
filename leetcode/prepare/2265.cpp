/*
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
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
    using pii = pair<int,int>;

    int averageOfSubtree(TreeNode* root) {
        int count = 0;

        function<pii(TreeNode*)> postOrder = [&](TreeNode* node) -> pii {
            if (!node) return {0, 0};

            pii left = postOrder(node->left);
            pii right = postOrder(node->right);

            int nodeSum = left.first + right.first + node->val;
            int nodeCount = left.second + right.second + 1;

            if (node->val == (nodeSum / nodeCount)) {
                ++count;
            }

            return {nodeSum, nodeCount};
        };

        postOrder(root);
        return count;
    }
};
