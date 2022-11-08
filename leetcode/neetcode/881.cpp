#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;
        while (i <= j) {
            ans++;

            // min and max not over the limit thus they can go on same boat.
            if (people[i] + people[j] <= limit) {
                i++;
            }
            // in case it over the limit, only max can goes on that boat,
            // thus min is stay for the next one.
            j--;
        }
        return ans;
    }
};
