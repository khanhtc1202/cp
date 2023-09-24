/*
https://leetcode.com/problems/champagne-tower/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0;
        vector<double> row(query_row+2, 0);
        row[0] = poured;
        // Loop tils query_row - 1 gen all the query_row ans.
        for (int i = 0; i < query_row; ++i) {
            // Run backward so that we update most right glass
            // and not override self glass on left which store
            // previous row values.
            for (int j = i; j >= 0; --j) {
                double exc = max((row[j]-1)/2.0, 0.0);
                row[j] = exc;
                row[j+1] += row[j];
            }
        }
        return min(1.0, row[query_glass]);
    }
};
