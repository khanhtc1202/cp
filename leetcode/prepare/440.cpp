/*
https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, d, k;
    vector<int> noPer;
    bool isPerfect;
    long long perfect[10] = {1,         11,          111,     1111,
                             11111,     111111,      1111111, 11111111,
                             111111111, 1111111111LL};
    long long tens[11] = {1,         10,         100,          1000,
                          10000,     100000,     1000000,      10000000,
                          100000000, 1000000000, 10000000000LL};

    // Function to count the  nodes in the lexicographical tree rooted at x
    int cntNodes(long long x, int dx) {
        int hx=d-dx;     // tree height for tree rooted at x
        hx-=(x>noPer[dx]); // Adjust height if x exceeds noPer[dx]

        // If the tree rooted at x is perfect, use the perfect[] array
        if (isPerfect ||x != noPer[dx]) {
            return perfect[hx];
        }

        // Otherwise, compute normally by iterating through the levels
        long long curr = x;
        long long next = x+1;
        int cnt = 0;
        while (curr <= n) {
            cnt+= min(n + 1LL, next)-curr; // Count the nodes in [curr, next)
            curr*= 10;  // Go to the next level
            next*= 10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        this->n = n;
        this->k=k;
        d=log10(n);
        isPerfect=(n+1==tens[d+1]);
        noPer.assign(d+1, INT_MAX);
        if (!isPerfect){
            for (int i=0, z=n; i <= d; z/=10, i++) 
                noPer[d-i]=z;
        }
        
        int curr=1, level=0;
        k--; // starting at 1

        while (k > 0) {
            int num=cntNodes(curr, level); // Count nodes in the tree rooted at curr
            if (num <= k) {
                curr++; // Move to the next sibling node
                k -= num;
            } 
            else {
                curr*=10; // Move to the leftmost child node
                level++;
                k--;
            }
        }
        return curr;
    }
};
