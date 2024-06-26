/*
https://leetcode.com/problems/word-break-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(const string& s, const unordered_set<string>& wordSet, string& currentSentence,
                    vector<string>& results, int startIndex) {
        // Reach the end of the string then current sentence is a valid sentence
        if (startIndex == s.length()) {
            results.push_back(currentSentence);
            return;
        }

        // Iterate over possible end indices
        for (int endIndex = startIndex+1; endIndex <= s.length(); ++endIndex) {
            string word = s.substr(startIndex, endIndex - startIndex);
            // If the word is in the set, proceed with backtracking
            if (wordSet.find(word) != wordSet.end()) {
                string originalSentence = currentSentence;
                if (!currentSentence.empty()) currentSentence += " ";
                currentSentence += word;
                backtrack(s, wordSet, currentSentence, results, endIndex);
                currentSentence = originalSentence;
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> results;
        string currentSentence;
        backtrack(s, wordSet, currentSentence, results, 0);
        return results;
    }
};
