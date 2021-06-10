#include <iostream>
using namespace std;

int main() {
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  int A[N], B[M];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  
  int j = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    while (j < M) {
      if ((A[i] - X <= B[j]) && (B[j] <= A[i] + Y)) {
        //   cout << B[j] << endl;
        i++;
        cnt++;
      }
      j++;
    }
  }
  cout << cnt << endl;
  return 0;
}