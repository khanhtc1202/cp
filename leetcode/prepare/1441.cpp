/*
https://leetcode.com/problems/build-an-array-with-stack-operations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int stream_i = 1;
        for (int num: target) {
            while (stream_i < num) {
                ans.push_back("Push");
                ans.push_back("Pop");
                stream_i++;
            }
            ans.push_back("Push");
            stream_i++;
        }
        return ans;
    }
};
