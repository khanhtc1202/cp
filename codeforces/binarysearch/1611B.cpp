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

int ans(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    if (a / b >= 3) {
        return b;
    }
    if (a == b) {
        return a / 2;
    }
    int x = (3*b - a) % 2 ? (3*b - a) / 2 + 1 : (3*b - a) / 2;
    return b - x + x / 2;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << ans(a, b) << endl;
    }
    
	return 0;
}
