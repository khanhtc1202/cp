/*
https://leetcode.com/problems/find-in-mountain-array/
*/
#include <bits/stdc++.h>
using namespace std;

// You should not implement it, or speculate about its implementation
class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=1, r=n-2, m, peak;

        while(l<r){
            m=l+(r-l)/2;
            int xl=mountainArr.get(m-1), 
            x=mountainArr.get(m),xr=mountainArr.get(m+1);
            if (xl<x && x>xr) {
                peak=m;
                break;
            }
            else if (x<xr)
                l=m+1;
            else
                r=m-1;
        }
        // Keep peak
        peak=r;

        // find in increasing part
        l=0, r=peak;
        while(l<r){
            m=l+(r-l)/2;
            int x=mountainArr.get(m);
            if (x==target) return m;
            else if (x<target) l=m+1;
            else r=m;
        }

        // find in decreasing part
        l=peak, r=n;
        while(l<r){
            m=l+(r-l)/2;
            int x=mountainArr.get(m);
            if (x==target) return m;
            else if (x>target) l=m+1;
            else r=m;
        }
        return -1;
    }
};
