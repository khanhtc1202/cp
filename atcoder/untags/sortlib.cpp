#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> const &input) {
  copy(input.begin(), input.end(), ostream_iterator<int>(cout, " "));
}

int main() {
  vector<int> v = {2, 3, 1, 6, 5, 1};
  print(v);
  cout << "\n";
  sort(v.begin(), v.end());
  print(v);
  cout << "\n";
}
