/*
https://leetcode.com/problems/number-of-orders-in-the-backlog/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell;

        for (auto& order: orders) {
            if (order[2] == 0)
                buy.push(make_pair(order[0], order[1]));
            else
                sell.push(make_pair(order[0], order[1]));

            while (!buy.empty() && !sell.empty() && sell.top().first <= buy.top().first) {
                int k = min(buy.top().second, sell.top().second);
                auto [price, amount] = buy.top(); buy.pop();
                amount -= k;
                if (amount) buy.push(make_pair(price, amount));

                auto [_price, _amount] = sell.top(); sell.pop();
                _amount -= k;
                if(_amount) sell.push(make_pair(_price, _amount));
            }
        }

        int res = 0, mod = 1e9+7;
        while (!sell.empty())
            (res += sell.top().second) %= mod, sell.pop();
        while (!buy.empty())
            (res += buy.top().second) %= mod, buy.pop();

        return res;
    }
};
