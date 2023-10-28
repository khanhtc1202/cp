/*
https://leetcode.com/problems/count-vowels-permutation/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
using ll = long long;
ll MOD = 1e9+7;
public:
    int countVowelPermutation(int n) {
        ll a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int j = 1; j < n; ++j) {
            ll a_next = e;
            ll e_next = (a+i) % MOD;
            ll i_next = (a+e+o+u) % MOD;
            ll o_next = (i+u) % MOD;
            ll u_next = a;

            a = a_next, e = e_next, i = i_next, o = o_next, u = u_next;
        }
        return (a+e+i+o+u) % MOD;
    }
};

// a-> {e}
// e-> {a,i}
// i-> {a,e,o,u}
// o-> {i,u}
// u-> {a}
