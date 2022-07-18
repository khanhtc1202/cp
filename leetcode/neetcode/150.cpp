#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (auto tk: tokens) {
            if (tk.size() > 1 || isdigit(tk[0])) {
                stk.push(stoi(tk));
                continue;
            }

            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop();

            int res = 0;
            if (tk == "+")
                res = num1+num2;
            else if (tk == "-")
                res = num1-num2;
            else if (tk == "*")
                res = num1*num2;
            else
                res = num1/num2;

            stk.push(res);
        }
        return stk.top();
    }
};
