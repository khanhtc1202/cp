/*
https://leetcode.com/problems/hand-of-straights/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        
        map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[hand[i]]++;
        }
        
        while (!hash.empty()) {
            int curr = hash.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                int need = curr+i;
                if (hash[need] == 0) return false;  
                hash[need]--;
                if (hash[need] == 0) hash.erase(need);
            }
        }
        return true;
    }
};
