#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> digits(10, 0);
    int k;
    cin >> k;
    string num;
    cin >> num;
    int sum = 0;
    for (int i = 0; i < num.length(); i++)
    {
        digits[num[i] - '0']++;
        sum += num[i] - '0';
    }
    int cnt = 0;
    int digit_idx = 0;
    while (sum < k && digit_idx < 11)
    {
        if (digits[digit_idx] == 0)
        {
            digit_idx++;
            continue;
        }
        digits[digit_idx]--;
        sum += 9 - digit_idx;
        cnt++;
    }
    cout << cnt << endl;
	return 0;
}
