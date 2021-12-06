#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 20000

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

const int INF = 1e9;

int sum(int n) {
    return n*(n+1)/2;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int x = (240 - k) / 5;
    int l = 0, r = n, ans = 0;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (sum(m) > x) {
            r = m - 1;
            continue;
        }
        if (sum(m) < x) {
            ans = m;
            l = m + 1;
            continue;
        }
        ans = m;
        break;
    }
    cout << ans << endl;
    
	return 0;
}
