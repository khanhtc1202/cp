/*
https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int _min = *min_element(arr.begin(), arr.end());
        int _max = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if ((_max - _min) % (n-1) != 0) return false;

        int diff = (_max - _min) / (n-1);
        int i = 0;
        while (i < n) {
            if (arr[i] == _min + i * diff) // right in place
                i++;
            else if ((arr[i] - _min) % diff != 0) // no index valid
                return false;
            else {
                int j = (arr[i] - _min) / diff;
                if (arr[i] == arr[j]) // duplicated
                    return false;
                swap(arr[i], arr[j]);
            }
        }
        return true;
    }
};
