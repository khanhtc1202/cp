#include<iostream>
#include<cmath>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)

void load_array_int(int* array, int size) {
  FOR(i, 0, size) std::cin >> array[i];
}

int main() {
  int size; cin >> size;
  int arr[size], x=0, res=0;
  load_array_int(arr, size);
  FOR(i, 0, size) x += arr[i];
  x /= size;
  FOR(i, 0, size) res += pow(arr[i] - x - 1, 2);
  cout << "cost = " << res << "\n";
}
