#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto i : nums) ++counts[i];
        
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto & k : counts) 
            buckets[k.second].push_back(k.first);
        reverse(begin(buckets), end(buckets));
        
        vector<int> res;
        for(auto & bucket: buckets) 
            for(auto i : bucket) {
                res.push_back(i);
                if(res.size() == k) return res;
            }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,1,1,2,2,3};
    vector<int> out = sol.topKFrequent(a, 2);
    for (auto x : out)
        cout << x << ", ";
    cout << endl;
    return 0;
}
