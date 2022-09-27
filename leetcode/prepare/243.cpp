#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int i1 = -1, i2 = -1;
        int ans = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            if (word1 == wordsDict[i]) i1 = i;
            if (word2 == wordsDict[i]) i2 = i;
            
            if (i1 != -1 && i2 != -1) {
                ans = min(ans, abs(i2-i1));
            }
        }
        return ans;
    }
};
