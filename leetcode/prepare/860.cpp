/*
https://leetcode.com/problems/lemonade-change/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        short cnt5 = 0, cnt10 = 0;
        for (auto b: bills) {
            switch (b) {
                case 5:
                    cnt5++;
                    break;
                case 10:
                    if (cnt5 > 0) cnt5--, cnt10++;
                    else return false;
                    break;
                case 20:
                    if (cnt10 > 0 && cnt5 > 0) cnt10--, cnt5--;
                    else if (cnt5 > 2) cnt5 -= 3;
                    else return false;
                    break;
            }
        }
        return true;
    }
};
