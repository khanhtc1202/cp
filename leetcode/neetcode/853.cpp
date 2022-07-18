#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end());

        stack<pair<int, int>> stk;
        for (int i = cars.size()-1; i >= 0; i--) {
            if (stk.empty()) {
                stk.push(cars[i]);
                continue;
            }
            if (!catched(target, stk.top(), cars[i]))
                stk.push(cars[i]);
        }
        return stk.size();
    }
private:
    bool catched(int target, pair<int, int> car1, pair<int, int> car2) {
        return float(target - car1.first) / car1.second >= float(target - car2.first) / car2.second;
    }
};
