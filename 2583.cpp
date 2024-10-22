/*
https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<>> heap;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            long sum = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            heap.push(sum);
            if (heap.size() > k) heap.pop();
        }
        if (heap.size() < k) return -1;
        return heap.top();
    }
};
