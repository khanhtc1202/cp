#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp;
        
        auto genRow = [=](int c) -> string {
            string out = "";
            for (int i = 0; i < n; i++)
                out.push_back(i == c ? 'Q' : '.');
            return out;
        };
        
        vector<int> col(n, 0);
        vector<int> diag1(2*n, 0);
        vector<int> diag2(2*n, 0);
        
        function<void(int)> backtrack = [&](int r) -> void {
            if (tmp.size() == n) {
                res.push_back(tmp);
                return;
            }
            
            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[c+r] || diag2[c-r+n-1]) continue;
                
                tmp.push_back(genRow(c));
                col[c] = diag1[c+r] = diag2[c-r+n-1] = 1;
                backtrack(r+1);
                tmp.pop_back();
                col[c] = diag1[c+r] = diag2[c-r+n-1] = 0;
            }
        };
        
        backtrack(0);
        return res;
    }
};
