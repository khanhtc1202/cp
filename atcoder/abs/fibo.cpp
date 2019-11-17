#include<iostream>
#include<cmath>
using namespace std;

double fibo(int n) {
  return (pow(1+sqrt(5), n)-pow(1-sqrt(5), n))/(pow(2, n)*sqrt(5));
}

int main() {
  int n; cin >> n;
  cout << "Fibo " << n << "-th is " << fibo(n) << "\n";
  return 0;
}

