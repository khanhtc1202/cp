/*
https://leetcode.com/problems/smallest-sufficient-team/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();
        unordered_map<string, int> skillId;
        for (int i = 0; i < m; i++) {
            skillId[req_skills[i]] = i;
        }
        vector<int> skillsMaskOfPerson(n);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i]) {
                skillsMaskOfPerson[i] |= 1 << skillId[skill];
            }
        }
        // At max there are n people in team thus 11...1 (= 2^n - 1 convert to bitmask)
        vector<long long> dp(1 << m, (1LL << n) - 1);
        dp[0] = 0;
        for (int skillsMask = 1; skillsMask < (1 << m); skillsMask++) {
            for (int i = 0; i < n; i++) {
                // skillsMask without skills of the current iterating person
                int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
                
                if (smallerSkillsMask != skillsMask) {
                    // Add current person to team with smallerSkillsMask
                    long long peopleMask = dp[smallerSkillsMask] | (1LL << i);
                    // If the teamMask smaller than the current team stored
                    // which has skillsMask, update teamMask as smallest team
                    // which has skillsMask.
                    if (__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
        }
        long long answerMask = dp[(1 << m) - 1];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
