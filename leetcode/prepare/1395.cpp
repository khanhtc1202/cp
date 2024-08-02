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

    int numTeams_Opt(vector<int>& rating) {
        const int n=rating.size();
        const int m=*max_element(rating.begin(), rating.end());

        FenwickTree L(m+1), R(m+1);

        for(int x: rating) R.update(x, 1);

        int cnt=0;
        for(int x: rating){
            R.update(x, -1);// remove x from R

            int LLess=L.sum(x-1);
            int RLess=R.sum(x-1);
            int LBigger=L.sum(x+1, m);
            int RBigger=R.sum(x+1, m);

            cnt+=LLess*RBigger+LBigger*RLess;

            L.update(x, 1);// add x to L
        }
        return cnt;
    }
};

// Or Binary Indexes Tree (BIT)
struct FenwickTree{
    vector<int> BIT;
    int n;
    FenwickTree(int n): n(n), BIT(n){}

    void update(int idx, int x){
        for (; idx<n; idx=idx|(idx+1))
            BIT[idx] += x;
    }

    int sum(int idx){
        int ans = 0;
        for (; idx>= 0; idx=(idx&(idx+1))-1)
            ans+=BIT[idx];
        return ans;
    }

    int sum(int l, int r){
        return sum(r)-sum(l-1);
    }
};
