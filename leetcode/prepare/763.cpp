/*
https://leetcode.com/problems/partition-labels/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> last;
        
        for (int i = 0; i < n; i++)
            last[s[i]] = i;
        
        vector<int> res;
        int curr = 0;
        while (curr < n) {
            int start = curr, max_pos = curr;
            while (curr <= max_pos) {
                max_pos = max(max_pos, last[s[curr]]);
                curr++;
            }
            
            res.push_back(max_pos - start + 1);
        }
        return res;
    }
};
