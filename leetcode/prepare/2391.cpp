/*
https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const int n=garbage.size();
        const char* GPM="GPM";
        int time=0;
        bool t[3]={0}; 
        for(int i=n-1; i>0; i--){
            string&& x=move(garbage[i]);
            time += x.size();
            for(int j=0; j<3; j++){
                if (!t[j]){
                    if(x.find(GPM[j])!=-1){
                        t[j]=1;
                        time += accumulate(travel.begin(), travel.begin()+i, 0);
                    } 
                } 
            }
        }
        return time+garbage[0].size();
    }
};
