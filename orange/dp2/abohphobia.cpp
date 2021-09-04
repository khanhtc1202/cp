#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.length();
        vector<vector<int> > max_palin_length(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            max_palin_length[i][i] = 1;
        }

        if (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == s[i + 1]) {
                    max_palin_length[i][i + 1] = 2;
                }
                else {
                    max_palin_length[i][i + 1] = 1;
                }
            }
        }

        for (int length = 3; length <= n; length++) {
            for (int start = 0; start < n - length + 1; start++) {
                int end = start + length - 1;

                if (s[start] == s[end]) {
                    max_palin_length[start][end] = max_palin_length[start + 1][end - 1] + 2;
                }
                else {
                    max_palin_length[start][end] = max(max_palin_length[start + 1][end], max_palin_length[start][end - 1]);
                }
            }
        }

        int ans = n - max_palin_length[0][n - 1];
        cout << ans << endl;
    }

    return 0;
}
