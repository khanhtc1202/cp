#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> tempStk;
        
        for (int i = 0; i < temperatures.size(); i++) {
            int currTemp = temperatures[i];
            while (!tempStk.empty() && tempStk.top().second < currTemp) {
                ans[tempStk.top().first] = i - tempStk.top().first;
                tempStk.pop();
            }
            tempStk.push({i, currTemp});
        }
        return ans;
    }
    vector<int> dailyTemperaturesBackward(vector<int>& temperatures) {
        int n = temperatures.size();
        int hottest = 0;
        vector<int> ans(n, 0);

        for (int i = n-1; i >= 0; i--) {
            if (hottest < temperatures[i]) {
                hottest = temperatures[i];
                continue;
            }
            int days = 1;
            while (temperatures[i + days] < temperatures[i]) {
                days += ans[i+days];
            }
            ans[i] = days;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {73,74,75,71,69,72,76,73};
    sol.dailyTemperatures(a);
    return 0;
}
