/*
https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        // Create a map of strings to store the count of all substrings.
        map<pair<char, int>, int> count;
        int substringLength = 0;
        for (int start = 0; start < s.length(); start++) {
            char character = s[start];
            substringLength = 0;
            for (int end = start; end < s.length(); end++) {
                // If the string is empty, or the current character is equal to
                // the previously added character, then add it to the map.
                // Otherwise, break the iteration.
                if (character == s[end]) {
                    substringLength++;
                    count[{character, substringLength}]++;
                } else {
                    break;
                }
            }
        }

        // Create a variable ans to store the longest length of substring with
        // frequency atleast 3.
        int ans = 0;
        for (auto i : count) {
            int len = i.first.second;
            if (i.second >= 3 && len > ans) ans = len;
        }
        if (ans == 0) return -1;
        return ans;
    }
};

class Solution_Opt {
public:
    int n;
    string s;
    int alphabet[26][3];
    inline void push(int x, int lens[3]){
        if (x>=lens[0]){
            lens[2]=exchange(lens[1], lens[0]);
            lens[0]=x;
        }
        else if (x>=lens[1]) lens[2]=exchange(lens[1], x);
        else if (x>=lens[2]) lens[2]=x;
    }
    inline void table(){
        char prev=s[0]; 
        int f=1;
        for(int i=1; i<n; i++){
            if (s[i]==prev)
                f++;
            else{
                push(f, alphabet[prev-'a']);
                f=1;
                prev=s[i];  
            }   
        }
        push(f, alphabet[s.back()-'a']);
    }
    inline int maxLen3x(int* v){
        return max({v[2], min(v[0]-1, v[1]), v[0]-2});
    }

    int maximumLength(string& s) {
        this->s=s;
        n=s.size();
        memset(alphabet, -1, sizeof(alphabet));
        table();
        int ans=-1;
        for (int* lens: alphabet){
            if (lens[0]==-1) continue;
            ans=max(ans,  maxLen3x(lens));
        }
        return ans<=0?-1:ans;
    }
};
