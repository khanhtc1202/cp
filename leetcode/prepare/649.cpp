/*
https://leetcode.com/problems/dota2-senate/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq, dq;
        for (int i = 0; i < n; i++)
            senate[i] == 'R' ? rq.push(i) : dq.push(i);

        while (!rq.empty() && !dq.empty()) {
            int rturn = rq.front(); rq.pop();
            int dturn = dq.front(); dq.pop();

            rturn < dturn ? rq.push(rturn + n) : dq.push(dturn + n);
        }
        return rq.empty() ? "Dire" : "Radiant";
    }
};
