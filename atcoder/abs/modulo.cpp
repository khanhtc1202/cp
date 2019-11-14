#include<iostream>

using namespace std;

int main() {
	long long x = 1;
	int m, n;
	cin >> n >> m;
        for (int i = 2; i <= n; i++) {  x = (x*i)%m; }
        cout << x%m << "\n";
	return 0;
}
