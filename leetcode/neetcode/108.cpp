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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
            if (left > right) return nullptr;
            
            int mid = (left + right) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(left, mid-1);
            root->right = build(mid+1, right);

            return root;
        };
        
        return build(0, nums.size() - 1);
    }
};
