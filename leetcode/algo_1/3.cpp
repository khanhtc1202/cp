#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        map<char, int> window;
        int max_l = 0;
        int lo = 0, hi = 0;

        while (hi < s.size()) {
            if (window.find(s[hi]) != window.end()) {
                cout << "DEBUG: hi: " << hi << " | lo: " << lo << endl;
                for (const auto& k: window) {
                    cout << k.first << " | " << k.second << endl;
                }
                lo = max(lo, window[s[hi]] + 1);
            }
            window[s[hi]] = hi;
            max_l = max(max_l, hi - lo + 1);
            hi++;
        }
        return max_l;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("aabbaab!bb") << endl;
    return 0;
}
