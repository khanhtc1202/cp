#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n <=0) break;

		queue<int> desk;
		for (int i = 1; i <= n; i++) {
			desk.push(i);
		}

		cout << "Discarded cards:";
		while (desk.size() > 1) {
			cout << " " << desk.front();
			if (desk.size() != 2) cout << ",";
			desk.pop();
			int roll = desk.front();
			desk.pop();
			desk.push(roll);
		}
		cout << "\nRemaining card: " << desk.front() << endl;
	}
	return 0;
}