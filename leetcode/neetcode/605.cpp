#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        if (n > sz/2 + 1) return false;
        for (int i = 0; i < sz; i++) {
            if (n == 0) return true;
            if (flowerbed[i] != 0) continue;
            
            bool leftEmpty = (i == 0) || flowerbed[i-1] == 0;
            bool rightEmpty = (i == sz-1) || flowerbed[i+1] == 0;
            
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};
