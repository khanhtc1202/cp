#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (profit < prices[i] - minp) {
                profit = prices[i] - minp;
            }
            minp = min(minp, prices[i]);
        }
        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> p = {7,5,4,3};
    cout << sol.maxProfit(p) << endl;
    return 0;
}
