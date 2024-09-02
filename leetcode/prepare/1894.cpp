/*
https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for (int i = 0; i < chalk.size(); ++i) {
            sum += chalk[i];
            if (sum > k) break;
        }
        
        k %= sum;
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};
