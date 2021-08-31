#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string str, patt;
        cin >> str;
        cin >> patt;
        unordered_map<char, bool> memo;
        for (int i = 0; i < str.length(); i++)
        {
            if (memo.find(str[i]) != memo.end())
                continue;
            for (int j = 0; j < patt.length(); j++)
            {
                if (patt[j] == str[i]) {
                    cout << str[i] << endl;
                    goto L;
                }
            }
            memo.insert(make_pair(str[i], true));
        }
        cout << "No character present" << endl;
L:
        continue;
    }
    
	return 0;
}
