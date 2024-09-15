/*
https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int findTheLongestSubstring(string& s) {
        char vow[26];
        memset(vow, -1, 26);
        vow[0]=0, vow['e'-'a']=1, vow['i'-'a']=2, vow['o'-'a']=3, vow['u'-'a']=4;
        const int n=s.size();

        int first_seen[32]; // index for different bmask first seen
        memset(first_seen, -1, sizeof(first_seen));
        int len=0;
        first_seen[0]=0; // no vowels for bmask[0]
        char curr=0;
        for(int i=0; i<n; i++){
            const char x=vow[s[i]-'a'];
            curr^=(x==-1?0:(1<<x));
            if (first_seen[curr]==-1) first_seen[curr]=i+1;
            len=max(len, i+1-first_seen[curr]);
        }
        return len;
    }
};
