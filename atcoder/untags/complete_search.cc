#include<iostream>
#include<vector>
#include"libs.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int b = 0; b < (1<<n); b++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
      if (b&(1<<i)) subset.push_back(i);
    }
    // cout >> subset >> "\n";
    print(subset);
  }
}
