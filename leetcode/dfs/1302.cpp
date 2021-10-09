#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
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
    vector<int> sums;
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sums.back();
    }
    void dfs(TreeNode* node, int lvl) {
        if (lvl == sums.size()) sums.push_back(node->val);
        else sums[lvl] += node->val;
        if (node->left) dfs(node->left, lvl+1);
        if (node->right) dfs(node->right, lvl+1);
    }
};

int main()
{
	return 0;
}
