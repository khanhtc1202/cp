#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        auto isPalindrome = [&](int l, int r) -> bool {
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };
        
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isPalindrome(i+1, j) || isPalindrome(i, j-1);
            }
            i++; j--;
        }
        return true;
    }
};
