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

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int m = (n % 2) ? (n / 2 + 1) : (n / 2);
        int ans = s / (n-m+1);
        cout << ans << endl;
    }
    
	return 0;
}
