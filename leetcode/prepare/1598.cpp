/*
https://leetcode.com/problems/crawler-log-folder/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for (const auto& x: logs) {
            if (x == "../") {
                if (step > 0) --step;
            } else if (x != "./") {
                ++step;
            }
        }
        return step;
    }
};
