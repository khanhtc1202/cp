#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt_e = 0, cnt_l = 0, cnt_m = 0;
	string line;
	for (int i = 0; i < n; i++)
	{
        cin >> line;
		if ("Emperor" == line) cnt_e++;
		else if ("Macaroni" == line) cnt_m++;
		else if ("Little") cnt_l++;
        cin >> line;
	}
	int bst = cnt_e;
	bst = max(bst, cnt_m);
	bst = max(bst, cnt_l);
	if (bst == cnt_e) cout << "Emperor Penguin" << endl;
	else if (bst == cnt_m) cout << "Macaroni Penguin" << endl;
	else cout << "Little Penguin" << endl;
	return 0;
}
