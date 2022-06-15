#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string& s) {
        int fast = 0, slow = 0;

        for (fast = 0; fast < s.size(); fast++) {
            if (s[fast] == ' ') {
                reverse(s.begin() + slow, s.begin() + fast);
                slow = fast+1;
            }
        }
        reverse(s.begin() + slow, s.end());
        return s;
    }
};

int main() {
    Solution sol;
    // string s; cin >> s;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s) << endl;
    return 0;
}
