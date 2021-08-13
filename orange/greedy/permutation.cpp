#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(i+1 - a[i]);
    cout << ans << endl;
	return 0;
}
