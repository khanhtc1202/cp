#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define LL long long

int main()
{
    LL n,ans=0;
    cin>>n;
	for(LL x=1;x<=n;x=x*10ll+1)
	{
		LL t=x,o=0;
		while(t<=n)
		{
			ans+=(min(n,t+o)-t+1);
			t *= 10ll, o=o*10ll+9ll;
		}
	}
	cout<<ans<<endl;
	return 0;
}
