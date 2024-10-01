/*
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> modCount;
        
        for (auto x: arr) modCount[(x%k+k)%k]++; // +k for x < 0 case

        // Need even number of mod0 or it's false
        if (modCount[0] % 2 == 1) return false;
        
        for (auto x: arr) {
            int mod = (x % k + k) % k;
            // If impossible to make all {mod, k-mod} pair, then it's false
            if (mod != 0 && modCount[mod] != modCount[k-mod]) {
                return false;
            }
        }
        return true;
    }
};
