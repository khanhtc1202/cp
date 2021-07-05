#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
 
using namespace std;
 
typedef pair<int,int>ii;
 
bool cmp(int i,int j)
{
    return i>j;
}
 
int main() {
     
    int t,i,n,m,num;
     
    cin>>t;
     
    while (t--)
    {
        cin>>n>>m;
         
        vector<int>v;
        queue<ii>q;
         
        for (i=0;i<n;i++)
        {
            cin>>num;
            q.push(ii(num,i));
            v.push_back(num);
        }
         
        sort(v.begin(),v.end(),cmp);
         
        i=0;
        int time = 0;
         
        while (!q.empty())
        {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();
             
            if (u == v[i])
            {
                time++;
                if (w == m) break;
                i++;
            }
            else
            {
                q.push(ii(u,w));
            }
        }
        cout<< time <<endl;
    }
     
    return 0;
}