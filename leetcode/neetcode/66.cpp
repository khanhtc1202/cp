#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry, tmp, digit;
        for (int i = digits.size() - 1; i > -1; i--) {
            tmp = i == digits.size() - 1 ? digits[i] + 1 : digits[i] + carry;
            carry = tmp / 10;
            res.push_back(tmp % 10);
        }
        if (carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> plusOneInPlace(vector<int>& digits) {
        int n = digits.size();

        for (int i = n-1; i >= 0; i--) {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        // at this place all digits in digits was 9.
        vector<int> res(n+1, 0);
        res[0] = 1;
        return res;
    }
};
