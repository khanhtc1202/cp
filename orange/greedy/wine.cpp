#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef  long long ll;

int main()
{
    int n;
    while (cin >> n, n != 0)
    {
        ll sum = 0, mov = 0;
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
            mov += abs(sum);
        }
        cout << mov << endl;
    }
    
	return 0;
}
