/*
https://leetcode.com/problems/count-number-of-teams/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int N = rating.size();
        int ans = 0;

        for (int mid = 0; mid < N; ++mid) {
            int leftSmaller = 0;
            int rightLarger = 0;

            for (int left = mid-1; left >= 0; --left) {
                if (rating[left] < rating[mid])
                    leftSmaller++;
            }

            for (int right = mid+1; right < N; ++right) {
                if (rating[right] > rating[mid])
                    rightLarger++;
            }

            int leftLarger = mid - leftSmaller;
            int rightSmaller = N - mid - 1 - rightLarger;

            ans += (leftSmaller * rightLarger + leftLarger * rightSmaller);
        }
        return ans;
    }
};
