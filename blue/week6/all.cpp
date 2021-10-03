#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 101

int R, C;
string ALLIZZWELL = "ALLIZZWELL";
int dr[] = {0,0,1,1,1,-1,-1,-1};
int dc[] = {1,-1,0,1,-1,0,1,-1};
bool visited[MAX][MAX];
char graph[MAX][MAX];

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < R && c < C;
}

bool found;
void DFS(int sr, int sc, int i)
{
    if (i == ALLIZZWELL.size())
    {
        found = true;
        return;
    }

    for(size_t j = 0; j < 8; j++)
    {
        int r = sr + dr[j];
        int c = sc + dc[j];
        if (isValid(r,c) && graph[r][c] == ALLIZZWELL[i] && !visited[r][c])
        {
            visited[r][c] = true;
            DFS(r, c, i+1);
            visited[r][c] = false;
        }
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        cin >> R >> C;
        for (size_t i = 0; i < R; i++)
        {
            for (size_t j = 0; j < C; j++)
            {
                cin >> graph[i][j];
                visited[i][j] = false;
            }
        }
        found = false;
        for (size_t i = 0; i < R; i++)
        {
            for (size_t j = 0; j < C; j++)
            {
                if (graph[i][j] == ALLIZZWELL[0] && !found)
                {
                    DFS(i, j, 1);
                }
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    
	return 0;
}
