/*
https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n<=0) return 0;
        while(n>0){
            auto [q, r]=div(n, 3);
            if (r==2) return 0;
            n=q;
        }
        return 1;
    }

    bool checkPowersOfThreeBacktrack(int n) {
        function<bool(int,int)> backtrack = [&](int i, int curr) {
            if (curr == n) return true;
            if (curr > n || pow(3,i) > n) return false;
            // Take or not take
            return backtrack(i+1, curr+pow(3,i)) || backtrack(i+1, curr);
        };
        return backtrack(0, 0);
    }
};
