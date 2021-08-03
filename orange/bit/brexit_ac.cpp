#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=400005;
vector<int> G[N];
int in[N],v[N];
int vis[N];
int n;
int cnt;
struct node
{ 
	int id,d;
    friend bool operator<(node a,node b)
    {
        return b.d<a.d;
    }
}x,y;
int ans,maxx;
int topo()
{
	int sum=n;
    priority_queue<node>Q;
    for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
	    {
	    	x.id=i;
	    	x.d=v[i];
	    	Q.push(x);
	    	vis[i]=1;
	    }
	}
    int t=0;
	ans=-1e9;
	 while(!Q.empty())
	{
	    y=Q.top();
		Q.pop();
	
		sum--;
	    ans=max(ans,v[y.id]+sum);
	    for(int i=0;i<G[y.id].size();i++)
		{
		    in[G[y.id][i]]--;
		    if(vis[G[y.id][i]]==0&&in[G[y.id][i]]==0)
			{
				vis[G[y.id][i]]=1;
				x.id=G[y.id][i];
				x.d=v[G[y.id][i]];
				Q.push(x);
			}	
		}
	}
}
int main()
{
    int m;
    while(scanf("%d",&n)!=-1)
    {
    	memset(in,0,sizeof(in));
    	memset(vis,0,sizeof(vis));
    	for(int i=0;i<=n;i++)
    		G[i].clear();
		int m;
		maxx=-1e9;
        for(int i = 1; i <= n; i++)
        {
			scanf("%d",&v[i]);
		    scanf("%d",&m);
		    while(m--)
			{
				int u;
				scanf("%d",&u);
				G[i].push_back(u);
				in[u]++;
			} 
        }
        
       
        topo();
       	printf("%d",ans);
    }
    return 0;
}