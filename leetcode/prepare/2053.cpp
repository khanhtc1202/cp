/*
https://leetcode.com/problems/kth-distinct-string-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for (int i = 0; i < arr.size(); ++i) {
            if (cnt.count(arr[i]) == 0) cnt[arr[i]] = 1;
            else cnt[arr[i]]++;
        }

        int uniquePos = 0;
        string ans = "";

        for (int i = 0; i < arr.size(); ++i) {
            if (cnt[arr[i]] == 1) {
                uniquePos++;
                if (uniquePos == k) {
                    ans = arr[i];
                    break;
                }
            }
        }
        return ans;
    }
};
