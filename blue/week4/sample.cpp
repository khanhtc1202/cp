#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	// Stack
	stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	// Queue
	queue<int> q;
	q.push(1);
	q.push(2);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();

	return 0;
}