/*
https://leetcode.com/problems/lexicographical-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            ans.push_back(curr);
            // Build next element
            // Add 0 to the end keep head if it's possible
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                // If impossible to moving up one last digit, remove it
                while (curr % 10 == 9 || curr >= n) {
                    curr /= 10;
                }
                // Then increase digit by one
                curr += 1;
            }
        }
        return ans;
    }
};
