#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, time;
  cin >> n >> time;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  int cnt = 0, start = 0, read = 0;
  for (int end = 0; end < n; end++) {
    read += v[end];
    while (read > time) {
      read -= v[start];
      start++;
    }
    cnt = max(cnt, end - start + 1);
  }
  cout << cnt << endl;
  return 0;
}