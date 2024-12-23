/*
https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root); int ans = 0;

        while (!q.empty()) {
            int lvlSize = q.size();
            vector<int> lvl(lvlSize);

            for (int i = 0; i < lvlSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                lvl[i] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans += getSwapsCount(lvl);
        }
        return ans;
    }

    int getSwapsCount(vector<int>& org) {
        int swaps = 0;
        vector<int> target = org;
        sort(target.begin(), target.end());

        unordered_map<int,int> pos;
        for (int i = 0; i < org.size(); ++i) {
            pos[org[i]] = i;
        }

        for (int i = 0; i < org.size(); ++i) {
            if (org[i] != target[i]) {
                swaps++;
                int currPos = pos[target[i]];
                pos[org[i]] = currPos;
                swap(org[currPos], org[i]);
            }
        }
        return swaps;
    }
};
