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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* cloned_target;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original, cloned, target);
        return cloned_target;
    }
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target)
        {
            cloned_target = cloned;
        }
        if (original->left) dfs(original->left, cloned->left, target);
        if (original->right) dfs(original->right, cloned->right, target);
    }
};

int main()
{
	return 0;
}
