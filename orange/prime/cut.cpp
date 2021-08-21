#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratos(int n)
{
    vector<bool> mark;
    vector<int> primes;
    mark.resize(n + 1, true);
    mark[0] = mark[1] = false;
    for (int i = 2; i*i <= n; i++)
    {
        if (mark[i] == true)
            for (int j = i*i; j <= n; j+= i)
                mark[j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (mark[i] == true)
            primes.push_back(i);
    return primes;
}

void printv(vector<int> &v, int s, int l)
{
    for (int i = s; i < s+l; i++)
        cout << v[i] << " ";
}

int main()
{
    int n, c;
    while (cin >> n >> c)
    {
        vector<int> primes = sieveOfEratos(n);
        if (n & 1)
        {
            int id_1 = (n-1) / 2 - c + 1;
            if (id_1 < 0)
                printv(primes, 0, primes.size());
            else
                printv(primes, id_1, 2*c - 1);
        }
        else
        {
            int id_1 = n / 2 - c;
            if (id_1 < 0)
                printv(primes, 0, primes.size());
            else
                printv(primes, id_1, 2*c);
        }
    }
    
	return 0;
}
