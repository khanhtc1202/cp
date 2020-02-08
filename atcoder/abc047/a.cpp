#include<iostream>
#include<set>
using namespace std;

int main() {
	set<int> s;
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		int a; cin >> a;
		sum += a;
		s.insert(a);
	}
	if (sum % 2 == 0 && s.count(sum/2)) { cout << "Yes\n"; return 0; }
	cout << "No\n";
}

