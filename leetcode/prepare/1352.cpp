/*
https://leetcode.com/problems/product-of-the-last-k-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    vector<int> prefix;
    int size = 0;
public:
    ProductOfNumbers() {
        prefix.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            prefix = {1};
            size = 0;
        } else {
            prefix.push_back(prefix[size]*num);
            ++size;
        }
    }
    
    int getProduct(int k) {
        if (k > size) return 0;
        return prefix[size] / prefix[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
