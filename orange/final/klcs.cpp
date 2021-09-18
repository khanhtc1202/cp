#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 2000
 
int lcs(int dp[MAX][MAX][10], int arr1[], int n, int arr2[], int m, int k)
{
    if (k < 0)
        return -1;
 
    if (n < 0 || m < 0)
        return 0;
 
    int& ans = dp[n][m][k];
 
    if (ans != -1)
        return ans;
 
    ans = max(lcs(dp, arr1, n - 1, arr2, m, k), lcs(dp, arr1, n, arr2, m - 1, k));
 
    if (arr1[n-1] == arr2[m-1])
        ans = max(ans, 1 + lcs(dp, arr1, n - 1, arr2, m - 1, k));
 
    ans = max(ans, 1 + lcs(dp, arr1, n - 1, arr2, m - 1, k - 1));
 
    return ans;
}
 
int main()
{
    int n,m,k; cin >> n >> m >> k;
    int arr1[n], arr2[m];
    for (size_t i = 0; i < n; i++)
        cin >> arr1[i];
    for (size_t i = 0; i < m; i++)
        cin >> arr2[i];

    int dp[MAX][MAX][10];
    memset(dp, -1, sizeof(dp));
 
    cout << lcs(dp, arr1, n, arr2, m, k) << endl;
 
    return 0;
}
