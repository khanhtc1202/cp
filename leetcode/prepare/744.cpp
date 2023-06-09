/*
https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (letters[mid] <= target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l == letters.size() ? letters[0] : letters[l];

        // auto it = upper_bound(letters.begin(), letters.end(), target);
        // return it == letters.end() ? letters[0] : *it;
    }
};
