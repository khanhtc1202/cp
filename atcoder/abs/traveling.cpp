#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
  int n; cin >> n;
  int t=0, x=0, y=0;
  while (n>0) {
    int t0=t, x0=x, y0=y;
    int t1, x1, y1;
    cin >> t1 >> x1 >> y1;
    int dis_t = t1 - t0, dis_s = abs(x1-x0)+abs(y1-y0);
    if ((dis_t < dis_s) || (dis_t - dis_s)%2!=0)
    {cout << "No"; return 0;}
    n--;
  }
  cout << "Yes";
}

