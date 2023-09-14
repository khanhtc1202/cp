/*
https://leetcode.com/problems/reconstruct-itinerary/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flight;
        for (auto& t: tickets) {
            string from = t[0], to = t[1];
            flight[from].push(to);
        }

        deque<string> ans;
        function<void(string)> dfs = [&](string From) {
            while (!flight[From].empty()) {
                string To = flight[From].top();
                flight[From].pop();
                dfs(To);
            }
            ans.push_front(From);
        };

        dfs("JFK");
        return vector<string>(ans.begin(), ans.end());
    }
};
