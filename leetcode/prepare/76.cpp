/*
https://leetcode.com/problems/minimum-window-substring/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string& s, string& t) {
        int n = s.size(), tn= t.size();
        int left = 0, right;
        int mp[64]={0}, tmp[64]={0};
        
        // Count the characters in string t
        for (char c : t){
            int idx=0x3f &c;
            tmp[idx]++;
        }
        
        int count = 0; // Counter for matching characters
        
        int minLength = INT_MAX; // Length of the minimum window
        int minLeft = 0; // Start index of the minimum window
        
        for (right = 0; right < n; right++) {
            char c = s[right];
            int idx= 0x3f & c;
            // Skip characters not present in string t
            if (tmp[idx] == 0) continue;
            
            // Increment the count of matching characters
            mp[idx]++;
            
            // Check if the current character count matches the required count
            if (mp[idx] <= tmp[idx]) count++;
            
            // If all characters of t are found in the current window
            if (count == tn) {
                // Try to minimize the window by moving the left pointer
                int idx_left;
                while (tmp[idx_left=(0x3f& s[left])]==0|| mp[idx_left]>tmp[idx_left]) {
                    if (mp[idx_left]!=0) mp[idx_left]--;
                    left++;
                }
               // cout<<"["<<left<<","<<right<<"]:"<<s.substr(left, right-left+1)<<endl;
                // Update the minimum window if necessary
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
            }
        }
        
        // If no valid window found, return an empty string
        if (minLength == INT_MAX) return "";
        
        // Return the minimum window substring
        return move(s.substr(minLeft, minLength));
    }
};
