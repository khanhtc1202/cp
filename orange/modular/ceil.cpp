#include <iostream>
using namespace std; 

int T; 
long long x, k; 

int main () {
	cin >> T;
	 
	for (int tt = 1; tt <= T; tt++) {
		cin >> x >> k; 

		long long p, q; 
		long long r = x % k; 
		if (r == 0) {
			p = k; 
			q = 0; 
		}
		else {
			long long a = x / k; 
			p = 1 + a - x; 
			q = x - a; 
		}

		cout << p << ' ' << q << endl; 
	}
	return 0; 
}
