#include <bits/stdc++.h>
using namespace std;

#define PRINT_ARR(a, n) do {           \
    for (int i = 0; i < n; i++) {      \
        cout << a[i] << ", ";          \
    }                                  \
    cout << endl;                      \
} while(0)

class Solution {
public:
    int getMaxLen_Greedy(vector<int>& nums) {        
        int n = nums.size();
        nums.push_back(0);
        int head = -1, min_idx = -1, max_idx = -1;
        int count = 0, max_len = 0;
        for (int i = 0; i <= n; i++){
            if (nums[i] != 0) {
                if (head == -1) head = i;
                if (nums[i] < 0) {
                    count++;
                    if (min_idx == -1) min_idx = i;
                    max_idx = i;
                }
            }

            if (nums[i] == 0) {
                if (head == -1) continue;
                int len = i - head;
                if (count % 2 == 0) {
                    max_len = max(max_len, len);
                } else {
                    int left = len - (min_idx - head + 1);
                    int right = len - (i - max_idx);
                    max_len = max({max_len, left, right});
                }
                head = min_idx = max_idx = -1;
                count = 0;
            }
        }
        return max_len;
    }

    int getMaxLen_DP(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg(n, 0), pos(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                neg[i] = (i == 0 ? 1 : pos[i-1] + 1);
                pos[i] = (i == 0 ? 0 : neg[i-1] + 1);
            } else if (nums[i] > 0) {
                neg[i] = (i == 0 ? 0 : neg[i-1] + 1);
                pos[i] = (i == 0 ? 1 : pos[i-1] + 1);
            } else {
                neg[i] = pos[i] = 0;
            }
        }
        // PRINT_ARR(neg, n);
        return *max_element(pos.begin(), pos.end());
    }

    int getMaxLen_PreSum(vector<int>& nums) {
        return 0;
    }
};

int main()
{
    Solution sol;
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    cout << sol.getMaxLen_Greedy(a) << endl;
    cout << sol.getMaxLen_DP(a) << endl;
    // cout << sol.getMaxLen_PreSum(a) << endl;
    return 0;
}