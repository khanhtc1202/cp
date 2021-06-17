#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;

int main()
{
	string molecule;
	cin >> molecule;

	stack<int> st;
	int block = 0;
	int sum = 0;
	for (int i = 0; i < molecule.length(); i++)
	{
		char c = molecule.at(i);
		switch (c)
		{
		case '(':
		{
			int s = 0;
			while (!st.empty())
			{
				s += st.top();
				st.pop();
			}
			if (block > 0)
			{
				st.push(s);
			}
			else{
				sum += s;
			}
			block++;
			break;
		}
		case 'C':
			st.push(12);
			break;
		case 'H':
			st.push(1);
			break;
		case 'O':
			st.push(16);
			break;
		case ')':
		{
			int s = 0;
			while (!st.empty())
			{
				s += st.top();
				st.pop();
			}
			st.push(s);
			block--;
			break;
		}
		default:
			int curr = st.top();
			st.pop();
			st.push(curr * atoi(&c));
			break;
		}
	}
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum << endl;
	return 0;
}