/*
https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0; i < experience.size(); ++i) {
            int exp = experience[i], e = energy[i];
            if (initialEnergy <= e) {
                ans += (e + 1 - initialEnergy);
                initialEnergy = e + 1;
            }
            if (initialExperience <= exp) {
                ans += (exp + 1 - initialExperience);
                initialExperience = exp + 1;
            }
            initialExperience += exp;
            initialEnergy -= e;
        }
        return ans;
    }
};
