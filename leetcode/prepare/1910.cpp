/*
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.size();
        for (char c: s) {
            ans.push_back(c);
            if (ans.size() >= n && ans[ans.size() - n] == part[0]) {
                int ids = ans.size() - n, idp = 0;
                while (idp < n && ans[ids] == part[idp]) {
                    ids++; idp++;
                }
                if (idp == n) ans.erase(ans.size()-n);
            }
        }
        return ans;
    }

    string removeOccurrences1(string s, string part) {
        string ans = "";
        int n = part.size();
        for (char c: s) {
            ans.push_back(c);
            if (ans.size() >= n && ans.substr(ans.size() - n) == part) {
                ans.resize(ans.size() - n);
            }
        }
        return ans;
    }

    string removeOccurrences2(string s, string part) {
        while(s.length()>0 && s.length()>s.find(part)){
           s.erase(s.find(part),part.length());
        }
        return s;
    }
};
