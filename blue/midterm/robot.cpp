#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 1000
pair<int, int> src;
pair<int, int> des;

const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dis[N][N];
int R, C;
int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}

bool in_bound(int r, int c)
{
    return r >= 0 && c >= 0 && r < R && c < C;
}

int BFS()
{
    queue<pair<int, int> > Q;
    Q.push(src);
    dis[src.first][src.second] = 1;

    while (!Q.empty())
    {
        pair<int, int> now = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int r = now.first + dir[i][0], c = now.second + dir[i][1];
            if (in_bound(r, c) && dis[r][c] == 0)
            {
                dis[r][c] = dis[now.first][now.second] + 1;

                pair<int, int> next(r, c);
                if (next == des)
                    return dis[des.first][des.second] - 1;

                Q.push(next);
            }
        }
    }

    return -1;
}

void resetDis()
{
	for (int i = 0; i < R; ++i)
		memset(dis[i], 0, sizeof dis[i]);
}

int main()
{
    while (scanf("%d%d", &R, &C) && R)
    {
        int n, r, c, x;
		cin >> n;
        getchar();
        for (int i = 0; i < n; ++i)
        {
            r = input();
            x = input();
            for (int j = 0; j < x; ++j)
            {
                c = input();
                dis[r][c] = -1;
            }
        }

		cin >> src.first >> src.second;
		cin >> des.first >> des.second;

		cout << BFS() << endl;
		resetDis();
    }

    return 0;
}
