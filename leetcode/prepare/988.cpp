/*
https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> q;
        q.emplace(root, "");
        string ans = "|";
        while(!q.empty()){
            auto [node, s]=q.front();
            s+=(node->val+'a');
            q.pop();
            if (!node->left && !node->right){
                string t=move(s);
                reverse(t.begin(), t.end());
                ans=min(ans, t);
            }
            if(node->left) q.emplace(node->left, s);
            if(node->right) q.emplace(node->right, s);    
        }
        return ans;
    }
};
