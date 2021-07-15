#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;

float func(float x)
{
    return p * pow(M_E, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

int main()
{
    while (cin >> p >> q >> r >> s >> t >> u) {
        float lf = 0, rg = 1;
        if (func(lf) * func(rg) > 0)
        {
            cout << "No solution" << endl;
            continue;
        }
        while (true)
        {
            float x = (lf + rg) * 0.5;
            float mid = func(x);
            if (abs(mid) < 1e-4)
            {
                printf("%.4f\n", x);
                break;
            }
            if (mid * func(lf) > 0)
            {
                lf = x;
                continue;
            }
            if (mid * func(rg) > 0)
            {
                rg = x;
                continue;
            }
        }
    } 
	return 0;
}
