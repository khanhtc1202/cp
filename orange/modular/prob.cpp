#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int maxx  = 2000005;
const long long mod = 1000000007;
long long fact[maxx];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxx; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

long long modularExponentiation(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return res;
}

long long modInverse(long long b, long long m) {
    long long res = modularExponentiation(b, m - 2, m);
    if (res * b % m == 1)
        return res;
    return -1;
}

long long getC(long long n, long long k) {
    long long nu = fact[n + k - 1];
    long long de = (fact[n] * fact[k - 1]) % mod;
    return (nu * modInverse(de, mod)) % mod;
}

int main() {
    init();
    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        long long n, k;
        cin >> n >> k;
        cout << "Case " << tt << ": " << getC(n, k) << endl;
    }
    return 0;
}
