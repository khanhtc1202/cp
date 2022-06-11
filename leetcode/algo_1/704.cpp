#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m;

        while (l <= r) {
            m = (l+r)/2;
            if (nums[m] == target) return m;
            if (nums[m] < target) {
                l = m + 1;
                continue;
            }
            if (nums[m] > target) {
                r = m - 1;
                continue;
            }
        }
        return -1;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int tar; cin >> tar;

    Solution sol;
    cout << sol.search(a, tar) << endl;
    return 0;
}
