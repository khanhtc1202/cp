/*
https://leetcode.com/problems/longest-happy-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> heap;
        if (a > 0) heap.push({a,'a'});
        if (b > 0) heap.push({b,'b'});
        if (c > 0) heap.push({c,'c'});

        string ans = "";
        while (!heap.empty()) {
            auto p = heap.top(); heap.pop();
            int cnt = p.first; char c = p.second;
            if (ans.size() >= 2 && ans[ans.size()-1] == c && ans[ans.size()-2] == c) {
                if (heap.empty()) break;
                auto temp = heap.top(); heap.pop();
                ans += temp.second;
                if (temp.first - 1 > 0) {
                    heap.push({temp.first - 1, temp.second});
                }
            } else {
                cnt--;
                ans += c;
            }
            if (cnt > 0) {
                heap.push({cnt, c});
            }
        }
        return ans;
    }
};
