#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

void buildTree(vector<int>& a, vector<int>& segtree, int left, int right, int index)
{
    if (left == right)
    {
        segtree[index] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(a, segtree, left, mid, 2*index+1);
    buildTree(a, segtree, mid+1, right, 2*index+2);
    segtree[index] = segtree[2*index+1] + segtree[2*index+2];
}

int sumRange(vector<int>& segtree, int left, int right, int from, int to, int index)
{
    if (from <= left && to >= right)
        return segtree[index];
    if (from > right || to < left)
        return 0;
    int mid = (left + right) / 2;
    return sumRange(segtree, left, mid, from, to, 2*index+1) +
            sumRange(segtree, mid+1, right, from, to, 2*index+2);
}

void updateQuery(vector<int>& segtree, vector<int>& a, int left, int right, int index, int pos, int value)
{
    if (pos < left || right < pos)
        return;
    if (left == right)
    {
        a[pos] = value;
        segtree[index] = value;
        return;
    }
    int mid = (left+right) / 2;
    if (pos <= mid)
        updateQuery(segtree, a, left, mid, 2*index+1, pos, value);
    else
        updateQuery(segtree, a, mid+1, right, 2*index+2, pos, value);
    segtree[index] = segtree[2*index+1] + segtree[2*index+2];
}

int main()
{
    int t; cin >> t;
    int cs = 1;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int h = (int)ceil(log2(n));
        int sizeTree = 2 * (int)pow(2, h) - 1;
        vector<int> segtree(sizeTree);
        buildTree(a, segtree, 0, n-1, 0);
        cout << "Case " << cs << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            int qt; cin >> qt;
            int p, v, l, r;
            switch (qt)
            {
            case 1:
                cin >> p;
                cout << a[p] << endl;
                updateQuery(segtree, a, 0, n-1, 0, p, 0);
                break;
            case 2:
                cin >> p >> v;
                updateQuery(segtree, a, 0, n-1, 0, p, a[p]+v);
                break;
            default:
                cin >> l >> r;
                cout << sumRange(segtree, 0, n-1, l, r, 0) << endl;
                break;
            }
        }
        cs++;
    }
    
	return 0;
}
