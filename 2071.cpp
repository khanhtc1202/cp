/*
https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto assignable = [&](int k) -> bool {
            int p = pills;
            multiset<int> ws; // BST stores workers
            // pick k strongest workers
            for (int i = m - k; i < m; ++i) {
                ws.insert(workers[i]);
            }
            // Try to assign k smallest tasks
            for (int i = k - 1; i >= 0; --i) {
                if (auto it = prev(ws.end()); *it >= tasks[i]) {
                    // Assign biggest task to the strongest worker if possible
                    ws.erase(it);
                } else {
                    if (!p) {
                        return false; // no more pill;
                    }
                    // Find the weakest worker that still fit the task after take the pill
                    auto as = ws.lower_bound(tasks[i] - strength);
                    if (as == ws.end()) {
                        return false; // no worker can fit even after pill
                    }
                    --p; // take pill
                    ws.erase(as);
                }
            }
            return true;
        };

        int l = 1, r = min(n, m), ans = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            if (assignable(mid)) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};
