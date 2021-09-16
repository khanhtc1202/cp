#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;

void KMPpreprocess(const string& P, vector<int>& prefix)
{
    prefix[0] = 0;
    int m = P.length();
    int i = 1, j = 0;
    while (i < m)
    {
        if (P[i] == P[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }
}

int KMPsearch(const string& T, const string& P, const vector<int>& prefix)
{
    int n = T.length();
    int m = P.length();
    int i = 0, j = 0;
    int cnt;
    while (i < n)
    {
        if (T[i] == P[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cnt++;
            j = prefix[j - 1];
        }
        else if (i < n && T[i] != P[j])
        {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
    }
    return cnt;
}

int main()
{
    int t; scanf("%d\n", &t);
    int cnt = 1;
    while (t--)
    {
        string T, P;
        getline(cin, T);
        T.erase(std::remove_if(T.begin(), T.end(), ::isspace), T.end());
        getline(cin, P);
        vector<int> prefix(P.length());
        KMPpreprocess(P, prefix);
        cout << "Case " << cnt << ": " << KMPsearch(T, P, prefix) << endl;
        cnt++;
    }
    
	return 0;
}
