/*
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size(), p[2]={0};
        p[0]=count(students.begin(), students.end(), 0), p[1]=n-p[0];
        for (int x: sandwiches){
            if (p[x]==0) return p[1-x];
            p[x]--;
        }
        return 0;
    }
};
