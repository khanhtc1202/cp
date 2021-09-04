
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int nTest;
    cin >> nTest;

    for(int iTest = 1; iTest <= nTest; ++iTest) {
        int na, nb, nc;
        string a, b, c;

        cin >> na >> nb >> nc;
        cin >> a >> b >> c;

        vector<vector<vector<int>>> L(na + 1, vector<vector<int>>(nb + 1, vector<int>(nc + 1, 0)));

        for(int i = 0; i <= na; ++i) {
            for(int j = 0; j <= nb; ++j) {
                for(int k = 0; k <= nc; ++k) {
                    if (i == 0 || j == 0 || k == 0)
                        L[i][j][k] = 0;
                    else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                        L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
                    else
                        L[i][j][k] = max(L[i - 1][j][k], max(L[i][j - 1][k], L[i][j][k - 1]));
                }
            }
        }

        cout << L[na][nb][nc] << endl;
    }

	return 0;
}