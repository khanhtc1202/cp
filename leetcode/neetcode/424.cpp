#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        auto solve = [&](char c) -> void {
            int cnt = 0, r = 0;
            for (int l = 0; l < s.size(); l++) {
                while (r < s.size() && (cnt + (s[r] != c)) <= k) {
                    cnt += (s[r] != c);
                    r++;
                }
                ans = max(ans, r-l);
                cnt -= (s[l] != c);
            }
        };
        for (int i = 0; i < 26; i++) {
            solve(i + 'A');
        }
        return ans;
    }

    int characterReplacement2(string s, int k) {
        vector<int> counts(26, 0);
        int res = 0, left = 0;
        int maxf = 0;
        for (int right = 0; right < s.size(); right++) {
            // Update counts
            counts[s[right] - 'A']++;

            // Keep maintaining the substring valid condition
            // while ((right - left + 1) - max_element(counts.begin(), counts.end()) > k) {}

            // can maintain only maxf which should be increasing only since
            // lenght - maxf <= k
            // formular only need to be update if the maxf is max (increasing only)
            // so only need to increase the maxf on counting new character (add 1)
            maxf = max(maxf, counts[s[right]]);
            while ((right - left + 1) - maxf > k) {
                counts[s[left]]--;
                left++;
            }
            
            // Update res
            res = max(res, right - left + 1);
        }
        return res;
    }
};
