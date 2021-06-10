#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  string str;
  cin >> str;
  
  int sum = 0;
  char prevChar = 'a';
  for (int i = 0; i < str.length(); i++) {
    int jump = abs(str[i] - prevChar);
    int realJump = jump > 13 ? (26 - jump) : jump;
    sum += realJump;
    prevChar = str[i];
  }
  cout << sum << endl;
  
  return 0;
}
