#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> out;
        for (int i = 0; i < numbers.size(); i++) {
            int l = i+1, r = numbers.size()-1;
            int m, x = target - numbers[i];
            while (l <= r)
            {
                m = l + (r-l)/2;
                if (x == numbers[m]) {
                    out.push_back(i+1);
                    out.push_back(m+1);
                    goto L;
                }
                if (x < numbers[m]) {
                    r = m - 1;
                    continue;
                } else {
                    l = m + 1;
                    continue;
                }
            }
        }
L:
        return out;
    }

    vector<int> twoSumOn(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() -1;
        while (numbers[lo]+numbers[hi] != target) {
            if (numbers[lo]+numbers[hi] > target) hi--;
            else lo++;
        }
        return vector<int>({lo+1, hi+1});
    }
};

int main() {
    return 0;
}
