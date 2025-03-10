/*
https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atLeast(word, k) - atLeast(word, k+1);
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';
    }

    long atLeast(string& w, int k) {
        long cnt = 0;
        int s = 0, e = 0;
        unordered_map<char,int> vCount;
        int cCount = 0;
        while (e < w.size()) {
            char c = w[e];
            if (isVowel(c)) {
                vCount[c]++;
            } else cCount++;

            // Shrink the window, under condition (5 vowels)
            while (vCount.size() == 5 && cCount >= k) {
                // from end to end of w, all char can combine with curr string to make a valid string
                cnt += w.size() - e;
                char sChar = w[s];
                if (isVowel(sChar)) {
                    if (--vCount[sChar]==0) {
                        vCount.erase(sChar);
                    }
                } else cCount--;
                s++; // shrink the window
            }
            e++;
        }
        return cnt;
    }
};
