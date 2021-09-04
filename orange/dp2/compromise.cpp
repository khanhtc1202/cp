#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long long int
#define ULL unsigned LL
 
const int inf=1<<30;
const LL INF=1e18;
const int MOD=1e9+7;
 
 
vector<string> LCS(string st1[], string st2[], int l1, int l2)
{
    int dp[l1+2][l2+2];
 
    for(int i=0; i<=l1; i++)
    {
        for(int j=0; j<=l2; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(st1[i-1]==st2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
 
    vector<string> sv;
 
    int n, m;
    n=l1, m=l2;
    while(n>0 && m>0)
    {
        if(st1[n-1]==st2[m-1])
        {
            sv.push_back(st1[n-1]);
            n--;
            m--;
        }
        else if(dp[n-1][m]>dp[n][m-1])
            n--;
        else m--;
    }
    return sv;
}
 
int main()
{
    while(1)
    {
        string st1[105], st2[105], s;
 
        cin>>s;
 
        if(s.length()==0)break;
        int l1, l2;
 
        l1=l2=0;
        st1[l1++]=s;
 
        while(cin>>s && s!="#") st1[l1++]=s;
 
        while(cin>>s && s!="#") st2[l2++]=s;
 
        vector<string> res=LCS(st1, st2, l1, l2);
 
        int len=res.size()-1;
        cout<<res[len];
        for(int i=len-1; i>=0; i--)
            cout<<" "<<res[i];
        cout<<'\n';
    }
    return 0;
}
