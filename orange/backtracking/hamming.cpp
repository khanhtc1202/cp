#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
string s[100];
string p;
int test[55];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        memset(test,0,sizeof(test));
        cin>>n>>m;
        for(int i=0;i<m;i++)
            test[n-1-i]=1;
        do{
            for(int i=0;i<n;i++)
                cout<<test[i];
            cout<<endl;
        }while(next_permutation(test,test+n));
        if(t>0) cout<<endl;
    }
}
