#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int A[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	unordered_map<int, int> umap;
	int unique = 0;
	int j = 1;
	for (int i = 1; i <= n; i++)
	{
		if (umap.count(A[i]) == 0)
		{
			// umap[A[i]] = 0;
			unique++;
		}
		umap[A[i]]++;
		
		if (unique == k)
		{
			while (true)
			{
				if (umap[A[j]] > 1)
				{
					umap[A[j]]--;
					j++;
				}
				else
				{
					cout << j << " " << i << endl;
					return 0;
				}
			}
		}
	}


	cout << -1 << " " << -1 << endl;
	return 0;
}
