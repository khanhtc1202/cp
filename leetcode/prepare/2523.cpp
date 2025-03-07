/*
https://leetcode.com/problems/closest-prime-numbers-in-range/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, closetA = -1, closetB = -1;
        int ans = 1e6;
        for (int x = left; x <= right; ++x) {
            if (isPrime(x)) {
                if (prevPrime != -1) {
                    int diff = x - prevPrime;
                    if (diff < ans) {
                        ans = diff;
                        closetA = prevPrime;
                        closetB = x;
                    }
                    // If ans == 1 or 2 then it's smallest
                    if (ans == 2 || ans == 1)
                        return {prevPrime, x};
                }
                prevPrime = x;
            }
        }
        return (closetA == -1) ? vector<int>{-1, -1} : vector<int>{closetA, closetB};
    }
private:
    bool isPrime(int number) {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0) return false;
        for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
            if (number % divisor == 0) return false;
        }
        return true;
    }
};
