#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> dp, path;
int last = -1;

void printV(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

int lowerBound(const vector<int> &a, const vector<int> &sub, int n, int x)
{
    int left = 0, right = n;
    int pos = right;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (a[index] < x)
        {
            pos = mid;
            right = mid;
        }
        else
            left = mid + 1;
    }
    return pos;
}

int LIS_Bin(const vector<int>& a)
{
    int length = 1;
    dp.clear();
    path.assign(a.size(), -1);
    dp.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] >= a[dp[0]])
        {
            dp[0] = i;
        }
        else if (a[i] <= a[dp[length - 1]])
        {
            path[i] = dp[length - 1];
            dp.push_back(i);
            length++;
        }
        else
        {
            int pos = lowerBound(a, dp, length, a[i]);
            path[i] = dp[pos - 1];
            dp[pos] = i;
        }
    }
    return length;
}

int LIS(const vector<int>& a)
{
    int length = 0;
    path = vector<int>(a.size(), -1);
    dp = vector<int>(a.size(), 1);
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] <= a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (length < dp[i])
        {
            last = i;
            length = dp[i];
        }
    }
    return length;
}

int main()
{
    int x, test = 1;
    bool end_of_test = false;
    vector<int> a;
    while (cin >> x)
    {
        if (x == -1 && end_of_test)
            break;
        
        if (x == -1)
        {
            cout << "Test #" << test << ":" << endl;
            cout << "  maximum possible interceptions: " << LIS(a) << endl;
            cout << endl;
            // reset
            // cout << "DP" << endl;
            // printV(dp);
            // printV(path);
            end_of_test = true;
            a.clear();
            test++;
            continue;
        }
        
        end_of_test = false;
        a.push_back(x);
    }
    
	return 0;
}
