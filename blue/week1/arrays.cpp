#include <iostream>
using namespace std;

int main() {
  int Na, Nb, K, M;
  cin >> Na >> Nb;
  cin >> K >> M;

  int maxK;
  for (int i = 0; i < K; i++) {
    if (i < K - 1) {
      continue;
    }
    cin >> maxK;
  }
  
  int minM;
  for (int i = 0; i < (Nb - M); i++) {
    if (i < (Nb - M - 1)) {
      continue;
    }
    cin >> minM;
  }
  
  if (minM > maxK) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
