#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);

        pre[0] = nums[0];
        post[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] * nums[i];
            post[n-1-i] = post[n-i] * nums[n-1-i];
        }

        vector<int> out(n);
        out[0] = post[1];
        out[n-1] = pre[n-2];
        for (int i = 1; i < n-1; i++) {
            out[i] = pre[i-1] * post[i+1];
        }
        return out;
    }

    vector<int> cumulativeSol(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n);

        out[0] = 1;
        for (int i = 1; i < n; i++) {
            out[i] = out[i-1] * nums[i];
        }

        int cumRight = 1;
        for (int i = n-1; i >= 0; i--) {
            out[i] *= cumRight;
            cumRight *= out[i];
        }
        return out;
    }
};

int main() {
    Solution sol;
    int n; cin >> n;
    vector<int> a;
    for (int& x : a) cin >> x;
    vector<int> out = sol.cumulativeSol(a);
    for (int& x : out) cout << x << ", ";
    cout << endl;
    return 0;
}
