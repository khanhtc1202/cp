/*
https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        long long ans = 0, sum = 0;
        int start = 0, end = 0;
        while (end < nums.size()) {
            int x = nums[end];
            int last = seen.count(x) ? seen[x] : -1;
            while (start <= last || end - start + 1 > k) {
                sum -= nums[start];
                start++;
            }
            sum += nums[end];
            seen[x] = end;
            if (end - start + 1 == k) ans = max(ans, sum);
            end++;
        }
        return ans;
    }
};

// Better solution with oop design
class SolutionOpt {
private:
    long long sum = 0;
    int dupli = 0, cnt[100001] = {};
    void pushElement(int &num) {
        sum += num;
        if (++cnt[num] == 2) ++dupli;
    }
    void popElement(int &num) {
        sum -= num;
        if (--cnt[num] == 1) --dupli;
    }
        
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) pushElement(nums[i]);
        long long res = dupli ? 0 : sum;

        for (int i = 0; i < nums.size() - k; ++i) {
            popElement(nums[i]);
            pushElement(nums[i + k]);
            if (!dupli) res = max(res, sum);
        }

        return res;
    }
};
