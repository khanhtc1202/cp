#include <iostream>
#include "libs.h"
using namespace std;

void binary_search(int* array, int n, int key);
void alternate_binary_search(int* array, int n, int key);
void count_value_equal(int* arr, int size, int val);
void binary_search_by_api(int* arr, int size, int val);

int main() {
  int x; cin >> x;
  int n; cin >> n;
  int array[n];
  load_array_int(array, n);

  // original way
  //  binary_search(array, n, x);
 
  // alternate way
  //  alternate_binary_search(array, n, x);

  // count value equal by api
  //  count_value_equal(array, n, x);

  // binary search by api
  binary_search_by_api(array, n, x);
  return 0;
}

void binary_search(int* array, int n, int key) {
  int a = 0,  b = n-1;
  while(a <= b){
    int k = (a+b)/2;
    if (array[k] == key) cout << "found x at " << k << "\n";
    if (array[k] > key) b = k-1;
    else a = k+1;
  }
}

void alternate_binary_search(int* array, int n, int key) {
  int k = 0;
  for (int b = n/2; b > 1; b /= 2) {
    while (k+b < n && array[k+b] <= key) k += b;
  }
  if (array[k] == key) {
    cout << "found x at " << k << "\n";
  }
}

void binary_search_by_api(int* arr, int size, int val) {
  auto k = lower_bound(arr, arr+size, val) - arr;
  if (k < size && arr[k] == val)
    cout << "found x at " << k << "\n";
}

void count_value_equal(int* arr, int size, int val) {
  auto a = lower_bound(arr, arr+size, val);
  auto b = upper_bound(arr, arr+size, val);
  cout << "number of ele which value eq " << val << " is " << b - a << "\n";
}

void alternate_count_value_equal(int* arr, int size, int val) {
  auto r = equal_range(arr, arr+size, val);
  cout << "number of ele which value eq " << val << " is " << r.second - r.first << "\n";
}
