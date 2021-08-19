#include <iostream>
using namespace std;
 
int main() {
    int n;
    while (cin >> n) {
        int b = 1;
        int cnt = 1;
        while (b % n != 0) {
            b = b * 10 + 1;
            b %= n;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}