/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n);
        int i = 0, j = n-1;

        for (int p = n - 1; p >= 0; p--) {
            if (abs(nums[i]) > abs(nums[j])) {
                out[p] = nums[i] * nums[i];
                i++;
            } else {
                out[p] = nums[j] * nums[j];
                j--;
            }
        }
        return out;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    Solution sol;
    vector<int> out = sol.sortedSquares(a);
    for (int& x : out) cout << x << ", ";
    cout << endl;
    return 0;
}
