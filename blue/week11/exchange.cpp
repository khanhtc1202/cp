#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n; float k;
    cin >> n >> k;
    float sum = 0;
    vector<float> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    float avg = sum / n;

    float sum_lf = 0, sum_rg = 0;
    float cnt_lf = 0, cnt_rg = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < avg)
        {
            cnt_lf++;
            sum_lf += arr[i];
        }
        else
        {
            cnt_rg++;
            sum_rg += arr[i];
        }
    }

    float x = (cnt_lf * sum_rg - cnt_rg * sum_lf) / (cnt_rg * (100 - k)/100 + cnt_lf);
    // Need to use below output as new avg and keep update until lf always lower than avg
    printf("%.9f\n", (sum_rg - x)/(cnt_rg));

	return 0;
}
