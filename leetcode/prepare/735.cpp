/*
https://leetcode.com/problems/asteroid-collision/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int ast: asteroids) {
            int flag = 1;
            while (!stk.empty() && stk.back() > 0 && ast < 0) {
                // Pop all smaller asteroid.
                if (stk.back() < abs(ast)) {
                    stk.pop_back();
                    continue;
                }
                // If ast has same size with the top one, both explore
                if (stk.back() == abs(ast)) {
                    stk.pop_back();
                }
                // There is -> asteroid that bigger than the current asteroid
                // so the current asteroid will be explored
                flag = 0;
                break;
            }
            if (flag) stk.push_back(ast);
        }
        return stk;
    }
};
