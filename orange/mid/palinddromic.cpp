#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string c = "abcdefghij";

bool isPalindrome(string str)
{
	int low = 0;
	int high = str.length() - 1;
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

string build(string n)
{
	int cnt;
	vector<char> rune;
	for (int i = 0; i < n.length(); i++)
	{
		int id = n[i] - '0';
		rune.push_back(c[id]);
		cnt += id;
	}
	string s = "";
	for (int i = 1; i <= cnt; i++)
		s += rune[i%rune.size()];
	return s;
}

int main()
{
	int t; cin >> t;
	string n;
	while (t--)
	{
		cin >> n;
		if (isPalindrome(build(n)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
