#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int t, n;
int a[N], b[N];


int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        // if n is odd, there will be only one point matches the requirement.
        if (n & 1) {
            cout << 1 << endl;
            continue;
        }

        // else, find the number of point in between 2 mid points (n/2-1 and n/2)
        // then multiply them in 2D.
        sort(a, a + n), sort(b, b + n);
        ll cntx = a[n / 2] - a[n / 2 - 1] + 1;
        ll cnty = b[n / 2] - b[n / 2 - 1] + 1;
        cout << cntx * cnty << endl;
    }

    return 0;
}