/*
https://leetcode.com/problems/number-of-senior-citizens/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        return accumulate(details.begin(), details.end(), 0, [](int sum, string& s){
            return sum+= ((s[11]-'0')*10+(s[12]-'0'))>60?1:0;
        });
    }
};
