#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void initMap(map<char, int>& m) {
        if (m.size() != 0) return;
        string s = "abcdefghijklmnopqrstuvwxyz";
        for (const auto& c: s) {
            m[c] = 0;
        }
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        map<char, int> ms1;
        initMap(ms1);
        for (const auto& c: s1)
            ms1[c]++;

        map<char, int> ms2;
        initMap(ms2);
        for (int i = 0; i < s1.size(); i++)
            ms2[s2[i]]++;

        for (int i = s1.size(); i < s2.size(); i++) {
            if (matched(ms1, ms2))
                return true;
            ms2[s2[i]]++;
            ms2[s2[i-s1.size()]]--;
        }
        return matched(ms1, ms2);
    }

    bool matched(map<char, int>& ms1, map<char, int>& ms2) {
        for (const auto& kv: ms1) {
            if (ms2[kv.first] != ms1[kv.first])
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
