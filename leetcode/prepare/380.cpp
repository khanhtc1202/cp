/*
https://leetcode.com/problems/insert-delete-getrandom-o1/
*/
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> S;
    vector<int> idx;
    int sz=0;
    mt19937 rng; // Mersenne Twister random number engine
public:
    RandomizedSet() {
        rng= mt19937(time(NULL));
    }

    bool insert(int val) {
        if (S.count(val)) return 0;

        S[val]=sz++;
        idx.push_back(val);
        return 1;
    }

    bool remove(int val) {
        if (!S.count(val)) return 0;

        int r=idx.back();
        int pos=S[val];

        S[r]=pos;
        idx[pos]=r;

        S.erase(val);
        idx.pop_back();
        sz--;

        return 1;
    }

    int getRandom() {
        return idx[rng()%sz];
    }
};
