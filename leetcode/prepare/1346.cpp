/*
https://leetcode.com/problems/check-if-n-and-its-double-exist/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> count;
        for (int x: arr) count[x]++;
        for (int x: arr) {
            if (x == 0 && count[0] > 1) return true;
            if (x != 0 && count.find(x*2) != count.end()) return true;
        }
        return false;
    }
};
