#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int arr1[8]={-2,-2,-1,-1,1,1,2,2};
int arr2[8]={-1,1,-2,2,-2,2,-1,1};
pair<int,int> arr[10];
int ans=0;
void knightMove(int x,int y,bool visited[10][10],int n,int dpth)
{
	int a,b,k=0;
	visited[x][y]=1;

	for(int i=0;i<8;i++)
	{
		a=x+arr1[i];
		b=y+arr2[i];
		if(a>=0 && a<n && b>=arr[a].first && b<=arr[a].second && !visited[a][b])
		{
			knightMove(a,b,visited,n,dpth+1);
			k=1;
		}
	}
	if(k==0)
        ans=max(ans,dpth);	
    visited[x][y]=0;    
	
}

int main()
{
	bool visited[10][10];

	int n,skip,col,k=1;
	
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		memset(visited,0,sizeof(visited));
		int cnt=0;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>skip>>col;
			cnt+=col;
			arr[i].first=skip;
			arr[i].second=col+skip-1;
		}
		int x=0;
		int y=arr[0].first;
		knightMove(x,y,visited,n,1);

    cout<<"Case "<<k++<<", "<<cnt-ans<<" squares can not be reached."<<endl;
		
	}
}
