#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void print(T const &input) {
  copy(input.cbegin(), input.cend(), ostream_iterator<typename T::value_type>(cout, " "));
}

bool string_compare(string a, string b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

int main() {
  vector<int> v = {2, 3, 1, 6, 5, 1};
  print(v);
  cout << "\n";
  sort(v.begin(), v.end());
  print(v);
  cout << "\n";

  // sort vector of string
  vector<string> vs = {"asd", "a", "af", ""};
  sort(vs.begin(), vs.end(), string_compare);
  print(vs);
  cout << "\n";
}
