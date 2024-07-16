/*
https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
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
    // Find path in root -> val using backtrack approach
    string getDirections(TreeNode* root, int startValue, int destValue) {
        function<bool(TreeNode*, int, string&)> dfs = [&](TreeNode* curr, int val, string& path) -> bool {
            if (curr == nullptr) return false;
            if (curr->val == val) return true;

            path += "L";
            if (dfs(curr->left, val, path)) return true;
            path.pop_back();

            path += "R";
            if (dfs(curr->right, val, path)) return true;
            path.pop_back();

            return false;
        };

        string rootS = "", rootD = "";
        dfs(root, startValue, rootS);
        dfs(root, destValue, rootD);

        int N = min(rootS.size(), rootD.size());
        int i = 0;
        while (i < N && rootS[i] == rootD[i]) {
            i++;
        }

        string ans = "";
        for (int j = i; j < rootS.size(); ++j) ans += "U";
        for (int j = i; j < rootD.size(); ++j) ans += rootD[j];

        return ans;
    }

    // Find path in reverse for faster dfs
    string getDirections(TreeNode* root, int startValue, int destValue) {
        function<bool(TreeNode*, int, string&)> dfs = [&](TreeNode* curr, int val, string& path) -> bool {
            if (curr->val == val) return true;

            if (curr->left && dfs(curr->left, val, path)) {
                path.push_back('L');
            } else if (curr->right && dfs(curr->right, val, path)) {
                path.push_back('R');
            }
            return !path.empty();
        };

        string startPath, destPath;
        find(root, startValue, startPath);
        find(root, destValue, destPath);
        while (!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()){
            startPath.pop_back();
            destPath.pop_back();
        }
        return string(startPath.size(), 'U') + string(destPath.rbegin(), destPath.rend());
    }
};
