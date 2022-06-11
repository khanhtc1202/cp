#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m;
        while (l < r) {
            m = l + (r - l)/2;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }

    bool isBadVersion(int n) {
        return n % 2;
    }
};

int main() {
    return 0;
}
