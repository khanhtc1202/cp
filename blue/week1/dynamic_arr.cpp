#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    cout << "Vector size: " << v.size() << endl;
    cout << "Vector cap: " << v.capacity() << endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    // cout << "Broken: " << v[0] << endl;
    // cout << "Broken: " << v[1] << endl;
    // cout << "Broken: " << v[-1] << endl;
    vector<int>::reverse_iterator rit;
    for (rit = v.rbegin(); rit != v.rend(); rit++) {
        cout << *rit << endl;
    }
    return 0;
}
