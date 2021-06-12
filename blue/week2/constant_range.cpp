#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  int max_size = 1;
  int rear = 0, last = 0;
  int m = A[0], M = A[0];
  for (int front = 1; front < N; front++) {
	if (A[front] != A[front-1]) {
      if (M == m) {
        M = max(M, A[front]);
        m = min(m, A[front]);
        last = front;
      } else {
        if (A[front] == M || A[front] == m) {
          last = front;
          if (front != N-1) continue;
        } else {
          if (A[front] > M) {
            m = M;
            M = A[front];
          } else {
            M = m;
            m = A[front];
          }
          max_size = max(max_size, front - rear);
          rear = last;
          last = front;
        }
      }
    }
    if (A[front] == N-1) {
      max_size = max(max_size, front - rear + 1);
    }
    // m = min(m, A[front]);
    // M = max(M, A[front]);
    // while (M - m > 1) {
    //   rear++;
    //   m = min(m + 1, A[rear]);
	//     M = max(M - 1, A[rear]);
    // }
    // max_size = max(max_size, front - rear + 1);
  }
  cout << max_size << endl;
  return 0;
}
