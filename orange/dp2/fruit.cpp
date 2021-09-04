#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) {
        int n = a.length(), m = b.length();
        a = '#' + a;
        b = '#' + b;
    
        vector<vector<int> > lcs(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        string res;
        int i = n, j = m;
        while (i || j) {
            if (i == 0) {
                res += b[j--];
            }
            else if (j == 0) {
                res += a[i--];
            }
            else {
                if (a[i] == b[j]) {
                    res += a[i--];
                    j--;
                }
                else if (lcs[i][j] == lcs[i - 1][j]) {
                    res += a[i--];
                }
                else {
                    res += b[j--];
                }
            }
        }
    
        cout << string(res.rbegin(), res.rend()) << endl;
    }
}
