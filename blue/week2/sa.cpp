#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 1001
#define mod 1000000007

using namespace std;

int main()
{
	int i, j, k;
	int n, max_size;

	cin >> n;

	int *A = new int[n + 1];
	for (i = 1; i <= n; i++)
		cin >> A[i];

	int rear = 1, last = 0; max_size = 1;
	int mn = A[1], mx = A[1];

	for (int front = 2; front <= n; front++)
	{
		if (A[front] != A[front - 1])
		{
			if (mn == mx)
			{
				if (A[front] > mx)
					mx = A[front];
				else
					mn = A[front];

				last = front;
			}

			else
			{
				if (A[front] == mx || A[front] == mn)
				{
					last = front;

					if (front != n)
						continue;
				}

				else
				{
					if (A[front] > mx)
						mn = mx, mx = A[front];
					else
						mx = mn, mn = A[front];
				
					max_size = max(max_size, front - rear);
					rear = last; last = front;
				}
			}
		}

		if (front == n)
		{
			max_size = max(max_size, front - rear + 1);
		}
	}

	cout << max_size << endl;

	return 0;
}
