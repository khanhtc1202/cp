/*
https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(string strNum, int target) {
        // Valid Partition Found
        if (strNum == "" && target == 0) return true;

        // Invalid Partition Found
        if (target < 0) return false;

        // Recursively check all partitions for a valid partition
        for (int index = 0; index < strNum.size(); index++) {
            string left = strNum.substr(0, index + 1);
            string right = strNum.substr(index + 1);
            int leftNum = stoi(left);

            if (canPartition(right, target - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int pNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currNum = 1; currNum <= n; currNum++) {
            int sqrNum = currNum * currNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (canPartition(to_string(sqrNum), currNum)) {
                pNum += sqrNum;
            }
        }
        return pNum;
    }
};

// Memorization
class Solution1 {
public:
    bool checkValid(int startIndex, int sum, string strNum, int target, vector<vector<int>>& memo) {
        // End of current branch reach the end of string
        if (startIndex == strNum.size()) {
            return sum == target;
        }

        if (sum > target) return false; // acc sum over target

        if (memo[startIndex][sum] != -1) return memo[startIndex][sum]; // memorization

        bool valid = false;
        for (int currIndex = startIndex; currIndex < strNum.size(); ++currIndex) {
            string partition = strNum.substr(startIndex, currIndex - startIndex + 1);
            int added = stoi(partition);

            valid = valid || checkValid(currIndex+1, sum+added, strNum, target, memo);
            if (valid) return true; // current branch leads to valid split output
        }

        return memo[startIndex][sum] = valid;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int currNum = 1; currNum <= n; ++currNum) {
            int square = currNum * currNum;
            string strNum = to_string(square);
            // memo of size [stringNumSize][currNum+1] of [startIndex][sum]
            vector<vector<int>> memo(strNum.size(), vector<int>(currNum+1, -1));
            if (checkValid(0, 0, strNum, currNum, memo)) {
                ans += square;
            }
        }
        return ans;
    }
};
