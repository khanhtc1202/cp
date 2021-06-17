#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		stack<char> st;
		int cnt = 0, tmpCnt = 0;
		for (int j = 0; j < str.length(); j++)
		{
			char c = str.at(j);
			if (c == '<')
			{
				st.push(c);
			}
			else{
				if (st.empty())
				{
					break;
				}
				tmpCnt += 2;
				st.pop();
				if (st.empty())
				{
					cnt = tmpCnt;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}