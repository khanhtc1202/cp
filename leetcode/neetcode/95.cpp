/*
https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> build = [&](int start, int end) -> vector<TreeNode*> {
            vector<TreeNode*> trees;
            if (start > end) {
                trees.push_back(nullptr);
                return trees;
            }

            for (int i = start; i <= end; i++) {
                vector<TreeNode*> lefts = build(start, i-1);
                vector<TreeNode*> rights = build(i+1, end);

                for (auto l: lefts) {
                    for (auto r: rights) {
                        TreeNode* curr = new TreeNode(i);
                        curr->left = l;
                        curr->right = r;
                        trees.push_back(curr);
                    }
                }
            }
            return trees;
        };

        return build(1, n);
    }
};
