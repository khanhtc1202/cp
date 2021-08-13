#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> re(n);
    int flip_point;
    for (int i = 0; i < n; i++)
    {
        cin >> re[i];
        if (k > 0 && re[i] < 0)
        {
            re[i] = -re[i];
            k--;
            flip_point = i;
        }
    }
    if (k % 2 == 1)
    {
        if (flip_point != (n-1) && re[flip_point] > re[flip_point+1])
        {
            re[flip_point + 1] = re[flip_point + 1] * (-1);
        }
        else
        {
            re[flip_point] = re[flip_point] * (-1);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += re[i];
    cout << sum << endl;
	return 0;
}
