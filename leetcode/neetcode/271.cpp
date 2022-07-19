#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (auto& str: strs) {
            int len = str.size();
            s += to_string(len) + '#' + str;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {        
        vector<string> out;
        string cnt; int i = 0; bool cut = false;
        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c) && !cut) {
                cnt += c;
                i++;
                continue;
            }
            // cut the '#'
            if (c == '#' && !cut) {
                i++; cut = true;
                continue;
            }
            // cut the string with lenght = cnt
            int len = atoi(cnt.c_str());
            cnt = ""; cut = false;
            out.push_back(s.substr(i,len));
            i += len;
        }
        if (cut) out.push_back("");
        return out;
    }
};
