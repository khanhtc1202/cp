#include <iostream>
using namespace std;
typedef long long ll;

ll solve(ll n)
{
    int cnt = 0;
    ll result = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            result = i;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        cnt++;
        result = n;
    }

    return cnt == 1 ? -1 : result;
}

int main()
{
    ll n;
    while (cin >> n, n != 0)
    {
        if (n < 0)
            cout << solve(-n) << endl;
        else
            cout << solve(n) << endl;
    }
	return 0;
}
