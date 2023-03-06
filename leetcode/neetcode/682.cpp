/*
Problem desc: https://leetcode.com/problems/baseball-game/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (auto ope: operations) {
            if (ope == "C") {
                scores.pop();
                continue;
            }
            if (ope == "D") {
                scores.push(scores.top() * 2);
                continue;
            }
            if (ope == "+") {
                int t1 = scores.top(); scores.pop();
                int t2 = scores.top();
                scores.push(t1);
                scores.push(t1+t2);
                continue;
            }
            scores.push(stoi(ope));
        }
        int ans = 0;
        while (!scores.empty()) {
            ans += scores.top();
            scores.pop();
        }
        return ans;
    }
};
