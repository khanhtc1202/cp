#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        auto cal = [=](int n) -> int {
            int res = 0, digit;
            while (n > 0) {
                digit = n % 10;
                res += digit*digit;
                n = n / 10;
            }
            return res;
        };
        
        // // using set
        // unordered_set<int> seen;
        // seen.insert(n);
        // while (true) {
        //     n = cal(n);
        //     if (seen.count(n)) break;
        //     seen.insert(n);
        // }
        // return n == 1;
        
        // // two pointers
        // int slow = n;
        // int fast = cal(n);
        // while (slow != fast) {
        //     slow = cal(slow);
        //     fast = cal(cal(fast));
        // }
        // return fast == 1;
        
        // cheating :)
        while (n > 9)
            n = cal(n);
        return n == 1 || n == 7;
    }
};
