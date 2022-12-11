#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        auto divisors = [](int n) -> vector<int> {
            vector<int> ans;
            for (int i = 2; i*i <= n; i++) {
                if (n % i == 0) {
                    ans.push_back(i);
                }

                while (n % i == 0) {
                    n /= i;
                }
            }

            if (n > 1) ans.push_back(n);

            return ans;
        };

        vector<vector<int>> adj(1e5+1, vector<int>());
        for (auto num: nums) {
            vector<int> tmp = divisors(num);
            for (auto x: tmp) {
                adj[x].push_back(num);
                adj[num].push_back(x);
            }
        }

        int cnt = 0;
        vector<int> visited(1e5+1, 0);
        auto DFS = [&](int s) -> void {
            stack<int> stk;
            stk.push(s);
            visited[s] = cnt;

            while (!stk.empty()) {
                int u = stk.top(); stk.pop();
                for (auto v: adj[u]) {
                    if (visited[v]) continue;
                    visited[v] = cnt;
                    stk.push(v);
                }
            }
        };
        
        for (auto num: nums) {
            if (!visited[num]) {
                cnt++;
                DFS(num); // update visited -> cnt
            }
        }

        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < nums.size(); i++) {
            if (visited[nums[i]] != visited[tmp[i]]) return false;
        }
        return true;
    }
};
