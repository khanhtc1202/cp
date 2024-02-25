/*
https://leetcode.com/problems/greatest-common-divisor-traversal/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getf(vector<int>& f, int x) {
        return f[x] == x ? x : (f[x] = getf(f, f[x]));
    }

    void merge(vector<int>& f, vector<int>& num, int x, int y) {
        x = getf(f, x);
        y = getf(f, y);

        if (x == y) return;
        if (num[x] < num[y]) swap(x, y);

        // Update frequency
        f[y] = x;
        num[x] += num[y];
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return true;

        vector<int> f(n), num(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            num[i] = 1;
        }

        // First index by prime factor
        unordered_map<int, int> have;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 1) return false;

            for (int d = 2; d*d <= x; ++d) {
                if (x % d == 0) {
                    if (have.count(d)) {
                        merge(f, num, i, have[d]);
                    } else {
                        have[d] = i;
                    } while (x % d == 0) {
                        x /= d;
                    }
                }
            }

            if (x > 1) {
                // x is prime
                if (have.count(x)) {
                    merge(f, num, i, have[x]);
                } else {
                    have[x] = i;
                }
            }
        }

        // True if all indices belong to the same connected component
        return num[getf(f, 0)] == n;
    }
};
