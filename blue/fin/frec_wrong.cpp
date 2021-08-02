#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;

double dist(pair<float, float> x1, pair<float, float> x2)
{
    return sqrt((x1.first - x2.first)*(x1.first - x2.first) + (x1.second - x2.second)*(x1.second - x2.second));
}

// Wrong since only check the dist from the visitted point maybe not the best dist we could get for that point.
double prim(vector<pair<float, float> > &v)
{
    int n = v.size();
    vector<bool> visited(n, false);
    visited[0] = true;
    double total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!visited[i])
        {
            int minP = 0;
            double minDist = numeric_limits<double>::max();
            for (int j = 0; j < visited.size(); j++)
            {
                if (visited[j] == false) continue;
                double dis = dist(v[i], v[j]);
                if (dis < minDist)
                {
                    minP = i;
                    minDist = dis;
                }
            }
            visited[minP] = true;
            total += minDist;
        }
    }
    return total;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        float x, y;
        vector<pair<float, float> > v;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        printf("%.2f\n", prim(v));
    }
    
	return 0;
}
