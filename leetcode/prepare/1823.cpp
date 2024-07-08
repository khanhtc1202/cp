/*
https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        function<int(int)> kill = [&](int remain) -> int {
            if (remain == 0) return 0;
            int ans = kill(remain - 1);
            return (ans + k) % remain;
        };

        return kill(n) + 1;
    }
};
