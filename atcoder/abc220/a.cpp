#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int i = (a % c) == 0 ? (a / c) : (a / c + 1);
    c *= i;
    if (c < a || c > b)
        cout << -1 << endl;
    else
        cout << c << endl;
    
	return 0;
}
