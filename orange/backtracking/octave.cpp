#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
bool vis[10][10];
char mine[10][10];
set<set<pair<int,int> > > allOctave;
int m1[] = {0 , 0 , -1 , 1};
int m2[] = {-1 , 1 , 0 , 0};

void countReachOct(int n, int r, int c, int cc, set<pair<int,int> > oneOct)
{
    if(r<1||c<1)
        return ;
    else if(r>n||c>n)
        return ;
    if(mine[r][c]=='.'||vis[r][c]==1)
        return ;

    vis[r][c] = 1;
    oneOct.insert(make_pair(r,c));
    if(cc==8)
    {
        allOctave.insert(oneOct);
        vis[r][c] = 0;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int tempr = r + m1[i];
        int tempc = c + m2[i];
        countReachOct(n,tempr,tempc,cc+1,oneOct);
    }
    vis[r][c] = 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        allOctave.clear();
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                vis[i][j] = 0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin >> mine[i][j];

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                set<pair<int,int> > oneOct;
                countReachOct(n,i,j,1,oneOct);
            }
        }
        cout << allOctave.size() << endl;
    }
    return 0;
}
