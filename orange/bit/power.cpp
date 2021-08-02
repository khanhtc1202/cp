#include <iostream>
#include <algorithm>
using namespace std;

const int NUM_BITS = 32;

bool is_power_of_2(int x)
{
    return (x != 0 && (x & (x-1)) == 0);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int total = 0;
        for (int i = 0; i < NUM_BITS; i++)
            total = total | (1 << i);
        
        bool hasSubset = false;
        for (int i = 0; i < NUM_BITS; i++)
        {
            int ans = total;
            for (int j = 0; j < n; j++)
                if (arr[j] & (1 << i)) ans &= arr[j];
            
            if (is_power_of_2(ans))
            {
                hasSubset = true;
                break;
            }
        }
        if (hasSubset) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
	return 0;
}
