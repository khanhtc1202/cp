#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int N, B, K, sum;
        sum = 0;
        cin >> N >> B;
        while(B--) {
            int count = 1;
            cin >> K;
            for(int i = 1; i <= K; i++) {
                int x;
                cin >> x;
                count = (count * x) % N;
            }
            sum = (sum + count) % N;
        }
        cout << sum << endl;
    }
    return 0;
}