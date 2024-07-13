/*
https://leetcode.com/problems/robot-collisions/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using int2=pair<int, int>;// (position, idx)
    static vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        const int n=positions.size();
        vector<int2> robot(n);
        for(int i=0; i<n; i++)// 0-indexed is fine
            robot[i]={positions[i], i};
        sort(robot.begin(), robot.end());

        int* stack=(int*)alloca(sizeof(int)*n);// allocate with a stack
        int top=-1;
        for(auto& [_, i]: robot){
            if (directions[i]=='R') stack[++top]=i;
            else{
                while(top!=-1 && healths[i]>0){
                    int j=stack[top];
                    int x=healths[j]-healths[i];
                    if (x>0) healths[j]--, healths[i]=0;
                    else if (x<0) healths[j]=0, healths[i]--, top--;
                    else healths[i]=healths[j]=0, top--;
                }
            }
        }
        vector<int> ans;
        for(int x: healths)
            if (x>0) ans.push_back(x);
        return ans;
    }
};
