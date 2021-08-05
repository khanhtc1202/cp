#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printAns(vector<int>& a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
}

void allCombination(vector<int> &a, vector<int> &src, int left, int k)
{
    if (k == 0)
    {
        printAns(a);
        cout << endl;
        return;
    }
    for (int i = left; i < src.size(); i++)
    {
        a.push_back(src[i]);
        allCombination(a, src, i+1, k-1);
        a.pop_back();
    }
}

int main()
{
    int n;
    int k = 6;
    while (cin >> n, n > 0)
    {
        vector<int> a;
        vector<int> src(n);
        for (int i = 0; i < n; i++)
        {
            cin >> src[i];
        }
        allCombination(a, src, 0, k);
    }
    cin.get();
    
	return 0;
}
