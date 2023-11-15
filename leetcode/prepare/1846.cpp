/*
https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int freq[100001]={0};
        int n=arr.size();

        for(int& x:arr)
            freq[min(n, x)]++;// if x>n, set x=n
        int acc=0, j=1;

        for(int i=1; i<=n; i++){
            acc += freq[i];
            if (i < acc) 
                acc = i;
        }
        return acc;
    }
};
