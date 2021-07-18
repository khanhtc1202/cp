#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void print_v(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> s(150, 0);
    vector<int> t(150, 0);
    string ss, st;
    getline(cin, ss);
    getline(cin, st);
    for (int i = 0; i < ss.length(); i++)
    {
        s[int(ss[i])] += 1;
    }
    for (int i = 0; i < st.length(); i++)
    {
        t[int(st[i])] += 1;
    }

    int y_cnt = 0, w_cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 0) continue;
        int matched = min(s[i], t[i]);
        s[i] -= matched;
        t[i] -= matched;
        y_cnt += matched;
    }
    // print_v(s);
    // print_v(t);
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] == 0 && t[i] == 0) || i >= 91) continue;
        int w_matched = min(s[i] + s[i+32], t[i] + t[i+32]);
        w_cnt += w_matched;
    }

    cout << y_cnt << " " << w_cnt << endl;
	return 0;
}
