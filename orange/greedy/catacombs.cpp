#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n+1), a(n+1);
    for (int i = 1; i < n+1; i++)
        cin >> t[i];
    int x = 1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0) a[i] = x, x++;
        if (a[t[i]] == 0) a[t[i]] = x;
    }
    cout << x - 1 << endl;
	return 0;
}
