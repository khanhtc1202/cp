/*
https://leetcode.com/problems/k-th-symbol-in-grammar/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs (int n, int k, int root) {
        if (n == 1) return root;

        int totalNodes = pow(2, n-1);
        // target node is on the right of current root subtree
        if (k > (totalNodes/2)) {
            int nextRoot = (root == 0) ? 1 : 0;
            return dfs(n-1, k-(totalNodes/2), nextRoot);
        } else {
            // target node is on the left of current root subtree
            int nextRoot = (root == 0) ? 0 : 1;
            return dfs(n-1, k, nextRoot);
        }
    }

    int kthGrammar(int n, int k) {
        return dfs(n, k, 0);
    }
};
