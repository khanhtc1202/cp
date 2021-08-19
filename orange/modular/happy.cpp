#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, m, b, g, x;
    bool hp_boy[101] = {}, hp_girl[101] = {};
    cin >> n >> m;

    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> x;
        hp_boy[x] = true;
    }

    cin >> g;
    for (int i = 0; i < g; i++)
    {
        cin >> x;
        hp_girl[x] = true;
    }

    int res = n + m - b - g;
    int lcm = n * m / gcd(n, m);

    for (int i = 0; i < 2 * lcm; i++)
    {
        if (hp_boy[i%n] + hp_girl[i%m] == 1)
        {
            hp_boy[i%n] = hp_girl[i%m] = true;
            res--;
        }
    }

    cout << (res == 0 ? "Yes" : "No") << endl;
	return 0;
}
