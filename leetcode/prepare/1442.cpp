/*
https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pref(arr.begin(), arr.end());
        pref.insert(pref.begin(), 0);
        int N = pref.size();

        for (int i = 1; i < N; ++i) pref[i] ^= pref[i-1];

        int count = 0;
        for (int s = 0; s < N; ++s) {
            for (int e = s+1; e < N; ++e) {
                if (pref[s] == pref[e])
                    count += e-s-1;
            }
        }
        return count;
    }

    int countTriplets_OnePass(vector<int>& arr) {
        unordered_map<int, int> total, cnt;
        int currXOR = 0, ans = 0;
        cnt[0] = 1;

        for (int i = 0; i < arr.size(); ++i) {
            currXOR ^= arr[i];
            // Formula based on:
            // with (start_1, start_2, ..., start_m, end) are indices which have same XOR prefix
            // ans += (end - start_1) + (end - start_2) + ... + (end - start_m)
            //     += end * m - (start_1 + start_2 + ... + start_m)
            // or = end * m - (start_1 + start_2 + ... + start_m + m)
            // and add (+1) to to after total each time we update total
            ans += i * cnt[currXOR] - total[currXOR];
            // Update cnt and total
            cnt[currXOR]++;
            total[currXOR] += i+1;
        }
        return ans;
    }
};
