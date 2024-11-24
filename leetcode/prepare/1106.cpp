/*
https://leetcode.com/problems/parsing-a-boolean-expression/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expr) {
        vector<char> stack;
        stack.reserve(expr.size());
        for (char c : expr) {
            switch (c) {
            case ',':
                break;// Do nothing
            case ')': {
                char s;
                vector<char> x;
                char t = stack.back();
                x.push_back(t);
                stack.pop_back();
                // Pop the stack until  '('
                while (t != '(') {
                    x.push_back(t);
                    t = stack.back();
                    stack.pop_back();
                }
                char op = stack.back(); // Get the '&', '|', or '!'
                stack.pop_back();       // Pop the operator
                // Process the operator
                switch (op) {
                case '!':
                    s = (x[0] == 'f') ? 't' : 'f';
                    break;
                case '&':
                    s = all_of(x.begin(), x.end(),
                               [](char b) { return b == 't'; })
                            ? 't'
                            : 'f';
                    break;
                case '|':
                    s = any_of(x.begin(), x.end(),
                               [](char b) { return b == 't'; })
                            ? 't'
                            : 'f';
                    break;
                }
                stack.push_back(s); // Push the result  onto the stack
                break;
            }
            default:            
                stack.push_back(c);
            }
        }
        return stack.back() == 't';
    }
};
