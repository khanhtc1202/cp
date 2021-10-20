#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 20000

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

const int INF = 1e9;

int main()
{
    int n, t;
    cin >> n >> t;
    char line[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> line[i];
    }
    for (size_t i = 0; i < t; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            if (line[j - 1] == 'B' && line[j] == 'G')
            {
                line[j-1] = 'G';
                line[j] = 'B';
                j++;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
        cout << line[i];
    cout << endl;
	return 0;
}
