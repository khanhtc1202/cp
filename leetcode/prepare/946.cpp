/*
https://leetcode.com/problems/validate-stack-sequences/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int sz = pushed.size();
        vector<int> stk;
        int i = 0;
        for (auto e: pushed) {
            stk.push_back(e);
            while (!stk.empty() && i < sz && stk.back() == popped[i]) {
                stk.pop_back();
                i++;
            }
        }
        return i == sz;
    }
};
