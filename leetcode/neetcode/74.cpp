/*
https://leetcode.com/problems/search-a-2d-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int l = 0, r = n - 1, m;
        while (l <= r) {
            m = (l+r)/2;
            if (target == matrix[m][0]) return true;
            if (target < matrix[m][0])
                r = m-1;
            else
                l = m+1;
        }

        int row = r;
        n = matrix[0].size();
        l = 0, r = n-1;
        while (l <= r) {
            m = (l+r)/2;
            if (target == matrix[row][m]) return true;
            if (target < matrix[row][m])
                r = m-1;
            else
                l = m+1;
        }
        return false;
    }

    bool searchMatrixSimple(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n*m-1, mid;
        int curr;
        while (left <= right) {
            mid = left + (right-left)/2;
            curr = matrix[mid/m][mid%m];
            if (curr == target) return true;
            if (curr < target) left = mid+1;
            else right = mid - 1;
        }
        return false;
    }
};
