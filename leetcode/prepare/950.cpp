/*
https://leetcode.com/problems/reveal-cards-in-increasing-order/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q; int n = deck.size();
        sort(deck.begin(), deck.end());
        for (int i = n-1; i >= 0; --i) {
            if (!q.empty()) {
                int x = q.front(); q.pop();
                q.push(x);
            }
            q.push(deck[i]);
        }
        vector<int> ans(n);
        for (int i = n-1; i >= 0; --i) {
            ans[i] = q.front(); q.pop();
        }
        return ans;
    }

    // Approach with radix sort and deque
    vector<int> bucket[1024];
    void radix_sort(vector<int>& nums) {
        // 1st round
        for (int x : nums)
            bucket[x&1023].push_back(x);
        int i = 0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
            B.clear();
        }
        // 2nd round
        for (int x : nums)
            bucket[x>>10].push_back(x);
        i=0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
        //    B.clear();
        }
    }
    vector<int> deckRevealedIncreasing_Deque(vector<int>& deck) {
        radix_sort(deck);
        int n=deck.size();
        deque<int> reveal={deck[n-1]};
        for(int i=n-2; i>=0; i--){
            int back=reveal.back();
            reveal.pop_back();
            reveal.push_front(back);
            reveal.push_front(deck[i]);
        }
        return vector<int>(reveal.begin(), reveal.end());
    }
};
