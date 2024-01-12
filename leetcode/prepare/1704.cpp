/*
https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        return (0x208222>>(c&0x1f))&1;
    }
    bool halvesAreAlike(string& s) {
        int n = s.size()/2, f=0;
        for(int i=0; i<n; i++)
            f += isVowel(s[i]);
        for(int i=n; i<=2*n; i++) 
            f -= isVowel(s[i]);

        return f==0;
    }
};
