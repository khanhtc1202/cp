#include <iostream>
using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result = result / i * (i - 1);
        }
    }
    if (n > 1)
        result = result / n * (n - 1);
    return result;
}

int main()
{
    int n;
    while (cin >> n, n != 0)
    {
        cout << phi(n) << endl;
    }
	return 0;
}
