#include<iostream>
using namespace std;

void binary_search(int* array, int n, int key);
void alternate_binary_search(int* array, int n, int key);

int main() {
  int x; cin >> x;
  int array[] = {1,2,3,4,5,6,7};
  int n = sizeof(array)/sizeof(array[0]);

  // original way
//  binary_search(array, n, x);
 
  // alternate way
  alternate_binary_search(array, n, x);

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
