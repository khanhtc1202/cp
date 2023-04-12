/*
https://leetcode.com/problems/simplify-path/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        int i = 1;
        while (i < path.size()) {
            if (path[i] == '/') {
                if (dir != "") dirs.push_back(dir);
                dir = "";
            } else {
                dir += path[i];
            }
            i++;
        }
        if (dir != "") {
            dirs.push_back(dir);
        }

        string ans = "";
        int drop = 0;
        while (!dirs.empty()) {
            dir = dirs.back(); dirs.pop_back();

            if (dir == "..") {
                drop++;
                continue;
            }
            if (dir == ".") {
                continue;
            }
            if (drop) {
                drop--;
                continue;
            }
            ans = ("/" + dir + ans);
        }
        return ans == "" ? "/" : ans;
    }
};
