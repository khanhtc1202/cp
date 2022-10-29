#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        
        unordered_map<string, int> exists;
        string curr = s.substr(0, 10);
        exists[curr] = 1;
        vector<string> out;
        for (int i = 10; i < s.size(); i++) {
            curr = curr.substr(1, 9) + s[i];
            if (exists[curr] == 1) out.push_back(curr);
            exists[curr]++;
        }
        return out;
    }
};
