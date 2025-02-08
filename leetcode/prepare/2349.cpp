/*
https://leetcode.com/problems/design-a-number-container-system/
*/
#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int, set<int>> numberToIndecies;
    unordered_map<int, int> indexToNumber;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int prev = indexToNumber[index];
            numberToIndecies[prev].erase(index);
            if (numberToIndecies[prev].empty()) {
                numberToIndecies.erase(prev);
            }
        }
        indexToNumber[index] = number;
        numberToIndecies[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndecies.find(number) != numberToIndecies.end()) {
            return *numberToIndecies[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
