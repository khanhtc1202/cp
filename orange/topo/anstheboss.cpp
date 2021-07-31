#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool sortByRank(const pair<int, int>& e1, const pair<int, int>& e2) {
	if (e1.second == e2.second) {
		return e1.first < e2.first;
	}
	return e1.second < e2.second;
}

void dfs(int u, vector<vector<int> >& adj, vector<int>& visited, vector<int>& topoOrder) {
    visited[u] = 1;

    for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, adj, visited, topoOrder);
        }
    }

    topoOrder.push_back(u);
}

vector<int> topoSort(vector<vector<int> >& adj) {
    vector<int> topoOrder;
    int n = adj.size();
    vector<int> visited(n, 0);

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u, adj, visited, topoOrder);
        }
    }

    reverse(topoOrder.begin(), topoOrder.end());

    return topoOrder;
}

void solveTest(int testNumber) {
    int n, r;
    cin >> n >> r;

    vector<vector<int> > adj(n, vector<int>());
    vector<int> inDeg(n, 0);

    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        ++inDeg[u];
    }

    vector<int> topoOrder = topoSort(adj);
    vector<int> rank(n);

    for (int j = 0; j < topoOrder.size(); j++) {
		int u = topoOrder[j];
        if (inDeg[u] == 0) {
            rank[u] = 1;
        }
    	for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
            rank[v] = max(rank[v], rank[u] + 1);
        }
    }

    vector<pair<int, int> > employees;

    for (int u = 0; u < n; u++) {
        employees.push_back(make_pair(u, rank[u]));
    }

    sort(employees.begin(), employees.end(), sortByRank);
    
    cout << "Scenario #" << testNumber << ":\n";

    for (int i = 0; i < employees.size(); i++) {
        cout << employees[i].second << ' ' << employees[i].first << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int testNumber = 1; testNumber <= t; testNumber++) {
        solveTest(testNumber);
    }    

    return 0;
}