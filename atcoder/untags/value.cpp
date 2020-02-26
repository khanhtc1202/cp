#include<iostream>
using namespace std;

int main() {
	float b = 1.0f;
	int i = static_cast<int>(b);
	int& j = reinterpret_cast<int&>(b);
	cout<<i<<endl;
	cout<<j<<endl;
}
