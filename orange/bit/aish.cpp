#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n+1, 0);
	vector<int> oneCnt(n+1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i+1];
		oneCnt[i+1] = v[i+1] == 1 ? oneCnt[i] + 1 : oneCnt[i];
	}
	
	int q;
	cin >> q;
	int l, r;
	while (q--)
	{
		cin >> l >> r;
		int no1 = oneCnt[r] - oneCnt[l-1];
		int xorVal = no1 & 1;
		int no0 = r - l + 1 - no1;
		cout << xorVal << " " << no0 << endl;
	}
	

	return 0;
}
