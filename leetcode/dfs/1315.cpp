#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        return sum;
    }
    void dfs(TreeNode* node, TreeNode* p, TreeNode* gp) {
        if (gp != NULL && gp->val % 2 == 0)
        {
            sum += node->val;
        }
        if (node->left) dfs(node->left, node, p);
        if (node->right) dfs(node->right, node, p);
    }
};

int main()
{
	return 0;
}
