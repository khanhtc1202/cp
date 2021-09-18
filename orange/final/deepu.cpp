#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
        cin >> arr[i];
    int m; cin >> m;
    int x;
    for (size_t i = 0; i < m; i++)
    {
        cin >> x;
        for (size_t j = 0; j < n; j++)
            arr[j] = arr[j] > x ? arr[j] - 1 : arr[j];
    }
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
	return 0;
}
