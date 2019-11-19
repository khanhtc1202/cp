#include<iostream>
using namespace std;

int main() {
	int best = 0, sum = 0, n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int a_k;
		cin >> a_k;
		sum = max(a_k, sum + a_k);
		best = max(best, sum);
	}
	cout << "max => " << best << "\n";
}
