#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;

    BIT(): n(1e5) {
        bit.resize(n+1, 0);
    }
    
    int get(int p) {
        int ans = 0;
        for (; p > 0; p -= (p&-p)) {
            ans = max(ans, bit[p]);
        }
        return ans;
    }
    
    void update(int p, int val) {
        for (; p <= n; p += (p&-p)) {
            bit[p] = max(bit[p], val);
        }
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2) {
            return e1[0] != e2[0] ? e1[0] < e2[0] : e1[1] > e2[1]; 
        });
        
        BIT tree;
        int ans = 1;
        for (auto e: envelopes) {
            int curr = tree.get(e[1]-1) + 1;
            ans = max(ans, curr);
            tree.update(e[1], curr);
        }
        return ans;
    }
};
