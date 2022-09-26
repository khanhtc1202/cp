#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7;
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size()-2; i++) {
            int rest = target - arr[i];
            if (rest < 0) continue;
            
            int l = i+1, r = arr.size()-1;
            while (l < r) {
                int curr = arr[l] + arr[r];
                if (curr < rest) {
                    l++;
                } else if (curr > rest) {
                    r--;
                } else if (arr[l] != arr[r]) {
                    int cl = 1, cr = 1;
                    while (l+1 < r && arr[l+1] == arr[l]) {
                        cl++; l++;
                    }
                    while (r-1 > l && arr[r-1] == arr[r]) {
                        cr++; r--;
                    }
                    ans += (cl*cr);
                    l++; r--;
                } else {
                    ans += (r-l+1) * (r-l) / 2;
                    l = r; // end of while loop
                }
            }
            ans %= mod;
        }
        return ans;
    }
};
