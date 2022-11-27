#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
#define m ((l + r) >> 1)
#define lc (i << 1) + 1
#define rc (i << 1) + 2
    vector<int> sum;
    int n;

    SegmentTree(int n = 0) : n(n){    
        sum.resize(4 * n + 1, 0);
    }

    void update(int i, int l, int r, int p, int val){
        if (l == r){
            sum[i] += val;
            return;
        }  
        if (p <= m) update(lc, l, m, p, val); 
        else update(rc, m + 1, r, p, val);
        sum[i] = sum[lc] + sum[rc];
    }
    
    int get(int i, int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return sum[i];
        return get(lc, l, m, u, v) + get(rc, m + 1, r, u, v);
    }

    void update(int p, int val){
        update(0, 0, n - 1, p, val);
    }

    int get(int l, int r){
        return get(0, 0, n - 1, l, r);
    }
#undef m
#undef lc
#undef rc  
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<long long> tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            tmp.push_back(2ll * nums[i]);
        }
        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
        
        SegmentTree tree(tmp.size());
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int need = lower_bound(tmp.begin(), tmp.end(), 2ll * nums[i]) - tmp.begin();
            ans += tree.get(need+1, tmp.size()-1);
            tree.update(lower_bound(tmp.begin(), tmp.end(), 1ll * nums[i]) - tmp.begin(), 1);
        }
        return ans;
    }
};
