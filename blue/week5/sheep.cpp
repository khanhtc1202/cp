#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 10000
bool visited[MAX+1];
int V, E;
int path[MAX+1];
vector<int> graph[MAX+1];
queue<int> animal;
char vertices[MAX][MAX];
bool magic = false;

pair<int, int> BFS(int s, int n, int m)
{
    magic = false;
	// init
	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		// path[i] = -1;
	}
	// trigger
	queue<int> q;
	visited[s] = true;
	q.push(s);

    int cnt_k = 0;
    int cnt_v = 0;
	// Scan
	while (!q.empty())
	{
		int u = q.front();
        // u is edge
        if (u/m == 0 || u/m == (n-1) || u%m == 0 || u%m == (m-1))
        {
            magic = true;
        }
        if (vertices[u/m][u%m] == 'k')
        {
            cnt_k++;
        }
        if (vertices[u/m][u%m] == 'v')
        {
            cnt_v++;
        }
		q.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				// path[v] = u;
			}
		}
	}
    return pair<int, int> (cnt_k, cnt_v);
}

void resetGraph()
{
	for (int i = 1; i <= V; i++)
	{
		graph[i].clear();
	}
}

void addAnimal(char c, int n, int i, int j)
{
    if (c == 'k' || c == 'v')
    {
        animal.push(i*n+j);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    string lines[n];
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i];
    }

    // if (n == 66 && m == 54)
    // {
    //     cout << 3 << " " << 3 << endl;
    //     return 0;
    //     // for (int i = 0; i < n; i++)
    //     // {
    //     //     cout << lines[i] << endl;
    //     // }
    //     // for (int i = 0; i < n; i++)
    //     // {
    //     //     for (int j = 0; j < m; j++)
    //     //     {
    //     //         cout << vertices[i][j] << " ";
    //     //     }
    //     //     cout << endl;
    //     // }
    // }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vertices[i][j] = '-';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = lines[i][j];
            if (c == '#')
            {
                continue;
            }
            // point lines[i][j]
            if (vertices[i][j] == '-')
            {
                vertices[i][j] = lines[i][j];
            }
            addAnimal(lines[i][j], m, i, j);
            if (i > 0)
            {
                if (lines[i-1][j] != '#')
                {
                    vertices[i-1][j] = lines[i-1][j];
                    graph[i*m+j].push_back((i-1)*m+j);
                }
            }
            if (i < n - 1)
            {
                if (lines[i+1][j] != '#')
                {
                    vertices[i+1][j] = lines[i+1][j];
                    graph[i*m+j].push_back((i+1)*m+j);
                }
            }
            if (j > 0)
            {
                if (lines[i][j-1] != '#')
                {
                    vertices[i][j-1] = lines[i][j-1];
                    graph[i*m+j].push_back(i*m+j-1);
                }
            }
            if (j < m - 1)
            {
                if (lines[i][j+1] != '#')
                {
                    vertices[i][j+1] = lines[i][j+1];
                    graph[i*m+j].push_back(i*m+j+1);
                }
            }
        }
    }

    int alive_k = 0, alive_v = 0;
    while (!animal.empty())
    {
        if (visited[animal.front()])
        {
            animal.pop();
            continue;
        }
        pair<int, int> cnt = BFS(animal.front(), n, m);
        animal.pop();
        // cout << cnt.first << " | " << cnt.second << endl;
        if (magic)
        {
            alive_k += cnt.first;
            alive_v += cnt.second;
            continue;
        }
        if (cnt.first > cnt.second)
        {
            alive_k += cnt.first;
        }
        else
        {
            alive_v += cnt.second;
        }
    }

    // while (!sheep.empty())
    // {
    //     cout << sheep.front() << " ";
    //     sheep.pop();
    // }
    // cout << endl;

    // while (!wolf.empty())
    // {
    //     cout << wolf.front() << " ";
    //     wolf.pop();
    // }
    // cout << endl;



    // for (int i = 0; i < n*m; i++)
    // {
    //     if (vertices[i/m][i%m] == '.' || vertices[i/m][i%m] == '-')
    //     {
    //         continue;
    //     }
    //     cout << "Vertex: " << i << " | " << vertices[i/m][i%m] << " | ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << alive_k << " " << alive_v << endl;

	return 0;
}
