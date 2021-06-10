#include <iostream>
#include <string>
using namespace std;

char charPlusOne(char c) {
  return c == 122 ? 'a' : c + 1;
}

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  
  string R(S);
  int r = 1;
  for (int i = (S.length() - 1); i >= 0; i--) {
    if (r == 0) {
      continue;
    }
    if (S[i] == 122) {
      R[i] = 'a';
      r = 1;
    } else {
      R[i] = S[i] + 1;
      r = 0;
    }
  }
  if (!S.compare(R) || !T.compare(R)) {
    cout << "No such string" << endl;
  } else {
    cout << R << endl;
  }
  
  return 0;
}
