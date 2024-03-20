/*
https://leetcode.com/problems/task-scheduler/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unsigned max_freq = 0, num_maxfreq = 0;
        int sz = tasks.size();
        int freq[26] = {0};
        for (char t: tasks) {
            int f = ++freq[t-'A'];
            if (f == max_freq) num_maxfreq++;
            else if (f > max_freq) {
                max_freq = f;
                num_maxfreq = 1;
            }
        }
        // Using the elements with max freq as the pivot
        // | .... | .... |
        // Then we have (max_freq - 1) range, each cost 
        // n+1 (n is the middle and 1 for the pivot) to run
        // then we have to add other elements in between
        // | x y z ... | x y z ... | x y z
        // That is why we need to + num_maxfreq at last
        int time = (max_freq - 1) * (n+1) + num_maxfreq;
        return max(time, sz);
    }
};
