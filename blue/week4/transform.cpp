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
		stack<char> op;
		string out = "";
		for (int j = 0; j < str.length(); j++)
		{
			char c = str.at(j);
			switch(c)
			{
			    case '(':
					break;
				case '+':
					op.push(c);
					break;
				case '-':
					op.push(c);
					break;
				case '*':
					op.push(c);
					break;
				case '/':
					op.push(c);
					break;
				case '^':
					op.push(c);
					break;
				case ')':
					out += op.top();
					op.pop();
					break;
				default:
					out += c;
					break;
		    }
		}
		cout << out << endl;
	}

	return 0;
}