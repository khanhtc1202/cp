#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int r = k % n;
        int p = n - 1 - r;

        vector<int> out(n);
        for (int i = p, j = n-1; i >= 0; i--, j--) {
            out[j] = nums[i];
        }
        for (int i = n-1, j = n-p+1; i > p; i--, j--) {
            out[j] = nums[i];
        }
        nums = out;
    }
};

int main() {
    return 0;
}
