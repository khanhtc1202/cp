#include<iostream>
using namespace std; // note that using namespace std makes your code slower :))

int main() {
  int num;
  int value;
  int flag = 1;
  cin >> num >> value;
  
  for (int i=0; i<num+1; i++) {
    for (int j=0; j<num+1-i; j++) {
      int sum = i*1000 + j*5000 + (num-i-j)*10000;
      if (sum == value) {
        cout << (num-i-j) << " " << j << " " << i << endl;
        flag = 0;
        break;
      }
    }
    if (!flag) {
      break;
    }
  }
  if (flag) {
    cout << "-1 -1 -1" << endl;
  }
}

