/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string& s) {
        using int_char=pair<int, char>;
        int freq[75];//'0'=48 'z'=122=>'z'-'0'+1=75        
        for(char c : s)
            freq[c-'0']++;

        priority_queue<int_char> pq;//MaxHeap
        int beg1=s.size();// freq=1 beginning index
        for(char c='0'; c<='z'; c++){
            if (freq[c-'0']==0) continue;
            if (freq[c-'0']==1) s[--beg1]=c;
            else pq.emplace(freq[c-'0'], c);
        }
        int l=0;
        while(!pq.empty()){
            auto [f, c]=pq.top();
            pq.pop();
            fill(s.begin()+l, s.begin()+(l+f), c);
            l+=f;
        }
        return s;       
    }
};
