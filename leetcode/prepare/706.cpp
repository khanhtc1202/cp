/*
https://leetcode.com/problems/design-hashmap/description/
*/
#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
vector<int> store;
public:
    MyHashMap(): store(1e6+1, -1) {}
    
    void put(int key, int value) {
        store[key] = value;
    }
    
    int get(int key) {
        return store[key];
    }
    
    void remove(int key) {
        store[key] = -1;
    }
};
